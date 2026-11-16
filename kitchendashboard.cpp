#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "order.h"
#include "orderqueue.h"
#include "widget_helpers.h"
#include <QLabel>

void MainWindow::generate_kitchen_dashboard() {
    QList<Order*> active_orders = OrderQueue::get_orders();
    delete_children(ui->kitchen_order_content);
    if (active_orders.empty()){
        QLabel *empty_label = new QLabel("No active orders in queue.", this);
        ui->kitchen_order_content->addWidget(empty_label);
    }
    else
    {
        for (Order *order : active_orders) {
            QLabel *order_label= new QLabel(order->generate_info_text(), this);
            ui->kitchen_order_content->addWidget(order_label);
        }
    }
}
