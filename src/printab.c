/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-rayan.lebec
** File description:
** printab
*/

#include "42.h"

void printab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        printf("%s\n", tab[i]);
}
