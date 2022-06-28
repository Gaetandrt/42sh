/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-rayan.lebec
** File description:
** double_redirector
*/

#include "42.h"

int doubleredirector(char **path, char *str, char **env, node **env_l)
{
    char *separator = ">>";
    char *b = strtok(str, separator);
    char *c = strtok(NULL, "");
    c = earse_first(c);
    char *cmd = s_eraser(b);
    char *filename = s_eraser(c);
    char *tab[] = {cmd, filename};

    for (int j = 1; ; j++, str = NULL) {
        if (b == NULL || c == NULL)
            return 84;
        overwrite(path, tab, env, env_l);
        return 0;
    }
    return 0;
}