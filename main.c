#include <stdio.h>
#include <stdlib.h>
#include "menu.h"


int main()
{
    char* menu_strings[] = {"Start Game", "Options", "Quit"};

    int length = sizeof(menu_strings)/sizeof(menu_strings[0]);

    printf("%d\n", menu(menu_strings, length));

    return 0;
}
