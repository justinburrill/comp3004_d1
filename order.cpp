#include "order.h"
#include "menuitem.h"

QString ordertype_to_str(OrderType type) {
    static const QString type_names[] = {
        "Online",
        "In Person"
    };
    return type_names[static_cast<int>(type)];
}

QString orderstatus_to_str(OrderStatus type) {
    static const QString status_names[] = {
        "In Progress",
        "Completed",
        "Picked Up",
        "Cancelled"
    };
    int i = static_cast<int>(type);
    return status_names[i];
}

QString Order::generate_info_text() {
    QString out = QString("%5 Order by %1 (ID %2) %3 items: %4")
            .arg(customer->name)
            .arg(order_id)
            .arg(menu_items.size())
            .arg(orderstatus_to_str(status))
            .arg(ordertype_to_str(type));
    for (MenuItem* item : menu_items) {
        out += QString("\n  %1 (%2)").arg(item->name).arg(item->price);
    }
    out += QString("\nSubtotal: %1\nTotal: %2\nLoyalty points redeemed: %3\nAccount credit used: %4")
            .arg(format_float(subtotal_cost()))
            .arg(format_float(total_cost()))
            .arg(loyalty_points_used)
            .arg(credit_used);
    return out;
}

float Order::total_cost() {
    return subtotal_cost() * TAX_RATE;
}

float Order::subtotal_cost() {
    float total = 0.0f;
    for (MenuItem* item : menu_items) {
        total += item->price;
    }
    return total;
}

float Order::unpaid_balance() {
    float total = total_cost();
    total -= loyalty_points_used; // 1 point = $1
    total -= credit_used;
    return total;
}

uint Order::loyalty_points_earned_from_order() {
    if (loyalty_points_used > 0) {
        return 0; // as per business rules
    }
    uint points_earned = total_cost() / 3;
    return points_earned;
}

QString format_float(float cost) {
    return QString::asprintf("%.2f", cost);
}
