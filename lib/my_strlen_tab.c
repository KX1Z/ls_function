/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** my_strlen_tab
*/

#include "../include/my.h"

int my_strlen_tab(char **tab)
{
    int count = 0;

    while (tab[count] != NULL)
        count++;
    return count;
}
