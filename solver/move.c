/*
** EPITECH PROJECT, 2021
** move.c
** File description:
** .
*/

#include "./lib/my.h"

int move_up(infos *info, data *path, data *visited)
{
    if (path[info->path_pos].y - 1 < 0) {
        info->did_up = 1;
        return (0);
    }
    if (info->map[path[info->path_pos].x][path[info->path_pos].y - 1] == 'X') {
        info->did_up = 1;
        return (0);
    }
    if (check_backtracking(info, visited,
    path[info->path_pos].x, path[info->path_pos].y - 1) == 0){
        info->did_up = 1;
        return (0);
    }
    path[info->path_pos + 1].y = path[info->path_pos].y - 1;
    path[info->path_pos + 1].x = path[info->path_pos].x;
    info->path_pos = info->path_pos + 1;
    visited[info->visited_pos + 1].y = path[info->path_pos].y;
    visited[info->visited_pos + 1].x = path[info->path_pos].x;
    info->visited_pos = info->visited_pos + 1;
    return (1);
}

int move_down(infos *info, data *path, data *visited)
{
    if (path[info->path_pos].y + 1 > info->height - 1) {
        info->did_down = 1;
        return (0);
    }
    if (info->map[path[info->path_pos].x][path[info->path_pos].y + 1] == 'X') {
        info->did_down = 1;
        return (0);
    }
    if (check_backtracking(info, visited,
    path[info->path_pos].x, path[info->path_pos].y + 1) == 0) {
        info->did_down = 1;
        return (0);
    }
    path[info->path_pos + 1].y = path[info->path_pos].y + 1;
    path[info->path_pos + 1].x = path[info->path_pos].x;
    info->path_pos = info->path_pos + 1;
    visited[info->visited_pos + 1].y = path[info->path_pos].y;
    visited[info->visited_pos + 1].x = path[info->path_pos].x;
    info->visited_pos = info->visited_pos + 1;
    return (1);
}

int move_left(infos *info, data *path, data *visited)
{
    if (path[info->path_pos].x - 1 < 0){
        info->did_left = 1;
        return (0);
    }
    if (info->map[path[info->path_pos].x - 1][path[info->path_pos].y] == 'X') {
        info->did_left = 1;
        return (0);
    }
    if (check_backtracking(info, visited,
    path[info->path_pos].x - 1, path[info->path_pos].y) == 0) {
        info->did_left = 1;
        return (0);
    }
    path[info->path_pos + 1].y = path[info->path_pos].y;
    path[info->path_pos + 1].x = path[info->path_pos].x - 1;
    info->path_pos = info->path_pos + 1;
    visited[info->visited_pos + 1].y = path[info->path_pos].y;
    visited[info->visited_pos + 1].x = path[info->path_pos].x;
    info->visited_pos = info->visited_pos + 1;
    return (1);
}

int move_right(infos *info, data *path, data *visited)
{
    if (path[info->path_pos].x + 1 > info->width - 1){
        info->did_right = 1;
        return (0);
    }
    if (info->map[path[info->path_pos].x + 1][path[info->path_pos].y] == 'X') {
        info->did_right = 1;
        return (0);
    }
    if (check_backtracking(info, visited,
    path[info->path_pos].x + 1, path[info->path_pos].y) == 0) {
        info->did_right = 1;
        return (0);
    }
    path[info->path_pos + 1].y = path[info->path_pos].y;
    path[info->path_pos + 1].x = path[info->path_pos].x + 1;
    info->path_pos = info->path_pos + 1;
    visited[info->visited_pos + 1].y = path[info->path_pos].y;
    visited[info->visited_pos + 1].x = path[info->path_pos].x;
    info->visited_pos = info->visited_pos + 1;
    return (1);
}

int my_move_to(int a, infos *info, data *path, data *visited)
{
    int value = 0;

    switch (a)
    {
        case 1:
            value = move_up(info, path, visited);
            break;
        case 4:
            value = move_down(info, path, visited);
            break;
        case 2:
            value = move_left(info, path, visited);
            break;
        case 3:
            value = move_right(info, path, visited);
            break;
    }
    return (value);
}
