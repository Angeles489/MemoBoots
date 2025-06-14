#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVector>
#include "Question.h"
#include <QObject.h>
#include "User.h"
#include <QMediaPlayer>
#include <QAudioOutput>

class Card : public QWidget {
    Q_OBJECT

public:
    explicit Card(User* user = nullptr, QWidget* parent = nullptr);

private slots:
    void checkAnswer();

private:
    QMediaPlayer* backgroundMusic_;
    QAudioOutput* audioOutput_;
    QLabel *questionLabel;
    QVector<QPushButton*> optionButtons;
    QVector<Question*> questions;
    int currentQuestionIndex;

    User* user_;

    void loadQuestions();
    void showQuestion(int index);
};