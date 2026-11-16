#include "user.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "order.h"
#include "orderqueue.h"
#include <qlabel.h>
#include "widget_helpers.h"


void MainWindow::generate_customer_dashboard() {
    delete_children(ui->current_order_contents);
    delete_children(ui->order_history_content);
    CustomerUser *customer = static_cast<CustomerUser*>(current_user);
    QString customer_info_txt = QString("%1 (%2)\nLoyalty points balance (ID %3): %4\nCredit balance: %5\nEmail: %6\nAddress: %7")
            .arg(customer->name)
            .arg(customer->username)
            .arg(customer->loyalty_points_id)
            .arg(customer->loyalty_points_balance)
            .arg(customer->credit_balance)
            .arg(customer->email)
            .arg(customer->home_address);
    ui->customer_info->setText(customer_info_txt);

    Order* current_order = OrderQueue::get_current_order_for_customer(customer);
    if (current_order == nullptr) {
        ui->current_order_contents->addWidget(new QLabel("No current order."));
        QPushButton* button = new QPushButton();
        button->setText("View menu");
        connect(button, &QPushButton::clicked, this, [this] {
            switch_to_menu();
        });
        ui->current_order_contents->addWidget(button);
    }
    else {
        ui->current_order_contents->addWidget(new QLabel(current_order->generate_info_text()));
    }

    QList<Order*> orders = OrderQueue::get_order_history_for_customer(customer);

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

void MainWindow::switch_to_menu() {
    ui->stackedWidget->setCurrentIndex(6);
    ui->back_button->show();
    generate_menu();
}

void MainWindow::generate_cart() {
    delete_children(ui->cart_layout);
    if (items_in_cart.size() == 0) {
        ui->cart_layout->addWidget(new QLabel("No items selected."));
        return;
    }
    for (MenuItem *item_in_cart : items_in_cart) {
        ui->cart_layout->addWidget(new QLabel(item_in_cart->generate_menu_text()));
        QPushButton* button = new QPushButton();
        button->setText("Remove");
        connect(button, &QPushButton::clicked, this, [this, item_in_cart] {
            items_in_cart.removeOne(item_in_cart);
            generate_cart();
        });
        ui->cart_layout->addWidget(button);
    }
}

void MainWindow::generate_menu() {
    // remove and regenerate
    delete_children(ui->available_menu_item_layout);

    ui->available_menu_item_layout->addWidget(new QLabel("Available menu items:"));
    for (MenuItem *item_in_menu : MenuDatabaseInterface::get_menu_items()) {
        ui->available_menu_item_layout->addWidget(new QLabel(item_in_menu->generate_menu_text()));
        if (item_in_menu->is_sold_out()) {
            ui->available_menu_item_layout->addWidget(new QLabel("Currently sold out."));
        }
        else {
            QPushButton* button = new QPushButton();
            button->setText("Add to order");
            // add lambda function as the on-clicked event
            connect(button, &QPushButton::clicked, this, [this, item_in_menu] {
                items_in_cart.push_back(item_in_menu);
                generate_cart();
            });
            ui->available_menu_item_layout->addWidget(button);
        }
    }

    generate_cart();
}
