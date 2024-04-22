#include <stdio.h>
#include <stdlib.h>

#include "./../lib/showMenu.h"
#include "./../lib/structDefinitions.h"
#include "./../lib/showOrdersAndStatus.h"

orderList *addOrder(orderList *orderHead, int *orderId)
{
    int TT = 0;     // Need to check how this TT works and probably replace it
    while (TT == 0) // Need to check how this TT works and probably replace it
    {
        bookTable();

        printf("Enter table no:\n");
        int t;
        scanf("%d", &t);
        if (table[t - 1] == 1)
        {
            printf("Table is already booked,please book another\n");
            continue;
        }
        else if (t > 10 || t < 1)
        {
            printf("Invalid number,refer the available tables\n");
            continue;
        }

        orderList *newOrder = (orderList *)malloc(sizeof(orderList));
        newOrder->dishHead = NULL;
        newOrder->next = NULL;
        newOrder->ID = *orderId;
        (*orderId)++;
        dishName *temp = NULL;

        TT = 1; // Need to check how this TT works and probably replace it
        newOrder->tableNumber = t;
        table[newOrder->tableNumber - 1] = 1;
        showMenu();
        printf("Enter your dish name no. (Refer to menu) \n");

        while (1)
        {
            int orderNumber;
            dishName *newDish = (dishName *)malloc(sizeof(dishName));
            printf("(0 to complete) $> ");
            scanf("%d", &orderNumber);
            if (orderNumber == 0)
            {
                break;
            }
            if (orderNumber > 5 || orderNumber < 0)
            {
                printf("Enter valid number from 1 to 5");
                continue;
            }

            (newDish->dishNameNo) = orderNumber - 1;
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
}

orderList *deleteOrder(orderList *head)
{
     if (head == NULL)
    {
        printf("No orders to delete.\n");
        return NULL;
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
