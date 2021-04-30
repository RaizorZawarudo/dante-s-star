/*
** EPITECH PROJECT, 2020
** my_putstr.c
** File description:
** displaying string characters
*/

#include <unistd.h>

void my_putchar(char c);

void my_putchar_err(char c);

int my_putstr_err(char const *str)
{
    while (*str != '\0') {
        my_putchar_err(*str);
        str++;
    }
    return 0;
}