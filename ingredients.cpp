#include <qstring.h>
#include <qmap.h>
#include "ingredients.h"

uint IngredientDatabase::get_count(QString ingredient_name) {
    return ingredients.value(ingredient_name, 0);
}

void IngredientDatabase::add_count(QString ingredient_name, uint count) {
    if (!ingredients.contains(ingredient_name)) {
        // set default if it doesn't exist
        ingredients[ingredient_name] = 0;
    }
    ingredients[ingredient_name] += count;
}

void IngredientDatabase::add_count(QMap<QString, uint> new_ingredients) {
    for (auto it = new_ingredients.begin(); it != new_ingredients.end(); ++it) {
        IngredientDatabase::add_count(it.key(), it.value());
    }
}

void IngredientDatabase::subtract_count(QString ingredient_name, uint count) {
    IngredientDatabase::add_count(ingredient_name, -count);
}

void IngredientDatabase::subtract_count(QMap<QString, uint> new_ingredients) {
    for (auto it = new_ingredients.begin(); it != new_ingredients.end(); ++it) {
        IngredientDatabase::add_count(it.key(), it.value());
    }
}

bool IngredientDatabase::have_enough(QString ingredient_name, uint count) {
    return IngredientDatabase::get_count(ingredient_name) >= count;
}

bool IngredientDatabase::have_enough(QMap<QString, uint> new_ingredients) {
    bool ret = true;
    for (auto it = new_ingredients.begin(); it != new_ingredients.end(); ++it) {
        ret = ret && IngredientDatabase::have_enough(it.key(), it.value());
    }
    return ret;
}

void IngredientDatabase::cleanup() {
    // nothing to do
}
