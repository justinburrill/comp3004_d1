#include "fakedatabases.h"
#include "user.h"
#include "menuitem.h"
#include "ingredients.h"
#include "QList"
#include "QMap"


void setupFakeUserDatabase() {
    UserDatabase::add_user(new CustomerUser("Jane Doe", "JDeey", "janedoe@fakemail.com", "123 Sesame St"));
    UserDatabase::add_user(new CustomerUser("George Johnson", "Georson", "georgio@fakemail.com", "223 Rock Ave"));
    UserDatabase::add_user(new CustomerUser("Bob Pa", "Patroly", "bensin023@fakemail.com", "321 Biltmore Cres"));
    UserDatabase::add_user(new CustomerUser("Clent Clark", "CCerk", "sharkattack@fakmail.com", "10 Seawater St"));
    UserDatabase::add_user(new CustomerUser("Brandon Bark", "MR Bark", "treesman@fakemail.com", "192 Oak St"));
    UserDatabase::add_user(new CustomerUser("Jacob Danny", "Taco man", "Tacoman@fakemail.com", "62 Singleton St"));

    UserDatabase::add_user(new CashierStaffUser("Cindy Block", "ACindyDC"));
    UserDatabase::add_user(new KitchenStaffUser("Greg Heffley", "WhimpyGuy"));
    UserDatabase::add_user(new KitchenStaffUser("Sarah Sha", "Singerfully"));
    UserDatabase::add_user(new ManagerStaffUser("Man Ajor", "ClintEastwood"));
    UserDatabase::add_user(new SysAdminStaffUser("Bill Bossa", "Barbie"));
}

// starting ingredients in inventory
void setupFakeIngredientDatabase() {
    // TODO
}

void setupFakeMenuItemDatabase() {
    // TODO
}

void cleanupFakeDatabases() {
    UserDatabase::cleanup(); // delete users allocated with "new"
    IngredientDatabase::cleanup();
    MenuDatabase::cleanup();
}

void setupFakeDatabases() {
    setupFakeUserDatabase();
}

void UserDatabase::cleanup() {
    qDeleteAll(users);
}

void UserDatabase::add_user(User *user) {
    users.push_back(user);
}

void IngredientDatabase::cleanup() {
    // nothing to do
}

void MenuDatabase::cleanup() {
    qDeleteAll(menu_items);
}
