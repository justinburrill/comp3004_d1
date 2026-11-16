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
    IngredientDatabaseInterface::add_count("Bagel Bread", 45);
    IngredientDatabaseInterface::add_count("Chicken", 60);
    IngredientDatabaseInterface::add_count("Steak", 35);
    IngredientDatabaseInterface::add_count("Pork", 29);
    IngredientDatabaseInterface::add_count("Lemon", 25);
    IngredientDatabaseInterface::add_count("Mayo", 60);
    IngredientDatabaseInterface::add_count("Tea Leaves", 80);
    IngredientDatabaseInterface::add_count("Tomato Sauce", 40);
    IngredientDatabaseInterface::add_count("Cream Cheese", 92);
    IngredientDatabaseInterface::add_count("Cheese", 57);
    IngredientDatabaseInterface::add_count("Coffee Beans", 280);
    IngredientDatabaseInterface::add_count("Chocolate", 45);
    IngredientDatabaseInterface::add_count("Milk", 165);
    IngredientDatabaseInterface::add_count("Sugar", 180);
    IngredientDatabaseInterface::add_count("Ice", 368);
    IngredientDatabaseInterface::add_count("Salt", 180);
}

void setupFakeMenuItemDatabase() {
    MenuDatabaseInterface::add_menu_item("BLT Sandwich", MenuCategory::Sandwich, 8.99f, {
        {"Bread", 1},
        {"Bacon", 3},
        {"Lettuce", 1},
        {"Tomato", 1},
        {"Mayo", 1}
    });
    MenuDatabaseInterface::add_menu_item("Cream Cheese Bagel", MenuCategory::Sandwich, 6.49f, {
        {"Bagel Bread", 1},
        {"Cream Cheese", 1}
    });
    MenuDatabaseInterface::add_menu_item("Meat Lovers Sandwich", MenuCategory::Sandwich, 9.99f, {
        {"Bread", 1},
        {"Bacon", 2},
        {"Chicken", 2},
        {"Pork", 2},
        {"Steak", 1},
        {"Tomato Sauce", 1},
        {"Cheese", 1}
    });
    MenuDatabaseInterface::add_menu_item("Coffee", MenuCategory::HotBeverage, 3.99f, {
        {"Coffee Beans", 1},
        {"Sugar", 2}
    });
    MenuDatabaseInterface::add_menu_item("Tea", MenuCategory::HotBeverage, 3.99f, {
        {"Tea Leaves", 2},
        {"Sugar", 2}
    });
    MenuDatabaseInterface::add_menu_item("Hot Chocolate", MenuCategory::HotBeverage, 4.49f, {
        {"Sugar", 1},
        {"Chocolate", 2},
        {"Milk", 1}
    });
    MenuDatabaseInterface::add_menu_item("Large Coffee", MenuCategory::HotBeverage, 6.49f, {
        {"Coffee Beans", 2},
        {"Sugar", 3}
    });
    MenuDatabaseInterface::add_menu_item("Iced Tea", MenuCategory::ColdBeverage, 3.99f, {
        {"Sugar", 3},
        {"Lemon", 1},
        {"Tea Leaves", 1},
        {"Ice", 3}
    });
    MenuDatabaseInterface::add_menu_item("Iced Coffee", MenuCategory::ColdBeverage, 4.49f, {
        {"Sugar", 2},
        {"Coffee Beans", 2},
        {"Ice", 5}
    });
    MenuDatabaseInterface::add_menu_item("Large Iced Cofee", MenuCategory::ColdBeverage, 7.49f, {
        {"Sugar", 3},
        {"Coffe Beans", 4},
        {"Ice", 8}
    });
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
    users.clear();
}

void IngredientDatabase::cleanup() {
    // nothing to do, no dynamically allocated contents
}

void MenuDatabase::cleanup() {
    qDeleteAll(menu_items);
    menu_items.clear();
}
