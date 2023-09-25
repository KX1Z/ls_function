/*
** EPITECH PROJECT, 2022
** B-CPE-101-LYN-1-1-pushswap-keziah.picq
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <stddef.h>
    #include <ncurses.h>
    #include <string.h>
    #include <limits.h>
    #include <dirent.h>
    #include <sys/types.h>
    #include <pwd.h>
    #include <time.h>
    #include <grp.h>


    typedef struct linked_list {
        bool a_case;
        bool l_case;
        bool R_case;
        bool d_case;
        bool r_case;
        bool t_case;
        char **files;
        int recursive;
        char **rec_tab;
        int total;
    } struct_t;

    #define PRECISION 6

// Library
unsigned int my_ptr_get_nbr(char const *str, int *i);
void my_putchar(char c);
void my_put_nbr(int nb);
void my_put_unsigned_number(unsigned int nb);
int my_strlen(char const *str);
void my_putstr(char const *str);
int my_get_nbr_size(int nb);
int my_getnbr(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char *src);
char *my_strdup(char *src);
int my_strlen_tab(char **tab);
char *my_evil_str(char *str);
int find_size_max_tab(char **tab);
void sort_alphabetical_order(char **array);
void change_alphabetical(char **array, int j);
char **my_evil_str_tab(char **tab);
char *my_strcat(char *dest, char const *src);

// ls_case
void handle_flags(int i, char **av, struct_t *data);
void handle_files_dir(int count, int ac, char **av, struct_t *data);
int handle_struct(int ac, char **av, struct_t *data);
int get_dir_files_bis(char *str);
char **get_dir_files(char *str, int dir_files);
void handle_all_dir_files(char *str, struct_t *data);
int my_ls(int ac, char **av);
char **handle_a(struct_t *data, char **dir_files_tab);
void handle_a_r(struct_t *data, char ***tab);
void handle_recursivity(const char* dirname, struct_t *data);
void handle_permissions(char **tab, char *str);
char *my_strdup_propreties(char *src, char *tab);

void handle_permissions_rec(char **tab, char *str);
void handle_all_dir_files_rec(char *str, struct_t *data);
void handle_all_recursivity_bis(const char* dirname, struct_t *data);
void handle_recursivity(const char* dirname, struct_t *data);
void handle_all_recursivity(const char* dirname, struct_t *data);
void handle_all_recursivity_last(const char* dirname, struct_t *data);
void handle_permissions_file(char *str);
int check_if_dir_null(char **tab);
int check_if_dir(char **tab);
void total(char *file);
char *enter_directory(char *one, char *end);

void permissions_one(struct stat fileStat);
void permissions_two(struct stat fileStat);
void permissions_three(char *time);

void handle_no_args(struct_t *data);
bool final_rec_files(struct_t *data, int i);
void final_rec_bis(struct_t *data, int i);
void final_rec(struct_t *data);
void final_rec_data(struct_t *data);

void data_files(struct_t *data, int i);
void handle_final_bis(struct_t *data);
int final_rec_haha(struct_t *data);
int check_if_finalls(struct_t *data, int i);

bool compare_time(char *file_one, char *file_two, char *str);
bool compare_time_init(char *file_one, char *file_two);
void sort_by_time_init(char **tab);
void sort_by_time(char **tab, char *str);
void sort_time_init(struct_t *data, char **tab);
void sort_time(struct_t *data, char **tab, char *str);
void compare_time_bis_bis(char **tab, int i, int j, char *str);
void compare_time_init_init(char **tab, int i, int j);

#endif /* !MY_H_ */
