/*
** EPITECH PROJECT, 2022
** B-PSU-300-LYN-3-1-myls-keziah.picq
** File description:
** check_dir
*/

#include "my.h"

int check_if_dir_null(char **tab)
{
    for (int i = 0; tab[i] != 0; i++) {
        if (opendir(tab[i]) == 0)
            return 2;
    }
    return 0;
}

int check_if_dir(char **tab)
{
    for (int i = 0; tab[i] != 0; i++) {
        if (opendir(tab[i]) != 0)
            return 2;
    }
    return 0;
}

int check_if_finalls(struct_t *data, int i)
{
    if (data->files[i + 1] == NULL) {
        if (final_rec_files(data, i) == true)
            return 1;
        handle_all_dir_files(data->files[i], data);
        my_putstr("\n\n\n");
        handle_all_recursivity_last(data->files[i], data);
        return 1;
    }
    return 0;
}
