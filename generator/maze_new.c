/*
** EPITECH PROJECT, 2021
** B-CPE-200-BER-2-1-dante-renan.dubois
** File description:
** maze_new
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./lib/my.h"

void shuffle_directions(int *dirs)
{
    int r = 0;
    for (int i = 0; i < 4; ++i) {
        r = rand() & 3;
        int temp = dirs[r];
        dirs[r]  = dirs[i];
        dirs[i]  = temp;
    }
}

int *initiate_direction(void)
{
    int *dirs = malloc(sizeof(int) * 4);

    dirs[0] = NORTH;
    dirs[1] = EAST;
    dirs[2] = SOUTH;
    dirs[3] = WEST;
    shuffle_directions(dirs);
    return dirs;
}

void update_offsets(mazer_data *mazer, int i, int *dirs)
{
    mazer->offset_x = 0;
    mazer->offset_y = 0;

    switch (dirs[i]) {
        case NORTH: mazer->offset_y = -1; break;
        case SOUTH: mazer->offset_y =  1; break;
        case EAST:  mazer->offset_x =  1; break;
        case WEST:  mazer->offset_x = -1; break;
    }
}

void got_to_position(int x, int y, char *grid, data_t data)
{
    mazer_data mazer;

    int *dirs = initiate_direction();
    grid[ pos_to_pixels(x, y, data.width) ] = '*';
    for (int i = 0; i < 4; i++) {
        update_offsets(&mazer , i, dirs);
        mazer.x2 = x + (mazer.offset_x) + mazer.offset_x;
        mazer.y2 = y + (mazer.offset_y) + mazer.offset_y;
        if (check_in_bounds(mazer.x2, mazer.y2, data.width, data.height)) {
            if (grid[ pos_to_pixels(mazer.x2, mazer.y2, data.width) ] == 'X') {
                grid[ pos_to_pixels(mazer.x2 - mazer.offset_x, mazer.y2 -
                mazer.offset_y, data.width) ] = '*';
                data.count = data.count + 1;
                got_to_position(mazer.x2, mazer.y2, grid, data);
            }
        }
    }
    free(dirs);
}

int main(int ac , char **av)
{
    data_t data;
    char *grid = NULL;

    if (!check_arguments(ac, av))
        return (84);
    data.width = my_getnbr(av[1]);
    data.height = my_getnbr(av[2]);
    data.count = 0;
    grid = malloc(sizeof(char) * (data.width * data.height));
    if (grid == NULL)
        return (84);
    srand( time(0) );
    grid = refresh_maze(grid, data.width, data.height);
    got_to_position(1, 1, grid, data);
    grid = put_grid_exits(grid, data);
    if (ac != 4)
        grid = deperfectize_grid(grid, data.width, data.height);
    print_maze(grid, data.width, data.height);
    free(grid);
    return (0);
}