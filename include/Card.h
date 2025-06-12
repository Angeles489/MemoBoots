#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVector>
#include "Question.h"
#include <QObject.h>

class Card : public QWidget {
    Q_OBJECT

public:
    explicit Card(QWidget *parent = nullptr);

private slots:
    void checkAnswer();

private:
    QLabel *questionLabel;
    QVector<QPushButton*> optionButtons;
    QVector<Question*> questions;
    int currentQuestionIndex;

    void loadQuestions();
    void showQuestion(int index);
};