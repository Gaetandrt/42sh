/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-rayan.lebec
** File description:
** earse_char
*/

#include "42.h"

char **erase_char(char **tab, char c)
{
    int i = 0;
    int j = 0;

    char **new = malloc(sizeof(char *) * (my_arraylen(tab) + 1));
    for (i = 0; tab[i] != NULL; i++) {
        if (tab[i][0] == c) {
            for (j = i; tab[j] != NULL; j++) {
                tab[j] = tab[j + 1];
            }
            i--;
        }
        tab[i] = erase_delim(tab[i], c);
    }
    for (i = 0; tab[i] != NULL; i++) {
        new[i] = tab[i];
    }
    new[i] = NULL;
    return new;
}