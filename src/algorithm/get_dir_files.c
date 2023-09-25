/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** get_dir_files
*/

#include "my.h"

int get_dir_files_bis(char *str)
{
    int dir_files = 0;
    DIR *directory;
    struct dirent *entry;

    directory = opendir(str);
    if (directory == NULL) {
        return -1;
    } while ((entry = readdir(directory)) != NULL) {
        if (entry->d_type == DT_REG) {
            dir_files++;
        } if (entry->d_type == DT_DIR) {
            dir_files++;
        }
    } if (closedir(directory) == -1)
        return -1;
    return dir_files;
}

char **get_dir_files(char *str, int dir_files)
{
    char **dir_files_tab = malloc(sizeof(char*) * dir_files + 1);
    DIR *directory = opendir(str);
    struct dirent *entry;
    int count_dir_files_tab = 0;
    if (directory == NULL) {
        handle_permissions_file(str);
        return NULL;
    } while ((entry = readdir(directory)) != NULL) {
        if (entry->d_type == DT_REG) {
            dir_files_tab[count_dir_files_tab] = my_strdup(entry->d_name);
            count_dir_files_tab++;
        } if (entry->d_type == DT_DIR) {
            dir_files_tab[count_dir_files_tab] = my_strdup(entry->d_name);
            count_dir_files_tab++;
        }
    } if (closedir(directory) == -1) {
        return NULL;
    } dir_files_tab[count_dir_files_tab] = NULL;
    return dir_files_tab;
}

void handle_all_dir_files(char *str, struct_t *data)
{
    char **tab;

    int dir_files = get_dir_files_bis(str);
    tab = get_dir_files(str, dir_files);
    if (tab == NULL) {
        return;
    }
    handle_a_r(data, &tab);
    sort_time(data, tab, str);
    handle_permissions(tab, str);
}

void handle_all_dir_files_rec(char *str, struct_t *data)
{
    char **tab;

    int dir_files = get_dir_files_bis(str);
    tab = get_dir_files(str, dir_files);
    if (tab == NULL)
        return;
    handle_a_r(data, &tab);
    handle_permissions_rec(tab, str);
}
