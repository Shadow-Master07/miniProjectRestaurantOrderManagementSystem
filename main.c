#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom headers created to place things at different locations
#include "include/lib/showMainMenu.h"
#include "include/lib/showMenu.h"
#include "include/lib/structDefinitions.h"

int main()
{
    orderList *orderHead = NULL;
    int choice;
    while (1)
    {
        showMainMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            orderHead = addOrder(orderHead, &orderId);
            break;
        case 2:
            orderHead = deleteOrder(orderHead);
            break;
        case 3:
            showMenu();
            break;
        case 4:
            orderListStatus(orderHead);
            break;
        case 5:
            printf("Bye.\n");
            exit(0);
        default:
            printf("Invalid choice. Please Enter a number from 1 to 5.\n");
        }
    }
    return 0;
}
