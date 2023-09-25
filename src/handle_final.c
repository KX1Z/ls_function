/*
** EPITECH PROJECT, 2022
** B-PSU-300-LYN-3-1-myls-keziah.picq
** File description:
** handle_final
*/

#include "my.h"

void handle_no_args(struct_t *data)
{
    int dir_files;

    if (data->R_case == true) {
        dir_files = get_dir_files_bis(".");
        data->files = get_dir_files(".", dir_files);
        final_rec_data(data);
    } else {
        handle_all_dir_files(".", data);
    }
}

void final_rec_bis(struct_t *data, int i)
{
    if (opendir(data->files[i]) != NULL) {
        my_putstr(data->files[i]);
        my_putchar('\n');
        handle_all_dir_files_rec(data->files[i], data);
        handle_all_recursivity(data->files[i], data);
    } else
        handle_permissions_file(data->files[i]);
}

bool final_rec_files(struct_t *data, int i)
{
    if (opendir(data->files[i]) != NULL) {
        my_putstr(data->files[i]);
        my_putchar('\n');
    } else {
        handle_permissions_file(data->files[i]);
        return true;
    }
    return false;
}

void final_rec(struct_t *data)
{
    for (int i = 0; data->files[i] != NULL; i++) {
        data->recursive = data->recursive++;
        handle_all_recursivity_bis(data->files[i], data);
        data->rec_tab = malloc(sizeof(char *)
        * data->recursive + 1);
        if (check_if_finalls(data, i) == 1)
            return;
        final_rec_bis(data, i);
        my_putstr("\n\n\n");
        data->recursive = 0;
    }
}

void final_rec_data(struct_t *data)
{
    for (int i = 2; data->files[i] != NULL; i++) {
        data->recursive = data->recursive++;
        handle_all_recursivity_bis(data->files[i], data);
        data->rec_tab = malloc(sizeof(char *)
        * data->recursive + 1);
        if (check_if_finalls(data, i) == 1)
            return;
        final_rec_bis(data, i);
        my_putstr("\n\n\n");
        data->recursive = 0;
    }
}
