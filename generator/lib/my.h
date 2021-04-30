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

#define NORTH 0
#define EAST  1
#define SOUTH 2
#define WEST  3

typedef struct data_s {
    int width;
    int height;
    int count;

} data_t;

typedef struct offsets_s {
    int offset_x;
    int offset_y;
    int x2;
    int y2;
} mazer_data;

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

char *deperfectize_grid(char *grid, int width, int height);
int pos_to_pixels( int x, int y, int width);
void print_maze(char *grid, int width, int height);
char *refresh_maze(char *grid, int width, int height);
int check_in_bounds( int x, int y, int width, int height);
char *put_grid_exits(char *grid, data_t data);

#endif /* !MY_H_ */