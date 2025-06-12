#pragma once

#include <QString>
#include <QStringList>
#include <stdexcept>

class Question
{
public:
    virtual ~Question() = default;

    virtual QString getText() const = 0;
    virtual QStringList getOptions() const = 0;
    virtual bool checkAnswer(int index) const = 0;
};