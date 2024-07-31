#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "my_ls.h"

#define MAX_ENTRIES 1024 

struct file_entry entries[MAX_ENTRIES];


char *get_file_permissions(mode_t mode) {
    static char permissions[11];

    permissions[0] = S_ISDIR(mode) ? 'd' : '-';
    permissions[1] = mode & S_IRUSR ? 'r' : '-';
    permissions[2] = mode & S_IWUSR ? 'w' : '-';
    permissions[3] = mode & S_IXUSR ? 'x' : '-';
    permissions[4] = mode & S_IRGRP ? 'r' : '-';
    permissions[5] = mode & S_IWGRP ? 'w' : '-';
    permissions[6] = mode & S_IXGRP ? 'x' : '-';
    permissions[7] = mode & S_IROTH ? 'r' : '-';
    permissions[8] = mode & S_IWOTH ? 'w' : '-';
    permissions[9] = mode & S_IXOTH ? 'x' : '-';
    permissions[10] = '\0';

    return permissions;
}

int compare_files(const void *a, const void *b) {
    struct file_entry *file_a = (struct file_entry *)a;
    struct file_entry *file_b = (struct file_entry *)b;
    return difftime(file_b->mod_time, file_a->mod_time);
}



int main(int argc, char *argv[]) {
    int one_per_line = 0;
    int reverse = 0;
    int list_directories = 0;
    int long_listing = 0;
    int directory_itself = 0;
    int recursive = 0;
    int sort_by_time = 0;
    int show_all = 0;
    int almost_all = 0;
    int follow_links = 0;
    const char *path = ".";

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-1") == 0) {
            one_per_line = 1;
        } else if (strcmp(argv[i], "-r") == 0) {
            reverse = 1;
        } else if (strcmp(argv[i], "-d") == 0) {
            directory_itself = 1;
        } 
        else if (strcmp(argv[i], "-R") == 0) {
            recursive = 1;
        }else if (strcmp(argv[i], "-l") == 0) {
            long_listing = 1;
        } 
        else if (strcmp(argv[i], "-t") == 0) {
            sort_by_time = 1;
        }
        else if (strcmp(argv[i], "-a") == 0) {
            show_all = 1;
        }
        else if (strcmp(argv[i], "-A") == 0) {
            almost_all = 1;
        }
        else if (strcmp(argv[i], "-L") == 0) {
            follow_links = 1;
        }
        else {
            path = argv[i];
        }
    }

    if (!path) {
        path = ".";
    }

    print_files(path, one_per_line, reverse, list_directories, long_listing, directory_itself, recursive, sort_by_time, show_all, almost_all, follow_links);

    return 0;
}