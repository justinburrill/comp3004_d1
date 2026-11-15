#include "mainwindow.h"
#include "user.h"
#include "ingredients.h"
#include "menuitem.h"
#include "fakedatabases.h"

#include <QApplication>

// set defaults
int StaffUser::current_staff_id = 0;
int CustomerUser::current_loyalty_points_id = 0;

// setup in-memory databases
QList<User*> UserDatabase::users = QList<User*>();
QList<MenuItem*> MenuDatabase::menu_items = QList<MenuItem*>();
QMap<QString, uint> IngredientDatabase::ingredients = QMap<QString, uint>();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    setupFakeDatabases();
    MainWindow w;
    w.show();
    auto rc = a.exec();
    cleanupFakeDatabases();
    return rc;
}
