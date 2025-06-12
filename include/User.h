#pragma once
#include <QString>
#include <QDebug>

class User {
public:
    explicit User(const QString& name = "");
    QString getName() const;
    void setName(const QString& name);

    bool operator==(const User& other) const;

    // Para imprimir el usuario con qDebug()
    friend QDebug operator<<(QDebug dbg, const User& user);

private:
    QString name_;
};