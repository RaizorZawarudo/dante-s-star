/*
** EPITECH PROJECT, 2021
** tools.c
** File description:
** .
*/

#include "./lib/my.h"

void print_maze(infos *info, data *path)
{
    for (int i = 0; i < info->path_pos; i++)
        info->map[path[i].y][path[i].x] = 'o';
    info->map[info->height - 1][info->width - 1] = 'o';
    for (int i = 0; i < info->height; i++)
        if (i == info->height - 1)
            printf("%s", info->map[i]);
        else
            printf("%s\n", info->map[i]);
    free(path);
}

void free_char_table(char **table)
{
    for (int i = 0; table[i]; i++)
        free(table[i]);
    free(table);
}

int check_backtracking(infos *info, data *visited, int x , int y)
{
    for (int i = 0; i <= info->visited_pos; i++) {
        if (visited[i].x == x && visited[i].y == y){
            return (0);
        }
    }
    return (1);
}

void my_backtrack(infos *info, data *path)
{
    path[info->path_pos].x = -1;
    path[info->path_pos].y = -1;
    info->path_pos = info->path_pos - 1;
}