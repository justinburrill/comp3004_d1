#include "mainwindow.h"
#include "user.h"

#include <QApplication>

// set defaults
int StaffUser::current_staff_id = 0;
int CustomerUser::current_loyalty_points_id = 0;

void setupUsers() {
    UserList::add_user(new CustomerUser("Jane Doe", "JDeey", "janedoe@fakemail.com", "123 Sesame St"));
    UserList::add_user(new CustomerUser("George Johnson", "Georson", "georgio@fakemail.com", "223 Rock Ave"));
    UserList::add_user(new CustomerUser("Bob Pa", "Patroly", "bensin023@fakemail.com", "321 Biltmore Cres"));
    UserList::add_user(new CustomerUser("Clent Clark", "CCerk", "sharkattack@fakmail.com", "10 Seawater St"));
    UserList::add_user(new CustomerUser("Brandon Bark", "MR Bark", "treesman@fakemail.com", "192 Oak St"));
    UserList::add_user(new CustomerUser("Jacob Danny", "Taco man", "Tacoman@fakemail.com", "62 Singleton St"));

    UserList::add_user(new KitchenStaffUser("Man Ajor", "ClintEastwood"));
    UserList::add_user(new KitchenStaffUser("Sarah Sha", "Singerfully"));
    UserList::add_user(new CashierStaffUser("Cindy Block", "ACindyDC"));
    UserList::add_user(new ManagerStaffUser("Greg Heffley", "WhimpyGuy"));
    UserList::add_user(new SysAdminStaffUser("Bill Bossa", "Barbie"));

}

void cleanupUsers() {
    UserList::cleanup(); // delete users allocated with "new"
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    setupUsers();
    MainWindow w;
    w.show();
    return a.exec();
}
