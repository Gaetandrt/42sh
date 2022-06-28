/*
** EPITECH PROJECT, 2022
** strncmp function
** File description:
** my_strncmp
*/

int my_strncmp(char *s1, char *s2, int x)
{
    int i = 0;

    while (i < x) {
        if (s1[i] != s2[i])
            return (-1);
        i++;
    }
    return (0);
}
