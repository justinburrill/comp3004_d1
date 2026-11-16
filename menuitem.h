#ifndef MENUITEM_H
#define MENUITEM_H

#include <qstring.h>
#include <qmap.h>
#include <QList>

enum class MenuCategory {Sandwich, HotBeverage, ColdBeverage};

class MenuItem {
public:
    QString name;
    MenuCategory category;
    float price;
    QMap<QString, uint> ingredients;

    MenuItem(QString name, MenuCategory category, float price, QMap<QString, uint> ingredients)
        : name(name), category(category), price(price), ingredients(ingredients)
    {}

    QString generate_menu_text();
    bool is_sold_out();
};


class MenuDatabaseInterface {
public:
    static void add_menu_item(QString name, MenuCategory category, float price, QMap<QString, uint> ingredients);

    static QList<MenuItem*> get_menu_items();
    static QList<MenuItem*> get_menu_items_by_category(MenuCategory category);
    static MenuItem* find_menu_item(const QStringView name);
};

#endif // MENUITEM_H
