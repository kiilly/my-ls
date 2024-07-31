#ifndef MY_LS_H
#define MY_LS_H

#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define MAX_ENTRIES 1024 

struct file_entry {
    char *name;
    time_t mod_time;
};

extern struct file_entry entries[MAX_ENTRIES];

void reverse_array(struct file_entry array[], int count);
char *get_file_permissions(mode_t mode);
void print_file_details(const char *path, const char *name);
int compare_files(const void *a, const void *b);
void print_files(const char *path, int one_per_line, int reverse, int list_directories, int long_listing, int directory_itself, int recursive, int sort_by_time, int show_all, int almost_all, int follow_links);

#endif