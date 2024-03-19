/*
** EPITECH PROJECT, 2023
** settingup.c
** File description:
** check
*/

#include "../include/my.h"

char **str_to_tab(char *str)
{
    int i = 0;
    int k = 0;
    int j;
    char **tab = malloc(sizeof(char *) * nbr_row(str) + 1);

    tab[nbr_row(str)] = NULL;
    while (str[i] != '\0') {
        j = 0;
        tab[k] = malloc(sizeof(char *) * nbr_row(str) + 1);
        if (tab[k] == NULL)
            exit(84);
        while (str[i] != '\n' && tab[k] != NULL) {
            tab[k][j] = str[i];
            j++;
            i++;
        }
        k++;
        i++;
    }
    return tab;
}

static int count_x_2(char *row, char *path)
{
    int count_x = 0;

    for (int j = 0; j < nbr_col(path); j++) {
        if (row[j] == 'X')
            count_x++;
    }
    return count_x;
}

int count_x(char **tab, char *path)
{
    int total_count_x = 0;

    for (int i = 0; tab[i] != NULL; i++)
        total_count_x += count_x_2(tab[i], path);
    return total_count_x;
}

static int is_box_surrounded(char **tab, int x, int y)
{
    return (tab[x][y] == 'X' && check_boxes(tab, x, y) == 1);
}

int check_lose(char **tab, char *path)
{
    int blocs = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; j != nbr_col(path); j++)
            blocs += is_box_surrounded(tab, i, j);
    }
    return (blocs == count_x(tab, path));
}

int	check_boxes(char **tab, int x, int y)
{
    if ((tab[x - 1][y] == '#' || tab[x - 1][y] == 'X')
        && (tab[x][y - 1] == '#' || tab[x][y + 1] == '#'
            || tab[x][y - 1] == 'X' || tab[x][y + 1] == 'X')
                || (tab[x + 1][y] == '#' || tab[x + 1][y] == 'X')
                    && (tab[x][y - 1] == '#' || tab[x][y + 1] == '#'
                        || tab[x][y - 1] == 'X' || tab[x][y + 1] == 'X'))
                            return 1;
    return 0;
}
