#include <stdio.h>
#include <string.h>
#include "./../lib/showMenu.h"

void showMenu()
{
    for(int i = 0; strcmp(Menu[i], "\0"); i++)
    {
        printf("%d. %s\n", (i+1), Menu[i]);
    }
}
