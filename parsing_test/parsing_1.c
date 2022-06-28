/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-42sh-rayan.lebec
** File description:
** parsing_1
*/

#include "42.h"

void add_node_back(char *str, int i, int n, sep_node **head)
{
    sep_node *newnode = malloc(sizeof(sep_node));
    sep_node *tmp;

    newnode->next = NULL;
    if (n == 1) {
        newnode->op = strndup(str + i, 1);
        newnode->pos = i;
    } else {
        newnode->op = strndup(str + i, 2);
        newnode->pos = i;
    }
    tmp = *head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = newnode;
}

int count_sep(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i + 1] == '\0')
            break;
        if (str[i] == ';' || (str[i] == '>' && str[i + 1] != \
        '>') || (str[i] == '<' && str[i + 1] != '<') || (str[i] == '&' && \
        str[i + 1] != '&') || (str[i] == '|' && str[i + 1] != '|')) {
            count++;
        }
        i++;
    }
    return (count);
}

int check_if_sep(char *str, sep_node **head)
{
    for (int i = 0; str[i + 1] != '\0'; i++) {
        if (is_separator(str[i], str[i + 1]) == 1) {
            add_node_back(str, i, 1, head);
        }
        if (is_separator(str[i], str[i + 1]) == 2) {
            add_node_back(str, i, 2, head);
            i++;
        }
    }
    return (0);
}

void print_list(sep_node **head)
{
    sep_node *tmp = *head;
    tmp = tmp->next;

    while (tmp != NULL) {
        printf("operator = %s\n", tmp->op);
        printf("pos = %d\n", tmp->pos);
        printf("\n\n");
        tmp = tmp->next;
    }
}

int parsing_1(char *cmd, mysh_t *mysh)
{
    sep_node *node = malloc(sizeof(sep_node));
    char **cmd_sorted;

    node->next = NULL;
    node->op = '\0';
    node->pos = 0;
    check_if_sep(cmd, &node);
    cmd_sorted = sort_cmd(cmd, &node, mysh);
    return (0);
}
