/*
** EPITECH PROJECT, 2021
** my_strcpy.c
** File description:
** mystrcpy
*/

void my_putchar(char ch);

char *my_strncpy(char *dest , char const *src, int n)
{
    int i = 0;
    
    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    if (n == i) {
        dest[i] = '\0';
    }
    return (dest);
}
