#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "file.h"

int changeColor(char *varName, char *code)
{
    FILE *f = fopen(CSS_FILE, "r"), *tmp = fopen("temporary", "w");
    char buffer[BUFFER_SIZE];
    int witness;
    
    if ( ! f || ! tmp )
        return 0;

    witness = 0; // permet de faire seulement
                 // la modification de la premiere occurence

    while (fgets(buffer, BUFFER_SIZE, f) != NULL)
        if (strstr(buffer, varName) && ! witness)
        {
            fputs(strcat(strcat(varName, ": "), strcat(code, ";\n")), tmp);
            witness = 1;
        }
        else
            fputs(buffer, tmp);

    fclose(f);
    fclose(tmp);

    remove(CSS_FILE);
    rename("temporary", CSS_FILE);

    return 1;
}
