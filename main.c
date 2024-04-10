#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom headers created to place things at different locations
#include "include/lib/showMainMenu.h"
#include "include/lib/showMenu.h"
#include "include/lib/structDefinitions.h"

int orderID = 1;
char Menu[6][20] = {"burger", "pizza", "coldrink", "masaladosa", "chips", "\0"};

void showAllOrders(orderList *orderHead)
{
    orderList *temp1 = orderHead;
    dishName *temp2 = NULL;
    int i;
    printf("Printing Order ID:\n");
    while (temp1 != NULL)
    {
        printf("%d:\n", temp1->ID);
        temp2 = temp1->dishHead;
        i = 1;
        while (temp2 != NULL)
        {
            printf("    %d. %s\n", i, Menu[temp2->dishNameNo]);
            temp2 = temp2->next;
            i++;
        }
        temp1 = temp1->next;
    }
    printf("Order list completed\n");
}

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
            deleteOrder(orderHead);
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
            printf("Bye.\n");
            exit(0);
        default:
            printf("Invalid choice. Please enter a number from 1 to 5.\n");
        }
    }
    return 0;
}
