/*
** EPITECH PROJECT, 2020
** my_strcmp.c
** File description:
** comparing strings
*/

int my_strcmp(char const *s1, char const *s2)
{
    int index = 0;
    int test = 0;

    while (s1[index] == s2[index] && (s1[index] != '\0' || s2[index] != '\0'))
        index++;
    test = (int) s1[index] - (int) s2[index];
    return test;
}