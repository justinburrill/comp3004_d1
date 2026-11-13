#include "mainwindow.h"
#include "user.h"
#include "ingredients.h"
#include "menuitem.h"

#include <QApplication>

// set defaults
int StaffUser::current_staff_id = 0;
int CustomerUser::current_loyalty_points_id = 0;
QList<User*> UserDatabase::users = QList<User*>();
QList<MenuItem*> MenuDatabase::menu_items = QList<MenuItem*>();
QMap<QString, uint> IngredientDatabase::ingredients = QMap<QString, uint>();

void setupFakeDatabase() {
    UserDatabase::add_user(new CustomerUser("Jane Doe", "JDeey", "janedoe@fakemail.com", "123 Sesame St"));
    UserDatabase::add_user(new CustomerUser("George Johnson", "Georson", "georgio@fakemail.com", "223 Rock Ave"));
    UserDatabase::add_user(new CustomerUser("Bob Pa", "Patroly", "bensin023@fakemail.com", "321 Biltmore Cres"));
    UserDatabase::add_user(new CustomerUser("Clent Clark", "CCerk", "sharkattack@fakmail.com", "10 Seawater St"));
    UserDatabase::add_user(new CustomerUser("Brandon Bark", "MR Bark", "treesman@fakemail.com", "192 Oak St"));
    UserDatabase::add_user(new CustomerUser("Jacob Danny", "Taco man", "Tacoman@fakemail.com", "62 Singleton St"));

    UserDatabase::add_user(new KitchenStaffUser("Man Ajor", "ClintEastwood"));
    UserDatabase::add_user(new KitchenStaffUser("Sarah Sha", "Singerfully"));
    UserDatabase::add_user(new CashierStaffUser("Cindy Block", "ACindyDC"));
    UserDatabase::add_user(new ManagerStaffUser("Greg Heffley", "WhimpyGuy"));
    UserDatabase::add_user(new SysAdminStaffUser("Bill Bossa", "Barbie"));
}

void cleanupFakeDatabase() {
    UserDatabase::cleanup(); // delete users allocated with "new"
    IngredientDatabase::cleanup();
    MenuDatabase::cleanup();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    setupFakeDatabase();
    MainWindow w;
    w.show();
    auto rc = a.exec();
    cleanupFakeDatabase();
    return rc;
}
