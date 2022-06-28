/*
** EPITECH PROJECT, 2022
** error handling for all separator
** File description:
** error_handling
*/

#include "my.h"

int error_handling(sep_node **head, mysh_t *mysh)
{
    sep_node *tmp = *head;

    tmp = tmp->next;
    while (tmp->next != NULL) {
        if (strcmp(tmp->op, ";") == 0) {
        }
        if (strcmp(tmp->op, ">") == 0) {
        }
        if (strcmp(tmp->op, "<") == 0) {
        }
        if (strcmp(tmp->op, "|") == 0) {
        }
        if (strcmp(tmp->op, "&") == 0) {
        }
        if (strcmp(tmp->op, "&&") == 0) {
        }
        if (strcmp(tmp->op, "||") == 0) {
        }
        if (strcmp(tmp->op, "<<") == 0) {
        }
        if (strcmp(tmp->op, ">>") == 0) {
        }
        tmp = tmp->next;
    }
}
