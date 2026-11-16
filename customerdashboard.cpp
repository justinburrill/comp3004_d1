#include "user.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "order.h"
#include "orderqueue.h"


void MainWindow::generate_customer_dashboard() {
    CustomerUser *customer = static_cast<CustomerUser*>(current_user);
    QString customer_info_txt = QString("%1 (%2)\nLoyalty points balance (ID %3): %4\nCredit balance: %5\nEmail: %6\nAddress: %7")
            .arg(customer->name)
            .arg(customer->username)
            .arg(customer->loyalty_points_balance)
            .arg(customer->loyalty_points_id)
            .arg(customer->credit_balance)
            .arg(customer->email)
            .arg(customer->home_address);

    ui->customer_info->setText(customer_info_txt);
    Order* current_order = OrderQueue::get_current_order_for_customer(customer);
    if (current_order == nullptr) {
        ui->current_order_content->setText("No current order.");
        // TODO: button to switch to menu
    }
    else {
        ui->current_order_content->setText(current_order->generate_info_text());
    }
    QList<Order*> orders = OrderQueue::get_order_history_for_customer(customer);
    qDeleteAll(ui->order_history_content->children());
    if (orders.empty()) {
        QLabel *empty_label = new QLabel("No orders.", this);
        ui->order_history_content->addWidget(empty_label);
    }
    else {
        for (Order *order : orders) {
            QLabel *order_label = new QLabel(order->generate_info_text(), this);
            ui->order_history_content->addWidget(order_label);
        }
    }

}
