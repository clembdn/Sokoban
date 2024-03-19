/*
** EPITECH PROJECT, 2023
** sokoban.c
** File description:
** main
*/

#include "../include/my.h"

int nbr_col(char *str)
{
    int col = 0;

    for (int i = 0; str[i] != '\n'; i++)
        col++;
    return col;
}

int nbr_row(char *str)
{
    int row = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            row++;
    }
    return row;
}

int lenmap(char **tab)
{
    int tot = 0;

    for (int i = 0; tab[i] != NULL; i++)
        tot++;
    return tot;
}

void validsize(char *str, char **tab)
{
    while (COLS < nbr_col(str) || LINES < lenmap(tab)) {
        clear();
        mvprintw(LINES / 2, COLS / 2 - 11, "enlarge the terminal");
        refresh();
    }
}

static int flag_h(int argc, char **argv)
{
    int fd = open("help.txt", O_RDONLY);
    char buffer;
    int i = 0;
    ssize_t bytesRead;

    bytesRead = read(fd, &buffer, 1);
    while (bytesRead > 0) {
        write(1, &buffer, 1);
        i++;
        bytesRead = read(fd, &buffer, 1);
    }
    close(fd);
    return 0;
}

int main(int argc, char **argv)
{
    char *buffer;
    int size;
    char *str;
    int fd = open(argv[1], O_RDONLY);

    if (argc != 2)
        exit(84);
    if (argv[1][0] == '-' && argv[1][1] == 'h')
        return flag_h(argc, argv);
    buffer = malloc(5000);
    size = read(fd, buffer, 5000);
    if (size < 0)
        exit(84);
    buffer[size] = 0;
    terrain_display(str_to_tab(buffer), buffer);
    free(buffer);
    return 0;
}
