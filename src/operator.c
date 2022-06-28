/*
** EPITECH PROJECT, 2022
** operator
** File description:
** minishell2
*/

#include "42.h"

int my_pipe(char **path, char **tab, char **env, node **env_l)
{
    int pfd[2];
    int pid;

    if (pipe(pfd) == -1)
        return 84;
    if ((pid = fork()) < 0)
        return 84;
    if (pid == 0) {
        close(pfd[1]);
        dup2(pfd[0], 0);
        close(pfd[0]);
        command_management(path, tab[1], env, &env_l);
        return 0;
    }
    else {
        close(pfd[0]);
        dup2(pfd[1], 1);
        close(pfd[1]);
        command_management(path, tab[0], env, &env_l);
        return 0;
    }
    return 0;
}

int filter_pipe(char **path, char **tab, char **env, node **env_l)
{
    tab[0] = s_eraser(tab[0]);
    tab[1] = s_eraser(tab[1]);
    if (tab[0] == NULL || tab[1] == NULL) {
        my_putstr("Inavlid null command.\n");
        return 84;
    }
    my_pipe(path, tab, env, env_l);
    return 0;
}

int isattydouble(char **path, char **tab, char **env, node **env_l)
{
    node *head = *env_l;
    if (strcmp(tab[1], head->buf) != 0) {
        return 1;
    }
    else
        command_management(path, tab[0], env, &env_l);
    return 0;
}

int execute_doubleleft(char **path, char **tab, char **env, node **env_l)
{
    node *head = *env_l;
    size_t bufsize = 32;
    size_t characters;
    char *buffer = malloc(sizeof(char) *bufsize);

    if (buffer == NULL)
        execute_doubleleft(path, tab, env, env_l);
    if (isatty(0) == 0) {
        head->buf = buffer;
        isattydouble(path, tab, env, env_l);
        return 0;
    }
    my_putstr("? ");
    characters = getline(&buffer, &bufsize, stdin);
    buffer[characters - 1] = 0;
    if (strcmp(buffer, tab[1]) != 0) {
        execute_doubleleft(path, tab, env, env_l);
    } else {
        command_management(path, tab[0], env, &env_l);
    }
    return 0;
}

int doublepipe(char **path, char *buffer, char **env, node **env_l)
{
    node *head = *env_l;
    char *separator = "||";
    char *a = strtok(buffer, separator);
    char *b = strtok(NULL, "");
    b = earse_first(b);
    char *x = s_eraser(a);
    char *y = s_eraser(b);
    char *tab[] = {x, y, NULL};

    for (int i = 0; tab[i] != NULL; i++) {
        command_management(path, tab[i], env, env_l);
        if (head->ret == 0) {
            head->ret = 0;
            return (1);
        }
    }
    return 0;
}
