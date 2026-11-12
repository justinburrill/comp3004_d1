#ifndef USER_H
#define USER_H
#include <QString>
#include <QList>

enum class UserType {Cashier, KitchenStaff, Manager, SysAdmin, Customer};

class User {
public:
    QString name;
    QString username;

    User() = default;

    User(QString name, QString username)
        : name(name), username(username)
    {}

    virtual UserType get_type() const = 0;
};

class CustomerUser : public User {
public:
    static int current_loyalty_points_id; // auto-increment

    QString email;
    QString home_address;
    int loyalty_points_id;
    int loyalty_points_balance;
    int credit_balance;

    CustomerUser(QString name, QString username, QString email, QString home_address, int loyalty_points_balance = 0, int credit_balance = 0)
        : User(name, username), email(email), home_address(home_address), loyalty_points_id(current_loyalty_points_id), loyalty_points_balance(loyalty_points_balance), credit_balance(credit_balance)  {
        // increment for next customer
        current_loyalty_points_id++;
    }

    UserType get_type() const {
        return UserType::Customer;
    }
};

class StaffUser : public User {
public:
    static int current_staff_id; // auto-increment

    int staff_id;

    StaffUser(QString name, QString username) : User(name, username), staff_id(current_staff_id) {
        // increment for next staff member
        current_staff_id++;
    }

};

class KitchenStaffUser : public StaffUser {
public:
    KitchenStaffUser(QString name, QString username) : StaffUser(name, username) {}

    UserType get_type() const {
        return UserType::KitchenStaff;
    }
};

class CashierStaffUser : public StaffUser {
public:
    CashierStaffUser(QString name, QString username) : StaffUser(name, username) {}

    UserType get_type() const {
        return UserType::Cashier;
    }
};

class ManagerStaffUser : public StaffUser {
public:
    ManagerStaffUser(QString name, QString username) : StaffUser(name, username) {}

    UserType get_type() const {
        return UserType::Manager;
    }
};

class SysAdminStaffUser : public StaffUser {
public:
    SysAdminStaffUser(QString name, QString username) : StaffUser(name, username) {}

    UserType get_type() const {
        return UserType::SysAdmin;
    }
};

class UserList {
private:
    static QList<User*> users;
public:
    static void add_user(User* user);
    static User* find_user(const QStringView name);
    static void cleanup();
};

#endif // USER_H
