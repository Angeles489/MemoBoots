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

    buttonClose = new QPushButton("abandonar", this);
    layout->addWidget(buttonClose);

    connect(buttonClose, &QPushButton::clicked, this, &Card::on_buttonCloseClicked);

    setLayout(layout);
}

void Card::on_buttonCloseClicked()
{
    this->close(); // Cierra la ventana de la tarjeta
}