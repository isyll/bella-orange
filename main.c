#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "color.h"

int nbc = 10;
Color colors[] = {
    {"rouge",   "#ff0000"},
    {"bleu",    "#0000ff"},
    {"vert",    "#00ff00"},

    {"noir",    "#000000"},
    {"gris",    "#808080"},
    {"argent",  "#c0c0c0"},

    {"marron",  "#800000"},
    {"mauve",   "#800080"},
    {"violet",  "#800080"},
    {"jaune",   "#ffff00"},
};

void drawTab(Color *, int);

int main(void)
{
    char color[MAX_NAME_SIZE];
    int ce;

    printf("Bonjour!\n");

    drawTab(colors, nbc);

    do {
        printf("Choisissez la couleur a appliquer : ");
        scanf("%s", color);

        if (color[0] == '#')
        {
            if ( (ce = colorCodeExist(color, colors, nbc) ) == -1)
            {
                printf("Le code de couleur saisi n'est pas pris en charge!\n\
Choisissez-en un valide!\n");
                continue;
            }
        }
        else
        {
            if ( (ce = colorNameExist(color, colors, nbc) ) == -1)
            {
                printf("La couleur saisie n'est pas prise en charge!\n\
Choisissez-en une valide!\n");
                continue;
            }
        }
    } while (1);

    return 0;
}

void drawTab(Color *c, int n)
{
    int i, tWidth, maxWidth;
    char line = '-', col = '|';

    if (n < 1 || ! c)
        return;

    tWidth = 12;
    maxWidth = 8; // strlen("couleurs")

    for (i = 0; i < n; i ++)
        if (strlen(c[i].name) > maxWidth)
            maxWidth = strlen(c[i].name);

    tWidth += maxWidth;

    printf(" ");
    for (i = 0; i < tWidth; i ++)
        printf("%c", line);
    printf("\n");

    printf("%c Couleurs %c Codes   %c\n", col, col, col);

    printf(" ");
    for (i = 0; i < tWidth; i ++)
        printf("%c", line);
    printf("\n");

    i = 0;
    for (int tmp; i < n; i ++)
    {
        tmp = strlen(c[i].name);

        printf("%c %s", col, c[i].name);
        if (maxWidth > tmp)
            for (int j = 0; j < maxWidth - tmp; j ++)
                printf(" ");

        printf(" %c %s %c\n", col, c[i].code, col);
    }

    printf(" ");
    for (i = 0; i < tWidth; i ++)
        printf("%c", line);
    printf("\n");
}

