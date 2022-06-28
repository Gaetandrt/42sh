/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-rayan.lebec
** File description:
** redirecor
*/

#include "42.h"

int redirector(char **path, char *str, char **env, node **env_l)
{
    char *separator = ">";
    char *b = strtok(str, separator);
    char *c = strtok(NULL, "");
    char *cmd = s_eraser(b);
    char *filename = s_eraser(c);
    char *tab[] = {cmd, filename};

    for (int j = 1; ; j++, str = NULL) {
        if (b == NULL || c == NULL)
            return 84;
        file_creator(path, tab, env, env_l);
        return 0;
    }
    return 0;
}