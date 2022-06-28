/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** my_strtowordaray
*/

#include "42.h"

int my_strlen(char const *str);

int count_space(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            break;
        i++;
    }
    return (i);
}

int count_word(char *str)
{
    int cpt = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            break;
        i++;
    }
    while (str[i] != '\0') {
        if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && (str[i + 1] \
        != ' ' && str[i + 1] != '\t' && str[i + 1] != '\n'))
            cpt++;
        i++;
    }
    return (cpt);
}

char **my_str_to_word_array_end(char **result, int y)
{
    result[y] = NULL;
    return (result);
}

char **my_str_to_word_array_bis(char *str)
{
    char **result = malloc(sizeof(char *) * (count_word(str) + 1));
    int i = 0;
    int y = 0;
    int x = 0;

    for (int i = 0; i <= count_word(str); i++)
        result[i] = malloc(sizeof(char) * (my_strlen(str) + 1));
    while (str[i] != '\0') {
        while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] \
        != '\n') {
            result[y][x] = str[i];
            i++;
            x++;
        }
        result[y][x] = '\0';
        x = 0;
        y++;
        i += count_space(str + i);
    }
    return (my_str_to_word_array_end(result, y));
}

char **str_to_word_array(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            break;
        i++;
    }
    return (my_str_to_word_array_bis(str + i));
}