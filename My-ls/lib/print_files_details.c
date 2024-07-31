#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../my_ls.h"

void print_file_details(const char *path, const char *name) {
    struct stat st;
    char full_path[1024];

    snprintf(full_path, sizeof(full_path), "%s/%s", path, name);

    if (stat(full_path, &st) == -1) {
        perror("stat");
        return;
    }

    struct passwd *pw = getpwuid(st.st_uid);
    struct group  *gr = getgrgid(st.st_gid);
    char mod_time[20];
    strftime(mod_time, 20, "%b %d %H:%M", localtime(&(st.st_mtime)));

    printf("%s %ld %s %s %lld %s %s\n",
       get_file_permissions(st.st_mode),
       (long)st.st_nlink,
       pw->pw_name,
       gr->gr_name,
       (long long)st.st_size,
       mod_time,
       name);
}