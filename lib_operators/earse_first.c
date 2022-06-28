/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-rayan.lebec
** File description:
** earse_first
*/

#include "42.h"

char *earse_first(char *str)
{
    char *new = malloc(sizeof(char) * my_strlen(str));
    int j = 0;

    for (int i = 1; str[i] != '\0'; i++) {
        new[j] = str[i];
        j++;
    }
    return new;
}