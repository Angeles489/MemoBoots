#pragma once

#include <QWidget>
#include <QLineEdit>
#include "User.h"

class WelcomeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit WelcomeWindow(QWidget* parent = nullptr);

signals:
    void userReady(User* user);

private slots:
    void onAccept();

private:
    QLineEdit* nameInput_;
};