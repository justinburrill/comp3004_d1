#ifndef ORDERQUEUE_H
#define ORDERQUEUE_H

#include <qlist.h>

#include "order.h"


class OrderQueue {
private:
    static QList<Order*> order_queue;
    static QList<Order*> order_history;

public:
    static void new_order(Order* order);
    static Order* pop_first_order();
    static QList<Order*> get_orders();
    static QList<Order*> get_order_history();
    static QList<Order*> get_order_history_for_customer(CustomerUser* customer);
    static void cleanup();
};
#endif // ORDERQUEUE_H
