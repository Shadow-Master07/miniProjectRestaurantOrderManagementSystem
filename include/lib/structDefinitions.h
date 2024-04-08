#ifndef STRUCTDEFINITIONS_H
#define STRUCTDEFINITIONS_H

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

orderList *addOrder(orderList *orderHead, int *orderId);
orderList *deleteOrder(orderList *head);
void orderListStatus(orderList *orderHead);

#endif