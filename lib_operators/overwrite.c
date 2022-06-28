/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-rayan.lebec
** File description:
** overwrite
*/

#include "42.h"

int overwrite(char **path, char **tab, char **env, node **env_l)
{
    int filefd = open(tab[1], O_WRONLY|O_CREAT | O_APPEND, 0666);

    if (!fork()) {
        close(1);
        dup(filefd);
        command_management(path, tab[0], env, &env_l);
    }
    else {
        close(filefd);
    }
    close(filefd);
    return 0;
}

void command_start(char **path, char **buffer, char **env, node **env_l)
{
    for (int i = 0; buffer[i] != NULL; i++) {
        buffer[i] = s_eraser(buffer[i]);
        command_management(path, buffer[i], env, env_l);
    }
}
