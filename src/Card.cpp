#include "Card.h"
#include <QVBoxLayout>
#include <QLabel>

Card::Card(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Card");
    resize(200, 100);

    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel("card", this);
    layout->addWidget(label);
    setLayout(layout);
}