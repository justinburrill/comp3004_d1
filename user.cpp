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


