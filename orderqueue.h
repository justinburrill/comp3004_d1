#ifndef ORDERQUEUE_H
#define ORDERQUEUE_H

#include <qlist.h>

#include "order.h"


class OrderQueue {
private:
    static QList<Order*> order_queue;

public:
    static void new_order(Order* order) {
        order_queue.append(order);
    }

    static Order* pop_first_order() {
        if (order_queue.empty()) {
            return nullptr;
        }
        Order* ret = order_queue[0];
        order_queue.pop_front();
        return ret;
    }

    static QList<Order*>* get_orders() {
        return &order_queue;
    }

};

#endif // ORDERQUEUE_H
