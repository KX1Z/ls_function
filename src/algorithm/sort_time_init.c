/*
** EPITECH PROJECT, 2022
** B-PSU-300-LYN-3-1-myls-keziah.picq
** File description:
** sort_time_init
*/

#include "my.h"

bool compare_time_init(char *file_one, char *file_two)
{
    struct stat file_stat_one;
    struct stat file_stat_two;
    char *str_one = file_one;
    char *str_two = file_two;

    if (stat(str_one, &file_stat_one) == -1 ||
        stat(str_two, &file_stat_two) == -1)
        return (false);
    return (file_stat_one.st_mtime > file_stat_two.st_mtime);
}

void compare_time_init_init(char **tab, int i, int j)
{
    char *tmp;

    if (compare_time_init(tab[i], tab[j])) {
        tmp = tab[i];
        tab[i] = tab[j];
        tab[j] = tmp;
    }
}

void sort_by_time_init(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; tab[j] != NULL; j++) {
            compare_time_init_init(tab, i, j);
        }
    }
}

void sort_time_init(struct_t *data, char **tab)
{
    if (data->t_case == true) {
        sort_by_time_init(tab);
    }
}
