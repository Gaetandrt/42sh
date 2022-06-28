/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-rayan.lebec
** File description:
** file_creator
*/

#include "42.h"

int file_creator(char **path, char **tab, char **env, node **env_l)
{
    int filefd = open(tab[1], O_WRONLY|O_CREAT, 0666);

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