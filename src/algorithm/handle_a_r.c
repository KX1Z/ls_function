/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** handle_a_r
*/

#include "my.h"

char **handle_a(struct_t *data, char **dir_files_tab)
{
    char **tab = malloc(sizeof(char *)
    * my_strlen_tab(dir_files_tab) + 1);
    int m = 0;

    for (int i = 0; dir_files_tab[i] != NULL; i++) {
        if (dir_files_tab[i][0] != '.') {
            tab[m] = dir_files_tab[i];
            m++;
        }
    }
    tab[m] = NULL;
    return tab;
}

void handle_a_r(struct_t *data, char ***tab)
{
    if (data->a_case == false)
        *tab = handle_a(data, *tab);
    if (data->r_case == true) {
        sort_alphabetical_order(*tab);
        my_evil_str_tab(*tab);
    } else
        sort_alphabetical_order(*tab);
}
