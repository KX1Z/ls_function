/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** my_strcpy
*/

#include "../include/my.h"

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
