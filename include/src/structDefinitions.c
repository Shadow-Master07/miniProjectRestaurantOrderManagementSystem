#include <stdio.h>
#include <stdlib.h>

#include "./../lib/showMenu.h"
#include "./../lib/structDefinitions.h"

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
    showMenu();
    printf("Enter your dish name no. (Refer to menu) \n");

    while (1)
    {
        int p;
        dishName *newDish = (dishName *)malloc(sizeof(dishName));
        printf("(0 to complete) $> ");
        scanf("%d", &p);
        if (p == 0)
        {
            break;
        }

        (newDish->dishNameNo) = p - 1;
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
