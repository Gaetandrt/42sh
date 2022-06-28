/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-rayan.lebec
** File description:
** doubleleft
*/

#include "42.h"

void doubleleft(char **path, char *str, char **env, node **env_l)
{
    char *separator = "<<";
    char *a = strtok(str, separator);
    char *b = strtok(NULL, "");
    b = earse_first(b);
    char *x = s_eraser(a);
    char *y = s_eraser(b);
    char *tab[] = {x, y};

    if (y == NULL) {
        my_putstr("Missing name for redirect.\n");
        return 84;
    }
    execute_doubleleft(path, tab, env, env_l);
}