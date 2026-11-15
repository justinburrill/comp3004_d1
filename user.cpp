#include "user.h"
#include "fakedatabases.h"

User* UserDatabaseInterface::find_user(const QStringView name) {
    for (User* u : UserDatabase::users) {
        if (u->name == name || u->username == name) {
            return u;
        }
    }
    return nullptr;
}

User* UserDatabaseInterface::find_user(const uint loyalty_points_id) {
    for (User* u : UserDatabase::users) {
        CustomerUser* user = dynamic_cast<CustomerUser*>(u);
        if (user == nullptr) { continue; }
        else {
            if (user->loyalty_points_id == loyalty_points_id) {
                return u;
            }
        }
    }
    return nullptr;
}

QList<User*>* UserDatabaseInterface::get_users() {
    return &UserDatabase::users;
}
