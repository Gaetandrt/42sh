/*
** EPITECH PROJECT, 2022
** function for env command
** File description:
** env_functions
*/

#include "42.h"

void unsetenv_function(node **env_l, char **av)
{
    node *tmp = *env_l;
    node *prev = NULL;

    while (tmp != NULL) {
        if (my_strncmp(tmp->name, av[1], my_strlen(av[1])) == 0) {
            if (prev == NULL) {
                *env_l = tmp->next;
                return;
            }
            tmp = prev;
            tmp->next = tmp->next->next;
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}

void setenv_function(node **env_l, char **av)
{
    node *newnode = malloc(sizeof(node));
    node *tmp = *env_l;

    if (my_str_isalpha(av[1]) == 1) {
        my_putstr("setenv: Variable name must contain alphanumeric");
        my_putstr("characters.\n");
        return;
    }
    newnode->next = NULL;
    newnode->name = my_strcat(av[1], "=");
    newnode->value = av[2];
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = newnode;
}

int set_oldpwd_bis(node *tmp)
{
    if (my_strncmp(tmp->name, "OLDPWD=", 6) == 0) {
        if (tmp->value == NULL)
            return (2);
        else
            return (1);
    }
    return (0);
}

void set_oldpwd(char *pwd, node **head)
{
    node *tmp = *head;

    while (tmp->next != NULL) {
        if (set_oldpwd_bis(tmp) == 1) {
            tmp->value = pwd;
            return;
        }
        if (set_oldpwd_bis(tmp) == 2)
            return;
        tmp = tmp->next;
    }
}

void env_command_parse(node **env_l, char **buf)
{
    if (my_strcmp(buf[0], "setenv") == 0) {
        if (my_arraylen(buf) < 3) {
            my_putstr("setenv: Too few arguments.\n");
            return;
        } else {
            setenv_function(env_l, buf);
            return;
        }
    }
    if (my_strcmp(buf[0], "unsetenv") == 0) {
        if (my_arraylen(buf) < 2) {
            my_putstr("unsetenv: Too few arguments.\n");
            return;
        } else {
            unsetenv_function(env_l, buf);
            return;
        }
    } else
        print_list(env_l);
}
