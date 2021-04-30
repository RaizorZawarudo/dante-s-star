/*
** EPITECH PROJECT, 2020
** my_putstr.c
** File description:
** displaying string characters
*/

#include <unistd.h>

void my_putchar(char c);

int my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str++;
    }
    return 0;
}