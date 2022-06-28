/*
** EPITECH PROJECT, 2022
** parse an array of string to find caracter
** File description:
** my_aos_parse
*/

#include <stdlib.h>
#include <stdio.h>

int my_aos_parse_bis(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return (1);
    }
    return (0);
}

int my_aos_parse(char **array, char c)
{
    int y = 0;

    while (array[y] != NULL) {
        if (my_aos_parse_bis(array[y], c) == 0)
            y++;
        else
            return (1);
    }
    return (0);
}
