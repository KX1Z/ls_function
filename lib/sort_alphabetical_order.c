/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** sort_alphabetical_order
*/

#include "../include/my.h"

static int array_size(char **array)
{
    int i = 0;

    while (array[i] != NULL)
        i++;
    return (i);
}

void change_alphabetical(char **array, int j)
{
    char *tmp;

    if (my_strcmp(array[j], array[j + 1]) > 0) {
        tmp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = tmp;
    }
}

void sort_alphabetical_order(char **array)
{
    int size = array_size(array);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            change_alphabetical(array, j);
        }
    }
}
