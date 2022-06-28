/*
** EPITECH PROJECT, 2022
** main file of minishell_1 project.
** File description:
** main
*/

#include "42.h"

void command_pars_bis(char **path, char **buf, char **env, node **env_l)
{
    if (my_strcmp(buf[0], "env") == 0 || my_strcmp(buf[0], "setenv") == 0 \
    || my_strcmp(buf[0], "unsetenv") == 0) {
        env_command_parse(env_l, buf);
        return;
    } else
        command_test(buf, path, env, env_l);
}

void command_pars(char **path, char **buf, char **env, node **env_l)
{
    char pwd[1024];
    getcwd(pwd, sizeof(pwd));

    if (my_strcmp(buf[0], "exit") == 0) {
            if (buf[1] == NULL)
                exit(0);
            else
                exit(my_getnbr(buf[1]));
    }
    if (my_strcmp(buf[0], "pwd") == 0) {
        my_putstr(pwd);
        my_putchar('\n');
    } else if (my_strcmp(buf[0], "cd") == 0) {
        if (my_arraylen(buf) > 2) {
            my_putstr("cd: Too many arguments.\n");
            return;
        }
        if (my_arraylen(buf) == 1) {
            chdir(home_find(env));
            return;
        }
        cd_function(buf, pwd, env, env_l);
    } else
        command_pars_bis(path, buf, env, env_l);
}

char *buffer_init(char *buffer)
{
    buffer[my_strlen(buffer) - 1] = '\0';
    return (buffer);
}

void getprompt(void)
{
    if (isatty(0) == 0)
        return;
    my_putstr("$> ");
}

int main(int ac, char **av, char **env)
{
    (void) ac;
    (void) av;
    node *env_l = init_env(env);
    size_t buf_size = 512;
    char *buffer = malloc(sizeof(char) * 512);
    char **path;

    path = path_parse(find_path(env));
    getprompt();
    while (getline(&buffer, &buf_size, stdin) != -1) {
        if (buffer[strlen(buffer) - 1] == '\n')
            buffer[strlen(buffer) - 1] = '\0';
        command_management(path, buffer, env, &env_l);
        getprompt();
    }
    return (0);
}
