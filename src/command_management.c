/*
** EPITECH PROJECT, 2022
** manage the command is simple or with pipe ect
** File description:
** command_management
*/

#include "42.h"

int check_str(char **tab, char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (tab[i] != NULL) {
        j = 0;
        while (tab[i][j] != '\0') {
            if (tab[0][0] == str[0])
                return 0;
            if (tab[i][j] == str[k]) {
                k++;
                j++;
            } else {
                k = 0;
                j++;
            }
            if (k == my_strlen(str))
                return (i);
        }
        i++;
    }
    return (-1);
}

int check_sep(char **tab, char delim)
{
    for (int i = 0; tab[i] != NULL; i++)
        for (int j = 0; tab[i][j] != '\0'; j++) {
            if (tab[0][0] == delim)
                return (0);
            if (tab[i][j] == delim)
                return (1);
        }
    return (-1);
}

int doubleesp(char **path, char *buffer, char **env, node **env_l)
{
    node *head = *env_l;
    char *separator = "&&";
    char *a = strtok(buffer, separator);
    char *b = strtok(NULL, "");
    b = earse_first(b);
    char *x = s_eraser(a);
    char *y = s_eraser(b);
    char *tab[] = {x, y, NULL};

    if (strlen(y) < 2 || y == NULL) {
        printf("Invalid null command.\n");
        return (0);
    }
    for (int i = 0; tab[i] != NULL; i++) {
        command_management(path, tab[i], env, env_l);
        if (head->ret == 1) {
            head->ret = 0;
            return (1);
        }
    }
    return 0;
}

void command_management_bis(char **path, char *buffer, char **env, node **env_l)
{
    if (check_sep(str_to_word_array(buffer), ';') > 0)
        command_start(path, my_str_to_word_array(buffer, ';'), env, &env_l);
    else if (check_sep(str_to_word_array(buffer), '|') > 0)
        filter_pipe(path, my_str_to_word_array(buffer, '|'), env, &env_l);
    else if (check_sep(str_to_word_array(buffer), '>') > 0) {
        redirector(path, buffer, env, &env_l);
        return;
    }
    else if (check_sep(str_to_word_array(buffer), '<') > 0) {
        left_redir(path, buffer, env, &env_l);
        return;
    }
    else
        command_pars(path, str_to_word_array(buffer), env, env_l);
}

void command_management(char **path, char *buffer, char **env, node **env_l)
{
    if (check_str(str_to_word_array(buffer), ">>") > 0) {
        doubleredirector(path, buffer, env, env_l);
        return;
    }
    else if (check_str(str_to_word_array(buffer), "<<") > 0) {
        doubleleft(path, buffer, env, env_l);
        return;
    }
    else if (check_str(str_to_word_array(buffer), "&&") > 0) {
        doubleesp(path, buffer, env, env_l);
        return;
    }
    else if (check_str(str_to_word_array(buffer), "||") > 0) {
        doublepipe(path, buffer, env, env_l);
        return;
    }
    else
        command_management_bis(path, buffer, env, env_l);
}
