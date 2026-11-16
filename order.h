#ifndef ORDER_H
#define ORDER_H

#include "user.h"
#include "menuitem.h"


const float TAX_RATE = 1.15;

enum class OrderType {Online, InPerson};

enum class OrderStatus {InProgress, Completed, PickedUp, Cancelled};

QString ordertype_to_str(OrderType type);

QString orderstatus_to_str(OrderStatus type);

QString format_float(float cost);

class Order {
private:
    static uint current_order_id;

public:
    uint order_id;
    CustomerUser* customer;
    QList<MenuItem*> menu_items;
    OrderType type;
    OrderStatus status;
    uint loyalty_points_used;
    float credit_used;

    Order(CustomerUser* customer, QList<MenuItem*> menu_items, OrderType type, uint points_used = 0, float credit_used = 0.0f)
        : order_id(current_order_id), customer(customer), menu_items(menu_items), type(type), status(OrderStatus::InProgress), loyalty_points_used(points_used), credit_used(credit_used)
    {
        current_order_id++; // increment for next order
    }

    QString generate_info_text();
    float total_cost();
    float subtotal_cost();
    float unpaid_balance();
    uint loyalty_points_earned_from_order();
};


#endif // ORDER_H
