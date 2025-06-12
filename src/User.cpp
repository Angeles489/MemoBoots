#include "User.h"
#include <QDebug>

User::User(const QString& name) : name_(name) {}

QString User::getName() const {
    return name_;
}

void User::setName(const QString& name) {
    name_ = name;
}



bool User::operator==(const User& other) const {
    return name_ == other.name_;
}

QDebug operator<<(QDebug dbg, const User& user) {
    dbg.nospace() << "Usuario(nombre=\"" << user.getName() << "\")";
    return dbg.space();
}