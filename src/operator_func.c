/*
** EPITECH PROJECT, 2022
** operator func
** File description:
** minishell2
*/

#include "42.h"

char *s_eraser(char *str)
{
    int len = my_strlen(str);
    if (str[len - 1] == 32)
        str[len - 1] = '\0';
    if (str[0] == 32)
        for (int i = 0; str[i] != '\0'; i++)
            str[i] = str[i + 1];
    return str;
}

int is_op(char *str)
{
    int a = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ';' || str[i] == '|' || str[i] == '<' || str[i] == '>')
            a++;
    return a;
}

int is_char(char *str, char c)
{
    while (*str) {
        if (*str == c)
            return 0;
        str++;
    }

    return 1;
}

int nb_char(char *str, char c)
{
    int a = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            a++;
    return a;
}

char *before_char(char *str, char *c)
{
    char *new = strtok(str, c);
    return new;
}