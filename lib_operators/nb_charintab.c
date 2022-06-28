/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-rayan.lebec
** File description:
** nb_charintab
*/

#include "42.h"

int nb_charintab(char **tab, char c)
{
    int nb = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++)
            nb += counter_nbchar(tab[i][j], c);
    }
    return nb;
}