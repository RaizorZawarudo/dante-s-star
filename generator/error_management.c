/*
** EPITECH PROJECT, 2021
** B-CPE-200-BER-2-1-dante-renan.dubois
** File description:
** error_management
*/

#include "./lib/my.h"

int check_arguments(int ac, char **av)
{
    if (ac < 3 || ac > 4)
        return 0;
    if (!my_str_isnum(av[1]) || !my_str_isnum(av[2])) {
        write(2, "width and lenght of maze must be integers", 41);
        return 0;
    }
    if (my_getnbr(av[1]) < 1 || my_getnbr(av[2]) < 1) {
        write(2, "width and lenght of maze must be bigger than 0", 46);
        return 0;
    }
    if (ac == 4 && strcmp(av[3], "perfect")) {
        write(2, "Only \"perfect\" can be passed as third argument", 44);
        return 0;
    }
    if (my_getnbr(av[1]) * my_getnbr(av[2]) >= 1208900)
        return (0);
    return 1;
}

char *deperfectize_grid(char *grid, int width, int height)
{
    int r = 0;

    for (int i = 0; i < width * height; i++) {
        if (grid[i] == 'X') {
            r = rand() % 20;
            if ( r == 1 || r == 2)
                grid[i] = '*';
        }
    }
    return (grid);
}