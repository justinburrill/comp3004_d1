#include "user.h"

void UserDatabase::add_user(User* user) {
    users.push_back(user);
}

User* UserDatabase::find_user(const QStringView name) {
    for (User* u : users) {
        if (u->name == name || u->username == name) {
            return u;
        }
    }
    return nullptr;
}

void UserDatabase::cleanup() {
    qDeleteAll(users);
}
