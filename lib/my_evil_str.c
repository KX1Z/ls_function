/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** my_evil_str
*/

#include "../include/my.h"

char *my_evil_str(char *str)
{
    int count = my_strlen(str);
    int mid = count / 2 - 1;
    int i = 0;
    int l = count - 1;
    char tmp = 0;

    while (i <= mid) {
        tmp = str[i];
        str[i] = str[l];
        str[l] = tmp;
        i++;
        l--;
    }
    return str;
}
