/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** handle_permissions
*/

#include "my.h"

char *my_strdup_propreties(char *src, char *tab)
{
    int count = 0;
    char *new_string = malloc(sizeof(char) * my_strlen(src) + 2
    + my_strlen(tab) + 5);

    my_strcpy(new_string, src);
    while (new_string[count] != 0) {
        count++;
    }
    new_string[count] = '/';
    new_string[count + 1] = 0;
    return new_string;
}

void handle_permissions(char **tab, char *str)
{
    struct stat fileStat;
    char *tmp;
    char *time;

    total(str);
    for (int i = 0; tab[i] != NULL; i++) {
        tmp = my_strdup_propreties(str, tab[i]);
        my_strcat(tmp, tab[i]);
        stat(tmp, &fileStat);
        permissions_one(fileStat);
        permissions_two(fileStat);
        time = ctime(&fileStat.st_mtime);
        permissions_three(time);
        my_putchar(' ');
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}

void handle_permissions_rec(char **tab, char *str)
{
    struct stat fileStat;
    char *tmp;
    char *time;

    total(str);
    for (int i = 0; tab[i] != NULL; i++) {
        tmp = my_strdup_propreties(str, tab[i]);
        my_strcat(tmp, tab[i]);
        stat(tmp, &fileStat);
        permissions_one(fileStat);
        permissions_two(fileStat);
        time = ctime(&fileStat.st_mtime);
        permissions_three(time);
        my_putchar(' ');
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    my_putstr("\n\n\n");
}

void handle_permissions_file(char *str)
{
    struct stat fileStat;
    char *time;

    stat(str, &fileStat);
    permissions_one(fileStat);
    permissions_two(fileStat);
    time = ctime(&fileStat.st_mtime);
    permissions_three(time);
    my_putchar(' ');
    my_putstr(str);
    my_putchar('\n');
}
