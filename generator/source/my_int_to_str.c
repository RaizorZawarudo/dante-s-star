/*
** EPITECH PROJECT, 2020
** rush-1-4.c
** File description:
** rush 1 - 4 copy pasta code from 2
*/

#include <stdlib.h>

void import_int_to_str(int counter, int temp, char *str, int i)
{
    int potenz = 0;

    for (; counter >= 0; counter--) {
        potenz = 1;
        for (int temp_counter = counter; temp_counter > 0; temp_counter--) {
            potenz = potenz * 10;
        }
        str[i] = (temp / potenz % 10) + 48;
        i++;
    }
    str[i] = '\0';
}

char *my_put_nbr_eval(int nb)
{
    int counter = 0;
    int i = 0;
    int temp = nb;
    char *str = malloc(sizeof(char) * 11);

    if (nb < 0) {
        temp = temp * (-1);
        nb = nb * (-1);
        str[i] = '-';
        i++;
    }
    while ((nb - 10) >= 0) {
        nb /= 10;
        counter++;
    }
    import_int_to_str(counter, temp, str, i);
    return str;
}