#include <stdio.h>
#include "../lib/showOrdersAndStatus.h"

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

void bookTable()
{
    printf("Available tables \n");
    printf(" --------------\n");
    for (int i = 0; i < 10; i++)
    {
        printf("| ");
        if (table[i] == 0)
        {
            if (i + 1 < 10)
            {
                printf("  %d  ", i + 1);
            }
            else
            {
                printf("  %d ", i + 1);
            }
        }
        if (table[i] == 1)
        {
            printf("  X  ");
        }
        if (i % 2 == 1)
        {
            printf(" |\n");
        }
    }
    printf(" --------------\n");
}