/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** day9 task2
*/

#ifndef MY_
    #define MY_
    #include "sokoban.h"

int nbr_col(char *str);
int nbr_row(char *str);
int lenmap(char **tab);
char **str_to_tab(char *str);
void validsize(char *str, char **tab);

int terrain_display(char **tab, char *path);
void lose_screen(char **tab, char *path);
void win_screen(char **tab, char *path);
pos_t loop_screen(char **tab, char *path, pos_t xy);

int	count_x(char **tab, char *path);
int	check_lose(char **tab, char *path);
int	check_boxes(char **tab, int x, int y);

pos_t check_pos_mvt(char **tab, pos_t xy, char *path);
pos_t move_right(char **tab, pos_t xy);
pos_t move_left(char **tab, pos_t xy);
pos_t move_up(char **tab, pos_t xy);
pos_t move_down(char **tab, pos_t xy);

pos_t get_pos(char **tab);
int	nb_of_dots(char **tab);
pos_t *add_coord(char **tab);
int check_spot(char **tab, pos_t *posdot);

int my_strlen( char const *str);

#endif
