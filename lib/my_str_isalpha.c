/*
** EPITECH PROJECT, 2021
** my_str_isalpha
** File description:
** my strisalpha
*/

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 48 || str[i] > 57) && (str[i] < 65 || str[i] > 90) \
        && (str[i] < 97 || str[i] > 122))
            return (1);
    }
    return (0);
}
