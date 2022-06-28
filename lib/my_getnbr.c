/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** my get number
*/

#include <unistd.h>

int my_getnbr_long(char const *str)
{
    int signe = 1;
    int resultat = 0;

    while (*str < '0' || *str > '9') {
        str++;
    }
    while ('-' == *str || '+' == *str) {
        if (*str == '-') {
            signe = signe * -1;
        }
        str++;
    }
    while (*str >= '0' && *str <= '9') {
        resultat = resultat * 10 + *str - '0';
        str++;
    }
    return (resultat * signe);
}

int my_getnbr(char const *str)
{
    int signe = 1;
    int resultat = 0;

    while ('-' == *str || '+' == *str) {
        if (*str == '-') {
            signe = signe * -1;
        }
        str++;
    }
    while (*str >= '0' && *str <= '9') {
        resultat = resultat * 10 + *str - '0';
        str++;
    }
    return (resultat * signe);
}
