/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-rayan.lebec
** File description:
** erase_delim
*/

#include "42.h"

char *erase_delim(char *str, char c)
{
    int i = 0;
    int j = 0;
    char *new = malloc(sizeof(char) * strlen(str));

    while (str[i] != '\0') {
        if (str[i] != c) {
            new[j] = str[i];
            j++;
        } else {
            new[j] = ' ';
            j++;
        }
        i++;
    }
    new[j] = '\0';
    return new;
}