#pragma once

#include "Question.h"

class TheoryQuestion : public Question
{
public:
    TheoryQuestion(const QString &text, const QStringList &options, int correctIndex);

    QString getText() const override;
    QStringList getOptions() const override;
    bool checkAnswer(int index) const override;

private:
    QString text_;
    QStringList options_;
    int correctIndex_;
};