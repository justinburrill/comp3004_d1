#include "menuitem.h"
#include "fakedatabases.h"
#include <QList>

static QList<MenuItem*> menu_items;

void MenuDatabaseInterface::add_menu_item(QString name, MenuCategory category, float price, QMap<QString, uint> ingredients) {
    MenuDatabase::menu_items.push_back(new MenuItem(name, category, price, ingredients));
}

QList<MenuItem*> MenuDatabaseInterface::get_menu_items(){
    return MenuDatabase::menu_items;
}

MenuItem* MenuDatabaseInterface::find_menu_item(const QStringView name) {
    for (MenuItem* item: MenuDatabase:: menu_items) {
        if (item->name == name) {
            return item;
        }
    }
    return nullptr;
}

void MenuDatabaseInterface::cleanup() {
    qDeleteAll(MenuDatabase::menu_items);
    MenuDatabase::menu_items.clear();
}

