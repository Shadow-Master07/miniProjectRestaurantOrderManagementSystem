#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom headers created to place things at different locations
#include "include/lib/showMainMenu.h"
#include "include/lib/showMenu.h"
#include "include/lib/structDefinitions.h"
#include "include/lib/showOrdersAndStatus.h"

int orderID = 1;
int table[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
char Menu[6][20] = {"Burger", "Pizza", "Coldrink", "Masala Dosa", "Chips", "\0"};

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
            orderHead = addOrder(orderHead, &orderID);
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
            showAllOrders(orderHead);
            break;
        case 6:
            printf("Thank You...\n");
            exit(0);
        default:
            printf("Invalid choice. Please enter a number from 1 to 6.\n");
        }
    }
    return 0;
}