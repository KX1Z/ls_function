/*
** EPITECH PROJECT, 2022
** pushswap
** File description:
** my_getnbr
*/

#include "../include/my.h"

int count_minus(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == '-' || str[i] == '+')
            count++;
        else
            return count;
    }
    return count;
}

int change_the_num(long long int *num, char const *str)
{
    int count = 0;
    int i = 0;

    while (str[i] > '9' || str[i] < '0') {
        if (str[i] == '-')
            count++;
        i++;
    }
    if (count % 2 != 0) {
        *num = -(*num);
    }
    return 0;
}

int check_overflow(long long int num)
{
    int sub_num;

    if (num < -2147483648 || num > 2147483647)
        return 0;
    sub_num = num;
    return sub_num;
}

int my_getnbr(char const *str)
{
    int count = count_minus(str);
    long long int num = 0;
    int i = count;
    int sub_num;

    for (; str[i] != 0; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            num = num * 10;
            num = num + (str[i] - 48);
        } else {
            change_the_num(&num, str);
            return sub_num = check_overflow(num);
        }
    }
    change_the_num(&num, str);
    return sub_num = check_overflow(num);
}
