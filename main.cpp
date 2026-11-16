#include "mainwindow.h"
#include "user.h"
#include "ingredients.h"
#include "menuitem.h"
#include "fakedatabases.h"
#include "order.h"
#include "orderqueue.h"

#include <QApplication>

// set defaults
uint StaffUser::current_staff_id = 0;
uint CustomerUser::current_loyalty_points_id = 0;
uint Order::current_order_id = 0;

// setup in-memory databases
QList<User*> UserDatabase::users = QList<User*>();
QList<MenuItem*> MenuDatabase::menu_items = QList<MenuItem*>();
QMap<QString, uint> IngredientDatabase::ingredients = QMap<QString, uint>();
QList<Order*> OrderQueue::order_queue = QList<Order*>();
QList<Order*> OrderQueue::order_history = QList<Order*>();

void cleanup() {
    cleanupFakeDatabases();
    OrderQueue::cleanup();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    setupFakeDatabases();
    MainWindow w;
    w.show();
    auto rc = a.exec();
    cleanup();
    return rc;
}
