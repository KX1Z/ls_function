/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** my_strdup
*/

#include "../include/my.h"

char *my_strdup(char *src)
{
    char *new_string = malloc(sizeof(char) * my_strlen(src) + 1);
    my_strcpy(new_string, src);
    return new_string;
}
