/*
** EPITECH PROJECT, 2022
** B-PSU-300-LYN-3-1-myls-keziah.picq
** File description:
** total
*/

#include "my.h"

char *enter_directory(char *file, char *end)
{
    int i = 0;
    int j = 0;
    int l = 0;
    char *str = NULL;

    for (; file[i]; i++);
    for (; end[j]; j++);
    if (file[i - 1] != '/')
        l++;
    str = malloc(sizeof(char) * (i + j + l + 1));
    str = my_strcpy(str, file);
    if (l == 1)
        str = my_strcat(str, "/");
    str = my_strcat(str, end);
    return (str);
}

void total(char *file)
{
    struct dirent *dirent;
    struct stat data;
    DIR *dir = opendir(file);
    int nb = 0;
    int total = 0;
    char *str = NULL;

    while (dirent = readdir(dir)) {
        if (dirent->d_name[0] == '.')
            continue;
        str = enter_directory(file, dirent->d_name);
        stat(str, &data);
        nb = data.st_blocks;
        total = nb + total;
    } my_putstr("total ");
    my_put_nbr(total);
    my_putchar('\n');
    closedir(dir);
}
