#include <qstring.h>
#include <qmap.h>
#include "ingredients.h"
#include "fakedatabases.h"

uint IngredientDatabaseInterface::get_count(QString ingredient_name) {
    return IngredientDatabase::ingredients.value(ingredient_name, 0);
}

void IngredientDatabaseInterface::add_count(QString ingredient_name, uint count) {
    if (!IngredientDatabase::ingredients.contains(ingredient_name)) {
        // set default if it doesn't exist
        IngredientDatabase::ingredients[ingredient_name] = 0;
    }
    IngredientDatabase::ingredients[ingredient_name] += count;
}

void IngredientDatabaseInterface::add_count(QMap<QString, uint> new_ingredients) {
    for (auto it = new_ingredients.begin(); it != new_ingredients.end(); ++it) {
        IngredientDatabaseInterface::add_count(it.key(), it.value());
    }
}

void IngredientDatabaseInterface::subtract_count(QString ingredient_name, uint count) {
    IngredientDatabaseInterface::add_count(ingredient_name, -count);
}

void IngredientDatabaseInterface::subtract_count(QMap<QString, uint> new_ingredients) {
    for (auto it = new_ingredients.begin(); it != new_ingredients.end(); ++it) {
        IngredientDatabaseInterface::add_count(it.key(), it.value());
    }
}

bool IngredientDatabaseInterface::have_enough(QString ingredient_name, uint count) {
    return IngredientDatabaseInterface::get_count(ingredient_name) >= count;
}

bool IngredientDatabaseInterface::have_enough(QMap<QString, uint> new_ingredients) {
    bool ret = true;
    for (auto it = new_ingredients.begin(); it != new_ingredients.end(); ++it) {
        ret = ret && IngredientDatabaseInterface::have_enough(it.key(), it.value());
    }
    return ret;
}
