/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** handle_recursivity
*/

#include "my.h"
#include <stdio.h>
#include <string.h>
#include <dirent.h>

void handle_all_recursivity_bis(const char* dirname, struct_t *data)
{
    DIR* dir = opendir(dirname);
    if (dir == NULL)
        return;
    struct dirent* entity;
    entity = readdir(dir);
    while (entity != NULL) {
        if (entity->d_type == DT_DIR && my_strcmp(entity->d_name, ".") != 0 &&
        my_strcmp(entity->d_name, "..") != 0) {
            char path[100] = { 0 };
            my_strcat(path, dirname);
            my_strcat(path, "/");
            my_strcat(path, entity->d_name);
            data->recursive = data->recursive++;
            handle_all_recursivity_bis(path, data);
        }
        entity = readdir(dir);
    }
    closedir(dir);
}

void handle_recursivity(const char* dirname, struct_t *data)
{
    DIR* dir = opendir(dirname);

    if (dir == NULL)
        return;
    struct dirent* entity;
    entity = readdir(dir);
    while (entity != NULL) {
        if (entity->d_type == DT_DIR && my_strcmp(entity->d_name, ".") != 0 &&
        my_strcmp(entity->d_name, "..") != 0) {
            char path[100] = { 0 };
            my_strcat(path, dirname);
            my_strcat(path, "/");
            my_strcat(path, entity->d_name);
            data->rec_tab[data->recursive] = my_strdup(path);
            data->recursive++;
            handle_recursivity(path, data);
        }
        entity = readdir(dir);
    } data->rec_tab[data->recursive] = NULL;
    closedir(dir);
}

void handle_all_recursivity(const char* dirname, struct_t *data)
{
    if (opendir(dirname) == NULL)
        return;
    handle_recursivity(dirname, data);
    handle_a_r(data, &data->rec_tab);
    for (int i = 0; data->rec_tab[i] != NULL; i++) {
        if (data->rec_tab[i + 1] == NULL) {
            my_putstr(data->rec_tab[i]);
            my_putchar('\n');
            handle_all_dir_files(data->rec_tab[i], data);
            return;
        } my_putstr(data->rec_tab[i]);
        my_putchar('\n');
        handle_all_dir_files_rec(data->rec_tab[i], data);
    }
}

void handle_all_recursivity_last(const char* dirname, struct_t *data)
{
    handle_recursivity(dirname, data);
    handle_a_r(data, &data->rec_tab);

    for (int i = 0; data->rec_tab[i] != NULL; i++) {
        if (opendir(data->rec_tab[i]) == NULL) {
            handle_permissions_file(data->rec_tab[i]);
            return;
        } if (data->rec_tab[i + 1] == NULL) {
            my_putstr(data->rec_tab[i]);
            my_putchar('\n');
            handle_all_dir_files(data->rec_tab[i], data);
            return;
        }
        my_putstr(data->rec_tab[i]);
        my_putchar('\n');
        handle_all_dir_files_rec(data->rec_tab[i], data);
    }
}
