#include "user.h"

void UserList::add_user(User* user) {
    users.push_back(user);
}

User* UserList::find_user(const QStringView name) {
    for (User* u : users) {
        if (u->name == name || u->username == name) {
            return u;
        }
    }
    return nullptr;
}

void UserList::cleanup() {
    qDeleteAll(users);
}
