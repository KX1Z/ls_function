/*
** EPITECH PROJECT, 2022
** B-PSU-300-LYN-3-1-myls-keziah.picq
** File description:
** handle_final_bis
*/

#include "my.h"

void data_files(struct_t *data, int i)
{
    if (data->files[i + 1] != NULL)
        my_putchar('\n');
}

void handle_final_bis(struct_t *data)
{
    for (int i = 0; data->files[i] != NULL; i++) {
        if (opendir(data->files[i]) == NULL)
            handle_all_dir_files(data->files[i], data);
    }
    for (int i = 0; data->files[i] != NULL; i++) {
        if (check_if_dir_null(data->files) == 2 &&
            opendir(data->files[i]) != NULL) {
            my_putchar('\n');
            my_putstr(data->files[i]);
            my_putstr(":\n");
            handle_all_dir_files(data->files[i], data);
        }
        if (opendir(data->files[i]) != NULL &&
            check_if_dir_null(data->files) != 2) {
            handle_all_dir_files(data->files[i], data);
            data_files(data, i);
        }
    }
}
