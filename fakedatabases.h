#ifndef FAKEDATABASES_H
#define FAKEDATABASES_H

#include "menuitem.h"
#include "user.h"


void setupFakeDatabases();
void cleanupFakeDatabases();

class UserDatabase {
public:
    static void add_user(User* user);
    static QList<User*> users;
    static void cleanup();
};

class MenuDatabase {
public:
    static QList<MenuItem*> menu_items;
    static void cleanup();
};

class IngredientDatabase {
public:
    static QMap<QString, uint> ingredients;
    static void cleanup();
};

#endif // FAKEDATABASES_H
