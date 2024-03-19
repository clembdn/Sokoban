/*
** EPITECH PROJECT, 2023
** settingup.c
** File description:
** xy
*/

#include "../include/sokoban.h"

static int is_player(char player)
{
    return player == 'P';
}

static int is_dot(char dot)
{
    return dot == 'O';
}

static pos_t get_player_position_in_row(char *row, int row_index)
{
    pos_t xy;

    for (int j = 0; row[j] != '\0'; j++) {
        if (is_player(row[j])) {
            xy.x = row_index;
            xy.y = j;
            return xy;
        }
    }
    return xy;
}

pos_t get_pos(char **tab)
{
    pos_t xy;

    for (int i = 0; tab[i] != NULL; i++) {
        xy = get_player_position_in_row(tab[i], i);
    }
    return xy;
}

int count_dots(char **tab)
{
    int dots = 0;
    int j;

    for (int i = 0; tab[i] != NULL; i++) {
        j = 0;
        while (tab[i][j] != '\0') {
            dots += is_dot(tab[i][j]);
            j++;
        }
    }
    return dots;
}

static void add_coord2(int i, pos_t *posdot, int *k, char **tab)
{
    for (int j = 0; tab[i][j] != '\0'; j++) {
        if (tab[i][j] == 'O') {
            posdot[*k].x = i;
            posdot[*k].y = j;
            (*k)++;
        }
    }
}

pos_t *add_coord(char **tab)
{
    int k = 0;
    pos_t *posdot = malloc(sizeof(pos_t) * count_dots(tab) + 1);

    if (posdot == NULL)
        return NULL;
    for (int i = 0; tab[i] != NULL; i++)
        add_coord2(i, posdot, &k, tab);
    posdot[k].x = 2000;
    posdot[k].y = 2000;
    return posdot;
}

int check_spot(char **tab, pos_t *posdot)
{
    int i = 0;

    for (int k = 0; posdot[k].x < 2000; k++) {
        if (tab[posdot[k].x][posdot[k].y] == ' ')
            tab[posdot[k].x][posdot[k].y] = 'O';
        if (tab[posdot[k].x][posdot[k].y] == 'O'
            || tab[posdot[k].x][posdot[k].y] == 'P')
                i = 1;
    }
    if (i == 1)
        return 1;
    return 0;
}
