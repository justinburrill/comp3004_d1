#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "order.h"
#include "orderqueue.h"
#include <QLabel>

void MainWindow::generate_kitchen_dashboard() {
    QList<Order*> active_orders = OrderQueue::get_orders();
    QLayoutItem *item;
    while ((item = ui->kitchen_order_content->takeAt(0)) != nullptr) {
        if (QWidget *widget = item->widget()) {
            delete widget;
        }
            delete item;
        }
    if (active_orders.empty()){
        QLabel *empty_label = new QLabel("No active orders in queue.", this);
        ui->kitchen_order_content->addWidget(empty_label);
    }
    else{
        for (Order *order: active_orders) {
            QLabel *order_label= new QLabel(order->generate_info_text(), this);
            ui->kitchen_order_content->addWidget(order_label);
        }
    }
}
