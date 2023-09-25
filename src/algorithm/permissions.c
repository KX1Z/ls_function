/*
** EPITECH PROJECT, 2022
** B-PSU-300-LYN-3-1-myls-keziah.picq
** File description:
** permissions
*/

#include "my.h"

void permissions_one(struct stat fileStat)
{
    my_putstr( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    my_putstr( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    my_putstr( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    my_putstr( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    my_putstr( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    my_putstr( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    my_putstr( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    my_putstr( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    my_putstr( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    my_putstr( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    my_putstr(" ");
    my_put_nbr(fileStat.st_nlink);
}

void permissions_two(struct stat fileStat)
{
    struct passwd *pw;
    struct group  *gr;

    pw = getpwuid(fileStat.st_uid);
    gr = getgrgid(fileStat.st_gid);
    if (pw != 0) {
        my_putstr(" ");
        my_putstr(pw->pw_name);
    }
    if (gr != 0) {
        my_putstr(" ");
        my_putstr(gr->gr_name);
    }
    my_putchar(' ');
    my_put_nbr(fileStat.st_size);
    my_putchar(' ');
}

void permissions_three(char *time)
{
    int var_time = 0;
    int tmp_time = 0;
    for (; time[var_time] != ' '; var_time++) {
    } var_time++;
    tmp_time = var_time;
    for (; time[tmp_time] < '0'
    || time[tmp_time] > '9'; tmp_time++) {
    } for (; time[tmp_time] != ' '; tmp_time++)
        my_putchar(time[tmp_time]);
    tmp_time++;
    my_putchar(' ');
    for (; time[var_time] != ' '; var_time++)
        my_putchar(time[var_time]);
    my_putchar(' ');
    for (int i = 0; i < 5; i++) {
        my_putchar(time[tmp_time]);
        tmp_time++;
    }
}
