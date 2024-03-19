/*
** EPITECH PROJECT, 2023
** settingup.c
** File description:
** moove
*/

#include "../include/my.h"

pos_t check_pos_mvt(char **tab, pos_t xy, char *path)
{
    int touch;
    int move;

    keypad(stdscr, TRUE);
    touch = getch();
    if (touch == KEY_UP)
        xy = move_up(tab, xy);
    if (touch == KEY_DOWN)
        xy = move_down(tab, xy);
    if (touch == KEY_LEFT)
        xy = move_left(tab, xy);
    if (touch == KEY_RIGHT)
        xy = move_right(tab, xy);
    if (touch == ' ')
        terrain_display(str_to_tab(path), path);
    if (touch == 'q')
        win_screen(tab, path);
    return xy;
}

pos_t move_right(char **tab, pos_t xy)
{
    if (tab[xy.x][xy.y + 1] != '#' && tab[xy.x][xy.y + 1] != 'X'
        && tab[xy.x][xy.y] == 'P') {
            tab[xy.x][xy.y] = ' ';
            tab[xy.x][xy.y + 1] = 'P';
            xy = get_pos(tab);
    } else if (tab[xy.x][xy.y + 1] == 'X' && tab[xy.x][xy.y + 2] != '#'
        && tab[xy.x][xy.y + 2] != 'X' && tab[xy.x][xy.y] == 'P') {
            tab[xy.x][xy.y] = ' ';
            tab[xy.x][xy.y + 1] = 'P';
            tab[xy.x][xy.y + 2] = 'X';
            xy = get_pos(tab);
    }
    return xy;
}

pos_t move_left(char **tab, pos_t xy)
{
    if (tab[xy.x][xy.y - 1] != '#' && tab[xy.x][xy.y - 1] != 'X'
        && tab[xy.x][xy.y] == 'P') {
            tab[xy.x][xy.y] = ' ';
            tab[xy.x][xy.y - 1] = 'P';
            xy = get_pos(tab);
    } else if (tab[xy.x][xy.y - 1] == 'X' && tab[xy.x][xy.y - 2] != '#'
        && tab[xy.x][xy.y - 2] != 'X' && tab[xy.x][xy.y] == 'P') {
            tab[xy.x][xy.y] = ' ';
            tab[xy.x][xy.y - 1] = 'P';
            tab[xy.x][xy.y - 2] = 'X';
            xy = get_pos(tab);
    }
    return xy;
}

pos_t move_up(char **tab, pos_t xy)
{
    if (tab[xy.x - 1][xy.y] != '#' && tab[xy.x - 1][xy.y] != 'X'
        && tab[xy.x][xy.y] == 'P') {
            tab[xy.x][xy.y] = ' ';
            tab[xy.x - 1][xy.y] = 'P';
            xy = get_pos(tab);
    } else if (tab[xy.x - 1][xy.y] == 'X' && tab[xy.x - 2][xy.y] != '#'
        && tab[xy.x - 2][xy.y] != 'X' && tab[xy.x][xy.y] == 'P') {
            tab[xy.x][xy.y] = ' ';
            tab[xy.x - 1][xy.y] = 'P';
            tab[xy.x - 2][xy.y] = 'X';
            xy = get_pos(tab);
    }
    return xy;
}

pos_t move_down(char **tab, pos_t xy)
{
    if (tab[xy.x + 1][xy.y] != '#' && tab[xy.x + 1][xy.y] != 'X'
        && tab[xy.x][xy.y] == 'P') {
            tab[xy.x][xy.y] = ' ';
            tab[xy.x + 1][xy.y] = 'P';
            xy = get_pos(tab);
    } else if (tab[xy.x + 1][xy.y] == 'X' && tab[xy.x + 2][xy.y] != '#'
        && tab[xy.x + 2][xy.y] != 'X' && tab[xy.x][xy.y] == 'P') {
            tab[xy.x][xy.y] = ' ';
            tab[xy.x + 1][xy.y] = 'P';
            tab[xy.x + 2][xy.y] = 'X';
            xy = get_pos(tab);
    }
    return xy;
}
