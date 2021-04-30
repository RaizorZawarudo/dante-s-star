/*
** EPITECH PROJECT, 2021
** B-CPE-200-BER-2-1-dante-renan.dubois
** File description:
** maze_gen_tools
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./lib/my.h"

int pos_to_pixels(int x, int y, int width)
{
    return (y * width + x);
}

void print_maze(char *grid, int width, int height)
{
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            my_putchar(grid[pos_to_pixels(x, y, width)]);
        }
        if (y != height - 1)
            my_putchar('\n');
    }
}

char *refresh_maze(char *grid, int width, int height)
{
    for (int i = 0; i < width * height; i++)
        grid[i] = 'X';
    return (grid);
}

int check_in_bounds(int x, int y, int width, int height)
{
    if (width % 2 == 0)
        width = width - 1;
    if (x < 0 || x >= width)
        return (0);
    if (y < 0 || y >= height)
        return (0);
    return (1);
}

char *put_grid_exits(char *grid, data_t data)
{
    grid[0] = '*';
    grid[1] = '*';
    grid[data.width * data.height - 1] = '*';
    grid[data.width * (data.height - 2) + data.width - 1] = '*';
    grid[data.width * (data.height - 2) + data.width - 2] = '*';
    return (grid);
}