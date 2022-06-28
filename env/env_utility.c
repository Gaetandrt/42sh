/*
** EPITECH PROJECT, 2022
** function for env commands
** File description:
** env_functions
*/

#include "42.h"

void print_list(node **head)
{
    node *tmp = *head;

    while (tmp != NULL) {
        my_putstr(tmp->name);
        my_putstr(tmp->value);
        my_putchar('\n');
        tmp = tmp->next;
    }
}

char *getenv_value(char *env)
{
    int i = 0;
    int n = 0;
    char *value = malloc(sizeof(char) * my_strlen(env) + 1);

    while (env[i] != '=' && env[i] != '\0')
        i++;
    i++;
    while (env[i] != '\0') {
        value[n] = env[i];
        i++;
        n++;
    }
    value[n] = '\0';
    return (value);
}

char *getenv_name(char *env)
{
    char *name = malloc(sizeof(char) * my_strlen(env) + 1);
    int i = 0;

    while (env[i] != '=' && env[i] != '\0') {
        name[i] = env[i];
        i++;
    }
    name[i] = '=';
    name[i + 1] = '\0';
    return (name);
}

void add_node_back2(node **head, char *env)
{
    node *newnode = malloc(sizeof(node));
    node *tmp;

    newnode->next = NULL;
    newnode->name = getenv_name(env);
    newnode->value = getenv_value(env);
    tmp = *head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = newnode;
}

node *init_env(char **env)
{
    if (env == NULL)
        exit(84);
    node *head = malloc(sizeof(node));
    head->name = getenv_name(env[0]);
    head->value = getenv_value(env[0]);
    head->next = NULL;
    head->ret = 0;

    for (int i = 1; i < my_arraylen(env); i++) {
        add_node_back2(&head, env[i]);
    }
    return (head);
}
