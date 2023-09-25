/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** my_evil_str_tab
*/

#include "../include/my.h"

char **my_evil_str_tab(char **tab)
{
    int count = my_strlen_tab(tab);
    int mid = count / 2 - 1;
    int i = 0;
    int l = count - 1;
    char *tmp;

    while (i <= mid) {
        tmp = tab[i];
        tab[i] = tab[l];
        tab[l] = tmp;
        i++;
        l--;
    }
    return tab;
}
