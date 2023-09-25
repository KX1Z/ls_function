/*
** EPITECH PROJECT, 2022
** pushswap
** File description:
** pushswap
*/

#include "../include/my.h"

int my_ls(int ac, char **av)
{
    struct_t data;
    handle_struct(ac, av, &data);

    if (my_strlen_tab(data.files) == 0)
        handle_no_args(&data);
    else {
        if (data.R_case == true)
            final_rec(&data);
        else {
            handle_final_bis(&data);
        }
    }
    return 0;
}
