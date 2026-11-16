#include "mainwindow.h"
#include "menuitem.h"
#include "order.h"
#include "orderqueue.h"
#include "ui_mainwindow.h"
#include "user.h"
#include "widget_helpers.h"

#include <QString>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0); // start on login page
    ui->exit_button->hide(); // don't need the exit button on the login page
    ui->back_button->hide(); // only for the menu
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_enter_button_clicked() {
    QString entered_name = ui->username_entry->text().trimmed();
    User* found_user = UserDatabaseInterface::find_user(entered_name);
    if (found_user == nullptr) { // user not found
        QString errmsg = QString("User \"%1\" not found").arg(entered_name);
        QMessageBox::information(this, "Login Error", errmsg);
    }
    else { // user found
        current_user = found_user;
        UserType type = found_user->get_type();
        switch_to_dashboard(type);
    }
}

void MainWindow::on_back_button_clicked() {
    switch_to_customer_dashboard();
}

void MainWindow::on_submit_order_button_clicked() {
    if (items_in_cart.size() == 0) {
        QMessageBox::information(this, "Order Error", "Empty cart, try again.");
        return;
    }
    CustomerUser* customer = static_cast<CustomerUser*>(current_user);
    Order* order = new Order(customer, items_in_cart, OrderType::InPerson);
    customer->loyalty_points_balance += order->loyalty_points_earned_from_order();
    items_in_cart.clear();
    OrderQueue::new_order(order);
    switch_to_customer_dashboard();
}

void MainWindow::reset() {
    ui->stackedWidget->setCurrentIndex(0);
    ui->username_entry->clear();
    ui->exit_button->hide();
    ui->back_button->hide();
    current_user = nullptr;
}

void MainWindow::on_exit_button_clicked() {
    MainWindow::reset();
}

void MainWindow::on_complete_order_button_clicked(){
    Order* finished_order = OrderQueue::pop_first_order();
    if (finished_order != nullptr) {
        generate_kitchen_dashboard();
    }
}

QString usertype_to_str(UserType type) {
    static const QString roleNames[] = {
        "Cashier",
        "Kitchen Staff",
        "Manager",
        "System Administrator",
        "Customer"
    };

    return roleNames[static_cast<int>(type)];
}

void MainWindow::switch_to_dashboard(UserType type) {
    ui->exit_button->show();

    QString displayInfo = QString("Name: %1\nRole: %2")
            .arg(current_user->name)
            .arg(usertype_to_str(current_user->get_type()));

    switch (type) {
        case UserType::Cashier:
            ui->cashier_info_label->setText(displayInfo);
            ui->stackedWidget->setCurrentIndex(1);
            break;
        case UserType::Customer:
            switch_to_customer_dashboard();
            break;
        case UserType::KitchenStaff:
            switch_to_kitchen_dashboard();
            break;
        case UserType::Manager:
            ui->manager_info_label->setText(displayInfo);
            ui->stackedWidget->setCurrentIndex(4);
            break;
        case UserType::SysAdmin:
            ui->sysadmin_info_label->setText(displayInfo);
            ui->stackedWidget->setCurrentIndex(5);
            break;
    }
}

void MainWindow::switch_to_customer_dashboard() {
    ui->stackedWidget->setCurrentIndex(2);
    ui->back_button->hide();
    generate_customer_dashboard();
}

void MainWindow::switch_to_kitchen_dashboard() {
    ui->stackedWidget->setCurrentIndex(3);
    generate_kitchen_dashboard();
}
