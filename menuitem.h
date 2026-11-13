#ifndef MENUITEM_H
#define MENUITEM_H

#include <qstring.h>
#include <qmap.h>

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
};


class MenuDatabase {
private:
    static QList<MenuItem*> menu_items;

public:

    static void cleanup();
};

#endif // MENUITEM_H
