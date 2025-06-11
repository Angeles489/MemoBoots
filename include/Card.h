#pragma once
#include <QWidget>
#include <QPushButton>

class Card : public QWidget
{
    Q_OBJECT
public:
    explicit Card(QWidget *parent = nullptr);
    ~Card() override = default;
private slots:
    void on_buttonCloseClicked();
private:
    QPushButton *buttonClose;
};