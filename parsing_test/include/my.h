/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-minishell2-gaetan.darrort [WSL : Ubuntu]
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>

typedef struct mysh_s {
    char **path;
    char **env;
    char *cmd;
} mysh_t;

typedef struct sep_node {
    char *op;
    int pos;
    struct sep_node *next;
} sep_node;

int count_sep(char *str);
int parsing_1(char *cmd, mysh_t *mysh);
char **my_path_to_word_array(char *str);
int error_handling(sep_node **head, mysh_t *mysh);
void add_node_back(char *str, int i, int n, sep_node **head);

#endif /* !MY_H_ */
