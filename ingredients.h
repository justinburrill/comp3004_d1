#ifndef INGREDIENTS_H
#define INGREDIENTS_H

#include <qstring.h>

class IngredientDatabase {
private:
    static QMap<QString, uint> ingredients;
public:

    // get amount of ingredient in the database
    static uint get_count(QString ingredient_name);
    // add to the amount of ingredient in the database
    static void add_count(QString ingredient_name, uint count);
    // ... or list of ingredients
    static void add_count(QMap<QString, uint> ingredients);
    // subtract from the amount of ingredient in the database
    static void subtract_count(QString ingredient_name, uint count);
    // ... or list of ingredients
    static void subtract_count(QMap<QString, uint> ingredients);
    // check if we have enough of an ingredient
    bool have_enough(QString ingredient_name, uint count);
    // ... or list of ingredients
    bool have_enough(QMap<QString, uint> ingredients);

    static void cleanup();
};

#endif // INGREDIENTS_H
