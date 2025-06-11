#pragma once
#include <QWidget>

class Card : public QWidget
{
    Q_OBJECT
public:
    explicit Card(QWidget *parent = nullptr);
};