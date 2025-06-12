#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include "User.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void setUser(User* user);

private slots:
    void on_buttonClicked();

private:
    User* currentUser_ = nullptr;
    QLabel      *label_;
    QPushButton *button_;
    QLineEdit   *lineEdit_;
    QTextEdit   *textEdit_;
};