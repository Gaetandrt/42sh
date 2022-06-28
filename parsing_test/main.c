/*
** EPITECH PROJECT, 2022
** parsing test
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

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

char **str_to_word_array(char *str, char delim)
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
    return (tab);
}


int maintest(int ac, char **av)
{
    char *cmd = av[1];

    mysh_t *mysh = malloc(sizeof(mysh_t));
    mysh->path = my_path_to_word_array("PATH=/home/remi/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/usr/lib/jvm/java-17-oracle/bin:/usr/lib/jvm/java-17-oracle/db/bin");
    parsing_1(cmd, mysh);
}
