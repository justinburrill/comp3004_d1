#include "menuitem.h"

void MenuDatabase::cleanup() {
    qDeleteAll(menu_items);
}
