/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** hanlde_struct
*/

#include "my.h"

void handle_flags(int i, char **av, struct_t *data)
{
    for (int m = 1; av[i][m] != 0; m++) {
        if (av[i][m] == 'a')
            data->a_case = true;
        if (av[i][m] == 'l')
            data->l_case = true;
        if (av[i][m] == 'R')
            data->R_case = true;
        if (av[i][m] == 'd')
            data->d_case = true;
        if (av[i][m] == 'r')
            data->r_case = true;
        if (av[i][m] == 't')
            data->t_case = true;
    }
}

void handle_files_dir(int count, int ac, char **av, struct_t *data)
{
    char **tab = malloc(sizeof(char *) * count + 1);
    int l = 0;

    for (int i = 1; i < ac; i++) {
        if (av[i][0] != '-') {
            tab[l] = my_strdup(av[i]);
            l++;
        }
    }
    tab[l] = NULL;
    data->files = tab;
    if (data->t_case == true) {
        sort_alphabetical_order(data->files);
        sort_time_init(data, data->files);
    }
}

int handle_struct(int ac, char **av, struct_t *data)
{
    int count = 0;

    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-')
            handle_flags(i, av, data);
        else
            count++;
    }
    handle_files_dir(count, ac, av, data);
    data->recursive = 0;
    return count;
}
