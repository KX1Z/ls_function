/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** sort_time
*/

#include "my.h"

bool compare_time(char *file_one, char *file_two, char *str)
{
    struct stat file_stat_one;
    struct stat file_stat_two;
    char *str_one = my_strdup_propreties(str, file_one);
    char *str_two = my_strdup_propreties(str, file_two);

    my_strcat(str_one, file_one);
    my_strcat(str_two, file_two);
    if (stat(str_one, &file_stat_one) == -1 ||
        stat(str_two, &file_stat_two) == -1)
        return (false);
    return (file_stat_one.st_mtime > file_stat_two.st_mtime);
}

void compare_time_bis_bis(char **tab, int i, int j, char *str)
{
    char *tmp;

    if (compare_time(tab[i], tab[j], str)) {
        tmp = tab[i];
        tab[i] = tab[j];
        tab[j] = tmp;
    }
}

void sort_by_time(char **tab, char *str)
{
    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; tab[j] != NULL; j++) {
            compare_time_bis_bis(tab, i, j, str);
        }
    }
}

void sort_time(struct_t *data, char **tab, char *str)
{
    if (data->t_case == true) {
        sort_by_time(tab, str);
    }
}
