/*
** EPITECH PROJECT, 2022
** B-PSU-300-LYN-3-1-myls-keziah.picq
** File description:
** my_strcat
*/

#include "../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int m = 0;

    for (; dest[i] != 0; i++) {
    }
    for (; src[m] != 0; m++) {
        dest[i + m] = src[m];
    }
    dest[i + m] = 0;
    return dest;
}
