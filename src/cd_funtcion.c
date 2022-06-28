/*
** EPITECH PROJECT, 2022
** handle cd command
** File description:
** cd_funtcion
*/

#include "42.h"

char *directory_name_find(char *pwd)
{
    int i = 0;

    while (pwd[i] != '\0') {
        if (pwd[i] == '/')
            return (pwd + i + 1);
        i++;
    }
    return (pwd);
}

char *home_find(char **env)
{
    if (my_strncmp(*env, "HOME=", 4) == 0) {
        return (*env + 5);
    }
    return (home_find(env + 1));
}

void cd_function_bis(char **buf, char *pwd, node **env_l)
{
    char *tmp;

    if (buf[1][0] != '/') {
        tmp = my_strcat(pwd, "/");
        int i = chdir(path_concatenate(buf, pwd));
        if (i != 0)
            my_putstr(my_strcat(buf[1], ": No such file or directory.\n"));
        else
            set_oldpwd(tmp, env_l);
    } else {
        tmp = my_strcat(pwd, "/");
        int i = chdir(my_strcat(pwd, buf[1]));
        if (i != 0)
            my_putstr(my_strcat(buf[1], ": No such file or directory.\n"));
        else
            set_oldpwd(tmp, env_l);
    }
}

void cd_function(char **buf, char *pwd, char **env, node **env_l)
{
    if (my_arraylen(buf) > 2) {
        my_putstr("cd: Too many arguments.\n");
        return;
    }
    if (my_arraylen(buf) == 1) {
        chdir(home_find(env));
        return;
    }
    if (buf[1][0] == '~') {
        int i = chdir(home_find(env));
        if (i != 0)
            my_putstr(my_strcat(buf[1], ": No such file or directory.\n"));
    }
    if (buf[1][0] == '-') {
        int i = chdir(find_old(env_l));
        if (i != 0)
            my_putstr(my_strcat(buf[1], ": No such file or directory.\n"));
    } else {
        cd_function_bis(buf, pwd, env_l);
    }
}
