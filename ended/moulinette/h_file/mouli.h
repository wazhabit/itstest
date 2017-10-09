#ifndef MOULI_H_
#define MOULI_H_

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>

DIR* open_directory(const char *path);
char **my_wordtab(char **tab, char *s, char c);

char *files_status(DIR* open, char **syntaxe, char *direct);
char *my_add_str_to_str(char *s1, char *s2);

int start_function(char **argv);
int it_is_a_real_char(char c);
int it_is_a_real_name(char *s);
int my_strlen(char *s);
int my_count_char_in_str(char c, char *str);
int my_putnbr(int nb);
int my_tablen(char **t);
int my_strcmp(char *s1, char *s2);

void say_me_the_syntaxe_plz();
void my_putchar(char c);
void my_putstr(char *str);
void my_puttab(char **tab);
void prepare_tab(char *s, char c, char ***tab);

#endif
