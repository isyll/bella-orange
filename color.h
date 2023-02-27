#ifndef COLOR_H
#define COLOR_H

#define MAX_NAME_SIZE 20
#define CCODE_SIZE 8

typedef struct {
    char name[MAX_NAME_SIZE];
    char code[CCODE_SIZE];
} Color;

int colorNameExist(char *, Color *, unsigned);
int colorCodeExist(char *, Color *, unsigned);

#endif