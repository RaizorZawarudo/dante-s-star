/*
** EPITECH PROJECT, 2021
** load_file
** File description:
** .
*/

#include "./lib/my.h"

char *load_file_in_mem(char const *filepath)
{
    int filedescriptor = 0;
    int size;
    struct stat stats;
    char *buffer;

    filedescriptor = open(filepath, O_RDONLY);
    if (filedescriptor == -1) {
        my_putstr("No such file");
        exit (84);
    }
    stat(filepath, &stats);
    size = stats.st_size;
    buffer = malloc(sizeof(char) * size + 1);
    read(filedescriptor, buffer, size);
    close(filedescriptor);
    return (buffer);
}

int get_map_width (char *buffer)
{
    int width = 0;

    for (int i = 0; buffer[i] != '\n'; i++) {
        if (buffer[i] != '\n')
            width++;
    }
    return (width);
}

int get_map_height(char *buffer)
{
    int height = 0;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if ( buffer[i] == '\n')
            height += 1;
    }
    height += 1;
    return height;
}

void initialize(infos *info, int width, int height, char **map)
{
    info->width = width;
    info->height = height;
    info->path_pos = 0;
    info->visited_pos = 0;
    info->did_up = 0;
    info->did_down = 0;
    info->did_left = 0;
    info->did_right = 0;
    info->nbr_path = 0;
    info->map = map;
}

char **create_map(char *buffer, infos *info)
{
    char **map = NULL;
    int height = get_map_height(buffer);
    int width = get_map_height(buffer);
    int counter = 0;

    map = malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++) {
        map[i] = malloc(sizeof(char) * width);
    }
    for (int i = 0 ; i < height; i++) {
        for (int j = 0; j < width; j++) {
            map[i][j] = buffer[counter];
            counter++;
            if (buffer[counter] == '\n')
                counter++;
        }
    }
    initialize(info, width, height, map);
    return map;
}