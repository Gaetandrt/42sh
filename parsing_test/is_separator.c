/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-rayan.lebec
** File description:
** add_node
*/

#include "42.h"

int is_separator(char c, char c2)
{
    if (c == ';' || (c == '>' && c2 != '>') || (c == '<' && c2 !=  \
    '<') || (c == '|' && c2 != '|') || (c == '&' && c2 != '&')) {
        return (1);
    }
    if ((c == '&' && c2 == '&') || (c == '>' && c2 == '>') || (c == '|' && \
    c2 == '|') || (c == '<' && c2 == '<')) {
        return (2);
    }
    return (0);
}