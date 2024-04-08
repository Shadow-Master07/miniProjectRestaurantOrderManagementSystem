#include <stdio.h>
#include <stdlib.h>

#include "./../lib/showMenu.h"
#include "./../lib/structDefinitions.h"

int orderID = 1;

orderList *addOrder(orderList *orderHead, int *orderId)
{
    orderList *newOrder = (orderList *)malloc(sizeof(orderList));
    newOrder->dishHead = NULL;
    newOrder->next = NULL;
    newOrder->ID = *orderId;
    (*orderId)++;
    dishName *temp = NULL;
    printf("Enter table no:\n");
    scanf("%d", &newOrder->tableNumber);
    int p = 1;
    while (p != 0)
    {
        showMenu();
        dishName *newDish = (dishName *)malloc(sizeof(dishName));
        printf("Enter your dish name no. (Refer to menu) \n");
        printf("$> ");
        scanf("%d", &newDish->dishNameNo);
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
        printf("Enter 0 to complete order or 1 to continue\n");
        scanf("%d", &p);
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
    printf("Order id is %d\n", newOrder->ID);
    return orderHead;
}

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
        printf("Dish %d completed\n", toDeleteDish->dishNameNo);
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
        if (temp2->dishNameNo == 1)
        {
            printf(" Burger \n");
        }
        else if (temp2->dishNameNo == 2)
        {
            printf(" Pizza \n");
        }
        else if (temp2->dishNameNo == 3)
        {
            printf(" Coldrink\n");
        }
        else if (temp2->dishNameNo == 4)
        {
            printf(" Masala Dosa \n");
        }
        else
        {
            printf(" Chips \n");
        }

        temp2 = temp2->next;
    }
}