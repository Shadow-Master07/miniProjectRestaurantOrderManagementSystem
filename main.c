#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom headers created to place things at different locations
#include "include/lib/showMainMenu.h"
#include "include/lib/showMenu.h"

char Menu[6][20] = {"burger", "pizza", "coldrink", "masaladosa", "chips", "\0"};

int orderId = 1;

typedef struct dishes
{
    int dishNameNo;
    struct dishes *next;
} dishName;

typedef struct order
{
    int ID;
    int tableNumber;
    dishName *dishHead;
    struct order *next;
} orderList;

orderList *addOrder(orderList *orderHead)
{

    orderList *newOrder = (orderList *)malloc(sizeof(orderList));
    newOrder->dishHead = NULL;
    newOrder->next = NULL;
    newOrder->ID = orderId;
    orderId++;
    dishName *temp = NULL;
    printf("Enter table no:\n");
    scanf("%d", &newOrder->tableNumber);

    while (1)
    {
        int p;
        showMenu();
        dishName *newDish = (dishName *)malloc(sizeof(dishName));
        printf("Refer the menu and enter the dish name no \n Enter 0 to complete your order \n");
        scanf("%d", &p);
        if (p == 0)
            break;
        newDish->dishNameNo = p;

        newDish->next = NULL;
        if (newOrder->dishHead == NULL)
        {
            newOrder->dishHead = newDish;
            temp = newDish;
        }
        else
        {
            temp->next = newDish;
            temp = temp->next;
        }
    }
    if (orderHead == NULL)
    {
        orderHead = newOrder;
        orderHead->next = NULL;
    }
    else
    {
        orderList *temp2 = orderHead;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }

        temp2->next = newOrder;
    }

    printf("order id is %d\n", newOrder->ID);
    return orderHead;
}

// Need to see this
orderList *deleteOrder(orderList *head)
{
    orderList *toDelete = head;
    head = head->next;
    dishName *toDeleteDish = toDelete->dishHead;
    dishName *tempDishDelete;
    printf("Order ID %d is completed\n", toDelete->ID);
    while (toDeleteDish != NULL)
    {
        tempDishDelete = toDeleteDish->next;
        printf("Dish %s completed\n", toDeleteDish->dishNameNo);
        free(toDeleteDish);
        toDeleteDish = tempDishDelete;
    }
    free(toDelete);
    return head;
}

void orderListStatus(orderList *orderHead)
{
    int id;
    printf("Enter order id\n");
    scanf("%d", &id);
    orderList *temp1 = orderHead;
    if (temp1 == NULL)
    {
        printf("Not found");
        return;
    }
    while (id != temp1->ID)
    {
        temp1 = temp1->next;
    }
    dishName *temp2 = temp1->dishHead;
    while (temp2 != NULL)
    {
        printf("%s\n", Menu[temp2->dishNameNo]);

        temp2 = temp2->next;
    }
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
            orderHead = addOrder(orderHead);
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
