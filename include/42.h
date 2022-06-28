/*
** EPITECH PROJECT, 2022
** minishell 1 header file
** File description:
** minishell1
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef MINISHELl1_H_
    #define MINISHELl1_H_
    #define UNUSED __attribute__((unused))

typedef struct cmd {
    char **buf;
    char *cmd;
    struct cmd *next;
} cmd;

typedef struct node {
    char *name;
    char *value;
    int ret;
    char *buf;
    struct node *next;
} node;

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

int my_getnbr(char const *str);
node *init_env(char **env);
void print_list(node **head);
void setenv_function(node **env_l, char **av);
void unsetenv_function(node **env_l, char **av);
char **my_path_to_word_array(char *str);
char **my_str_to_word_array(char *str, char delim);
char **str_to_word_array(char *str);
void command_start(char **path, char **buffer, char **env, node **env_l);
int my_strlen(char const *str);
char *my_strncpy(char *dest , char const *src, int n);
void command_test(char **buf, char **path, char **env, node **env_l);
char *my_strcat(char *dest, char *src);
int line_count(char *src);
char **path_parse(char *src);
char *find_path(char **env);
char *path_concatenate(char **buf, char *pwd);
char *find_old(node **head);
void cd_function(char **buf, char *pwd, char **env, node **env_l);
void env_command_parse(node **env_l, char **buf);
void my_putstr(char const *str);
int my_aos_parse(char **array, char c);
void command_management(char **path, char *buffer, char **env, node **env_l);
void command_pars(char **path, char **buf, char **env, node **env_l);
int my_strcmp(char *s1, char *s2);
char *home_find(char **env);
int my_strncmp(char *s1, char *s2, int x);
void set_oldpwd(char *pwd, node **head);
void my_putchar(char c);
int my_arraylen(char **av);
int my_str_isalpha(char const *str);
int command_execve(char **buf, char *command, char **env);
void add_node_back(char *str, int i, int n, sep_node **head);
int is_separator(char c, char c2);

// FONCTION REMI

int filter_pipe(char **path, char **tab, char **env, node **env_l);
int my_pipe(char **path, char **tab, char **env, node **env_l);
void doubleleft(char **path, char *str, char **env, node **env_l);
int doubleredirector(char **path, char *str, char **env, node **env_l);
int left_redir(char **path, char *str, char **env, node **env_l);
int file_creator(char **path, char **tab, char **env, node **env_l);
int redirector(char **path, char *str, char **env, node **env_l);
int my_comma(char **path, char **buf, char **env, node **env_l);
int splitop(char *str, char **env, node *head);
char *s_eraser(char *str);
int is_op(char *str);
int is_char(char *str, char c);
int nb_char(char *str, char c);
char *erase_delim(char *str, char c);
int counter_nbchar(char v, char c);
int my_strlen(char const *str);
char *before_char(char *str, char *c);
char *earse_first(char *str);
void printab(char **tab);
int doubleesp(char **path, char *buffer, char **env, node **env_l);
int doublepipe(char **path, char *buffer, char **env, node **env_l);
int overwrite(char **path, char **tab, char **env, node **env_l);
int redirector(char **path, char *str, char **env, node **env_l);
int left_redir(char **path, char *str, char **env, node **env_l);
int doubleredirector(char **path, char *str, char **env, node **env_l);
void doubleleft(char **path, char *str, char **env, node **env_l);
void command_start(char **path, char **buffer, char **env, node **env_l);
int execute_doubleleft(char **path, char **tab, char **env, node **env_l);

#endif /* !MINISHELl1_H_ */
