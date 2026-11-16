#include "menuitem.h"
#include "ingredients.h"
#include "fakedatabases.h"
#include <QList>

static QList<MenuItem*> menu_items;

void MenuDatabaseInterface::add_menu_item(QString name, MenuCategory category, float price, QMap<QString, uint> ingredients) {
    MenuDatabase::menu_items.push_back(new MenuItem(name, category, price, ingredients));
}

QList<MenuItem*> MenuDatabaseInterface::get_menu_items() {
    return MenuDatabase::menu_items;
}

QList<MenuItem*> MenuDatabaseInterface::get_menu_items_by_category(MenuCategory category) {
    QList<MenuItem*> out = QList<MenuItem*>();
    for (MenuItem *item : MenuDatabase::menu_items) {
        if (item->category == category) {
            out.push_back(item);
        }
    }
    return out;
}

MenuItem* MenuDatabaseInterface::find_menu_item(const QStringView name) {
    for (MenuItem* item : MenuDatabase::menu_items) {
        if (item->name == name) {
            return item;
        }
    }
    return nullptr;
}

QString MenuItem::generate_menu_text() {
    return QString("%1 %2").arg(name, 30).arg(price);
}

bool MenuItem::is_sold_out() {
    return !IngredientDatabaseInterface::have_enough(ingredients);
}
