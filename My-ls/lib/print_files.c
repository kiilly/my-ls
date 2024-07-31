#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../my_ls.h"

void print_files(const char *path, int one_per_line, int reverse, int list_directories, int long_listing, int directory_itself, int recursive, int sort_by_time, int show_all, int almost_all, int follow_links) {

    static int first_run = 1;

    if (first_run && recursive) {
        printf(".:\n");
        first_run = 0;
    } else if (recursive) {
        printf("\n%s:\n", path);
    }

    if (directory_itself) {
        if (long_listing) {
            print_file_details(path, "");
        } else {
            printf("%s\n", path);
        }
        return;
    }

    DIR *dir;
    struct dirent *entry;
    int count = 0;
    int total = 0;
    int is_directory[MAX_ENTRIES];


    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL && count < MAX_ENTRIES) {
        if ((!show_all && !almost_all && entry->d_name[0] == '.') || 
            (almost_all && (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)))
            continue;

        if (list_directories && entry->d_type != DT_DIR)
            continue;

        struct stat st;
        char fullpath[1024];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);
        if ((follow_links ? lstat : stat)(fullpath, &st) == 0) {
            total += st.st_blocks;
            entries[count].name = strdup(entry->d_name);
            entries[count].mod_time = st.st_mtime;
            is_directory[count] = (entry->d_type == DT_DIR);
            count++;
        }
    }

    if (long_listing) {
        printf("total %d\n", total / 2);
    }

    if (reverse) {
        reverse_array(entries, count);
    }

    if (sort_by_time) {
    qsort(entries, count, sizeof(struct file_entry), compare_files);
}
    

    for (int i = 0; i < count; i++) {
    if (entries[i].name != NULL) {
        if (long_listing)
            print_file_details(path, entries[i].name);
        else if (one_per_line)
            printf("%s\n", entries[i].name);
        else
            printf("%s\t", entries[i].name);
    }
}

    printf("\n");
    closedir(dir);

    for (int i = 0; i < count; i++) {
    if (entries[i].name != NULL && entries[i].name[0] != '.' && is_directory[i]) {
        char subpath[1024];
        snprintf(subpath, sizeof(subpath), "%s/%s", path, entries[i].name);
        print_files(subpath, one_per_line, reverse, list_directories, long_listing, directory_itself, recursive, sort_by_time, show_all,almost_all,follow_links);
    }

    if(entries[i].name != NULL) {
        free(entries[i].name);
        entries[i].name = NULL;
    }
}
    
}