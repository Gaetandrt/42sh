/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** my_strtowordaray
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int my_strlen(char const *str);

int count_space_bis(char *str)
{
    int i = 0;

    while (str[i] == ':') {
        i++;
    }
    return (i);
}

char **path_init(char *str, int cpt, int j, int x)
{
    char **result = malloc(sizeof(char *) * cpt);

    for (int i = 0; i < cpt; i++)
        result[i] = malloc(sizeof(char) * my_strlen(str));
    for (int i = 0; str[i] != '\0'; i++) {
        result[j][x] = str[i];
        x++;
        if (str[i + 1] == '\0') {
            result[j][x] = '\0';
        } else if (str[i] == ':') {
            result[j][x - 1] = '\0';
            i += count_space_bis(str + i) - 1;
            j++;
            x = 0;
        }
    }
    result[cpt - 1] = NULL;
    return (result);
}

char **my_path_to_word_array(char *str)
{
    int cpt = 2;
    int j = 0;
    int x = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ':')
            cpt++;
    }
    return (path_init(str, cpt, j, x));
}
