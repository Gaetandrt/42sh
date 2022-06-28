/*
** EPITECH PROJECT, 2022
** command execution part
** File description:
** command_execve
*/

#include "42.h"

char *cmd_flags(char *path, char **command);

int command_execve(char **buf, char *command, char **env)
{
    int pidwaiter;
    pid_t pid;
    pid = fork();
    if (pid < 0)
        return (84);
    if (pid == 0)
        execve(command, buf, env);
    else
        waitpid(pid, &pidwaiter, 0);
    return 0;
}

char *cmd_path(char *path, char *command)
{
    char *result = NULL;

    result = my_strcat(my_strcat(path, "/"), command);
    return (result);
}

char *path_test(char **buf, char **path, char **env)
{
    if (path == NULL)
        return ("not found");
    if (access(cmd_path(*path, buf[0]), F_OK | X_OK) == 0) {
        return (cmd_path(*path, buf[0]));
    } else
        return (path_test(buf, path + 1, env));
}

void command_test(char **buf, char **path, char **env, node **env_l)
{
    node *head = *env_l;
    int i = 0;
    int path_len = my_arraylen(path) - 1;

    while (access(cmd_path(path[i], buf[0]), F_OK | X_OK) != 0) {
        if (i == path_len) {
            my_putstr(my_strcat(buf[0], ": Command not found.\n"));
            head->ret = 1;
            return;
        }
        i++;
    }
    command_execve(buf, cmd_path(path[i], buf[0]), env);
}
