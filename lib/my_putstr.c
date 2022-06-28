/*
** EPITECH PROJECT, 2021
** Day04
** File description:
** Task02
*/

#include <unistd.h>

void my_putchar(char c);

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i += 1;
    }
}
