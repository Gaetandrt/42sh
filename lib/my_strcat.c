/*
** EPITECH PROJECT, 2022
** my_strcat function, concatenate 2 strings
** File description:
** my_strcat
*/

#include <stdio.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char *src)
{
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);
    char *result = malloc(sizeof(char) * (dest_len + src_len) + 1);
    int i = 0;

    while (i < (dest_len)) {
        result[i] = dest[i];
        i++;
    }
    for (int j = 0; i < (dest_len + src_len); j++) {
        result[i] = src[j];
        i++;
    }
    result[i] = '\0';
    return (result);
}
