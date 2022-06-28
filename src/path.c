/*
** EPITECH PROJECT, 2022
** all path funtcion
** File description:
** path
*/

#include "42.h"

char *find_old(node **head)
{
    node *tmp = *head;

    while (tmp->next != NULL) {
        if (my_strncmp(tmp->name, "OLDPWD=", 6) == 0)
            return (tmp->value);
        tmp = tmp->next;
    }
    exit (84);
}

char *path_concatenate(char **buf, char *pwd)
{
    pwd = my_strcat(my_strcat(pwd, "/"), buf[1]);
    return (pwd);
}

char **path_parse(char *src)
{
    char **path = malloc(sizeof(char *) * line_count(src) + 1);

    for (int i = 0; i < line_count(src); i++)
        path[i] = malloc(sizeof(char) * 100);
    path = my_path_to_word_array(src);
    return (path);
}

char *find_path(char **env)
{
    if (my_strncmp(*env, "PATH=", 5) == 0)
        return (*env + 5);
    if (env == NULL)
        return (*env);
    return (find_path(env + 1));
}
