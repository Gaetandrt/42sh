/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-rayan.lebec
** File description:
** left_redir
*/

#include "42.h"

int left_redir(char **path, char *str, char **env, node **env_l)
{
    char *separator = "<";
    char *a = strtok(str, separator);
    char *b = strtok(NULL, "");
    char *x = s_eraser(a);
    char *y = s_eraser(b);
    char *z = s_eraser(y);
    int fd = open(z, O_RDONLY);

    if (y == NULL) {
        my_putstr("Missing name for redirect.\n");
        return 84;
    }
    if (fd == -1) {
        my_putstr(z);
        my_putstr(": Aucun fichier ou dossier de ce type.\n");
        return 84;
    }
    command_management(path, x, env, &env_l);
    return 0;
}