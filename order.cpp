#include "order.h"
#include "menuitem.h"


QString Order::generate_info_text() {
    QString out = QString("Order by %1 (ID %2) %3 items:")
            .arg(customer->name)
            .arg(order_id)
            .arg(menu_items.size());
    for (MenuItem* item : menu_items) {
        out += QString("\n%1 (%2)").arg(item->name, 15);
    }
    out += QString("Subtotal: %1\nTotal: %2\nLoyalty points redeemed: %3\nAccount credit used: %4")
            .arg(total_cost_str())
            .arg(total_cost_str())
            .arg(loyalty_points_used)
            .arg(credit_used);
    return out;
}

QString Order::total_cost_str() {
    return QString::asprintf("%.2f", total_cost());
}

float Order::total_cost() {
    float tax_rate = 1.13;
    return subtotal_cost() * tax_rate;
}

QString Order::subtotal_cost_str() {
    return QString::asprintf("%.2f", subtotal_cost());
}

float Order::subtotal_cost() {
    float total = 0.0f;
    for (MenuItem* item : menu_items) {
        total += item->price;
    }
    return total;
}
