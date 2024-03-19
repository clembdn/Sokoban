/*
** EPITECH PROJECT, 2023
** settingup.c
** File description:
** display
*/

#include "../include/my.h"

int terrain_display(char **tab, char *path)
{
    WINDOW *box;
    pos_t xy;
    pos_t *posdot;

    posdot = add_coord(tab);
    xy = get_pos(tab);
    initscr();
    while (1) {
        curs_set(0);
        validsize(path, tab);
        xy = loop_screen(tab, path, xy);
        if (check_spot(tab, posdot) == 0)
            win_screen(tab, path);
        if (check_lose(tab, path) == 1)
            lose_screen(tab, path);
    }
    refresh();
    endwin();
    free(box);
    return 0;
}

void lose_screen(char **tab, char *path)
{
    clear();
    refresh();
    endwin();
    exit(1);
}

void win_screen(char **tab, char *path)
{
    clear();
    refresh();
    endwin();
    exit(0);
}

int my_strlen(char const *str)
{
    int res = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        res++;
    }
    return res;
}

pos_t loop_screen(char **tab, char *path, pos_t xy)
{
    clear();
    for (int i = 0; tab[i] != NULL; i++) {
        mvprintw(LINES / 2 - lenmap(tab) / 2 + i,
            COLS / 2 - my_strlen(tab[i]) / 2, tab[i]);
        curs_set(0);
    }
    refresh();
    xy = check_pos_mvt(tab, xy, path);
    return xy;
}
