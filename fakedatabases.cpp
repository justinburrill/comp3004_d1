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
    IngredientDatabaseInterface::add_count("Bacon", 80);
    IngredientDatabaseInterface::add_count("Lettuce", 100);
    IngredientDatabaseInterface::add_count("Tomato", 100);
    IngredientDatabaseInterface::add_count("Bread", 45);
    IngredientDatabaseInterface::add_count("Chicken", 60);
    IngredientDatabaseInterface::add_count("Steak", 35);
    IngredientDatabaseInterface::add_count("Pork", 29);
    IngredientDatabaseInterface::add_count("Lemon", 25);
    IngredientDatabaseInterface::add_count("Mayo", 60);
    IngredientDatabaseInterface::add_count("Tea Leaves", 80);
    IngredientDatabaseInterface::add_count("Tomato Sauce", 40);
    IngredientDatabaseInterface::add_count("Cream Cheese", 92);
    IngredientDatabaseInterface::add_count("Cheese", 57);
    IngredientDatabaseInterface::add_count("Coffee", 180);
    IngredientDatabaseInterface::add_count("Sugar", 180);
    IngredientDatabaseInterface::add_count("Salt", 180);
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
    setupFakeIngredientDatabase();
}

void UserDatabase::add_user(User *user) {
    users.push_back(user);
}

void UserDatabase::cleanup() {
    qDeleteAll(users);
}

void IngredientDatabase::cleanup() {
    // nothing to do, no dynamically allocated contents
}

void MenuDatabase::cleanup() {
    qDeleteAll(menu_items);
}
