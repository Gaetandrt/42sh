/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** my_strtowordaray
*/

#include <stdlib.h>
#include <stdio.h>

char **my_str_to_word_array(char *str, char delim)
{
    char **tab = malloc(sizeof(char *) * (my_strlen(str) + 1));
    int i = 0;
    int j = 0;
    int k = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == delim) {
            tab[j] = malloc(sizeof(char) * (k + 1));
            for (int l = 0; l < k; l++)
                tab[j][l] = str[i - k + l];
            tab[j][k] = '\0';
            j++;
            k = 0;
        } else
            k++;
    }
    tab[j] = malloc(sizeof(char) * (k + 1));
    for (int l = 0; l < k; l++)
        tab[j][l] = str[i - k + l];
    tab[j][k] = '\0';
    tab[j + 1] = NULL;
    return (tab);
}
