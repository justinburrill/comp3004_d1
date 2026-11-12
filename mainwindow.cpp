#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "user.h"

#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0); // set login page
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_enter_button_clicked() {
    // TODO;
}
