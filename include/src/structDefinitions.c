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
    if (head == NULL)
    {
        printf("Nothing to remove\n");
        return head;
    }
    orderList *toDelete = head;
    head = head->next;
    dishName *toDeleteDish = toDelete->dishHead;
    dishName *tempDishDelete;
    printf("Order ID %d is completed\n", toDelete->ID);
    while (toDeleteDish != NULL)
    {
        tempDishDelete = toDeleteDish->next;
        printf("Dish %d completed\n", toDeleteDish->dishNameNo); // To free memory and comment this out later when publishing
        free(toDeleteDish);
        toDeleteDish = tempDishDelete;
    }
    free(toDelete);
    return head;
}
