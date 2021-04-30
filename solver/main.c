/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** .
*/

#include "./lib/my.h"

void my_solver(char **map, infos *info)
{
    data *path = malloc(sizeof(data) * (info->width * info->height) + 1);
    data *visited = malloc(sizeof(data) * (info->width * info->height) + 1);

    for (int i = 0 ; i < info->height; i++) {
        for (int j = 0; j < info->width; j++) {
            if (map[i][j] == '*')
                info->nbr_path = info->nbr_path + 1;
        }
    }
    path[0].x = 0;
    path[0].y = 0;
    visited[0].x = 0;
    visited[0].y = 0;
    move_test(info, path, visited);

}

void my_reset_info(infos *info)
{
    info->did_up = 0;
    info->did_down = 0;
    info->did_left = 0;
    info->did_right = 0;
}

int create_path(infos *info, data *path, data *visited)
{
    int loop = 0;
    int a = 4 ;

    while (loop != 1)
    {
        loop = my_move_to(a, info, path, visited);
        if (info->did_up == 1 && info->did_down == 1
        && info->did_left == 1 && info->did_right == 1){
            my_backtrack(info, path);
            my_reset_info(info);
            return (info->path_pos);
        }
        a--;
    }
    my_reset_info(info);
    return (info->path_pos);
}

void move_test(infos *info, data *path, data *visited)
{
    int i = info->path_pos;
    int end_x = info->width - 1;
    int end_y = info->height - 1;

    while (path[i].x != end_x || path[i].y != end_y) {
        if (info->visited_pos == info->nbr_path - 1) {
            printf("no solution found\n");
            exit (84);
        }
        i = create_path(info, path, visited);
    }
    free(visited);
    print_maze(info, path);
}

int main(int ac, char **av)
{
    char *buffer = NULL;
    char **map = NULL;
    infos *info = malloc(sizeof(infos));

    if (ac != 2)
        return (84);
    buffer = load_file_in_mem(av[1]);
    map = create_map(buffer, info);
    my_solver(map, info);
    free (info);
    free (buffer);
    free_char_table(map);
    return (0);
}