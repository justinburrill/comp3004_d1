#include "order.h"
#include "orderqueue.h"

void OrderQueue::new_order(Order* order) {
    order_queue.append(order);
}

Order* OrderQueue::pop_first_order() {
    if (order_queue.empty()) {
        return nullptr;
    }
    Order* ret = order_queue.takeFirst();
    order_history.push_back(ret);
    return ret;
}

QList<Order*> OrderQueue::get_orders() {
    return order_queue;
}

QList<Order*> OrderQueue::get_order_history() {
    return order_history;
}

Order* OrderQueue::get_current_order_for_customer(CustomerUser* customer) {
    // get first order with matching customer
    for (Order *order : get_orders()) {
        if (*order->customer == *customer) {
            return order;
        }
    }
    return nullptr;
}

QList<Order*> OrderQueue::get_order_history_for_customer(CustomerUser* customer) {
    QList<Order*> out = QList<Order*>();
    for (Order *order : get_order_history()) {
        if (*order->customer == *customer) {
            out.push_back(order);
        }
    }
    return out;
}

void OrderQueue::cleanup() {
    qDeleteAll(order_queue);
    qDeleteAll(order_history);
    order_queue.clear();
    order_history.clear();
}
