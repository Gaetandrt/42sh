/*
** EPITECH PROJECT, 2022
** functon for minishell1
** File description:
** utilitys
*/

#include "42.h"

int line_count(char *src)
{
    int cpt = 0;

    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] == ':')
            cpt++;
    }
    return (cpt);
}

int my_arraylen(char **av)
{
    int i = 0;

    while (av[i])
        i++;
    return (i);
}
