#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "user.h"
#include "menuitem.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_enter_button_clicked();
    void on_exit_button_clicked();
    void on_complete_order_button_clicked();
    void on_submit_order_button_clicked();
    void on_back_button_clicked();

private:
    Ui::MainWindow *ui;
    User* current_user = nullptr;
    QList<MenuItem*> items_in_cart = QList<MenuItem*>();

    void switch_to_dashboard(UserType type);
    void reset();
    void switch_to_customer_dashboard();
    void switch_to_kitchen_dashboard();
    void switch_to_menu();

    void generate_customer_dashboard();
    void generate_kitchen_dashboard();
    void generate_menu();
    void generate_cart();
};
#endif // MAINWINDOW_H
