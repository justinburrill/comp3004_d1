#ifndef ORDER_H
#define ORDER_H

#include "user.h"
#include "menuitem.h"


enum class OrderType {Online, InPerson};


class Order {
private:
    static uint current_order_id;

public:
    uint order_id;
    CustomerUser* customer;
    QList<MenuItem*> menu_items;
    OrderType type;
    float loyalty_points_used;
    float credit_used;

    Order(CustomerUser* customer, QList<MenuItem*> menu_items, OrderType type, float points_used = 0.0f, float credit_used = 0.0f)
        : order_id(current_order_id), customer(customer), menu_items(menu_items), type(type), loyalty_points_used(points_used), credit_used(credit_used)
    {
        current_order_id++; // increment for next order
    }

    QString generate_info_text();
};


#endif // ORDER_H
