#include<string.h>

#include "color.h"

int colorNameExist(char *name, Color *c, unsigned n)
{
    for (int i = 0; i < n; i ++)
        if ( ! strcmp(c[i].name, name))
            return i;
    return -1;
}

int colorCodeExist(char *code, Color *c, unsigned n)
{
    for (int i = 0; i < n; i ++)
        if ( ! strcmp(c[i].code, code))
            return i;
    return -1;
}