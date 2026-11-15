#ifndef INGREDIENTS_H
#define INGREDIENTS_H

#include <qstring.h>

class IngredientDatabaseInterface {
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
    static bool have_enough(QString ingredient_name, uint count);
    // ... or list of ingredients
    static bool have_enough(QMap<QString, uint> ingredients);
};

#endif // INGREDIENTS_H
