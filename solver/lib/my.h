/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <time.h>
#include <fcntl.h>
#include <math.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>

typedef struct infos {
    int width;
    int height;
    int path_pos;
    int visited_pos;
    int did_up;
    int did_down;
    int did_left;
    int did_right;
    int nbr_path;
    char **map;
} infos;

typedef struct data {
    int x;
    int y;

} data;

int my_str_isnum(char *str);
int my_strcmp(char const *s1, char const *s2);
char *my_put_nbr_eval(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_putchar_err(char c);
int my_putstr_err(char const *str);
int my_diff(char letter, int key);
char *my_decrypter(char *file, int key);
char my_small_letter(char letter, int key);
char my_capital_letter(char letter, int key);
char *read_file(char *filepath);
void file_creating(char *str);
int err_handling(int ac, char *av[]);
int check_arguments(int ac, char **av);
char *load_file_in_mem(char const *filepath);
char **create_map(char *buffer, infos *info);
void move_test(infos *info, data *path, data *visited);
int check_backtracking(infos *info, data *visited, int x , int y);
void my_backtrack(infos *info, data *path);
void initialize(infos *info, int width, int height, char **map);
int my_move_to(int a, infos *info, data *path, data *visited);
void print_maze(infos *info, data *path);
void free_char_table(char **table);

#endif /* !MY_H_ */