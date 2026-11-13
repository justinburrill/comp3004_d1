#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "user.h"

#include <QString>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0); // start on login page
    ui->exit_button->hide(); // don't need the exit button on the login page
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_enter_button_clicked() {
    QString entered_name = ui->username_entry->text().trimmed();
    User* found_user = UserList::find_user(entered_name);
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


void MainWindow::on_exit_button_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
    ui->username_entry->clear();
    ui->exit_button->hide();
}

void MainWindow::switch_to_dashboard(UserType type) {
    ui->exit_button->show();
    switch (type) {
        case UserType::Cashier:
            ui->stackedWidget->setCurrentIndex(1);
            break;
        case UserType::Customer:
            ui->stackedWidget->setCurrentIndex(2);
            break;
        case UserType::KitchenStaff:
            ui->stackedWidget->setCurrentIndex(3);
            break;
        case UserType::Manager:
            ui->stackedWidget->setCurrentIndex(4);
            break;
        case UserType::SysAdmin:
            ui->stackedWidget->setCurrentIndex(5);
            break;
    }

}
