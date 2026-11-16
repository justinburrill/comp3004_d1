#include "user.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "order.h"
#include "orderqueue.h"


void MainWindow::generate_customer_dashboard() {
    QString customer_info_txt = "";
    ui->customer_info->setText(customer_info_txt);
    QList<Order*> orders = OrderQueue::get_order_history_for_customer(static_cast<CustomerUser*>(current_user));
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
