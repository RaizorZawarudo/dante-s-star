/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** connect one string to a second string
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void my_putchar_err(char c)
{
    write(2, &c, 1);
}