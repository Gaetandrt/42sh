/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** use the fonction write to print a caractere one by one
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
