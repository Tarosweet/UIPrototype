#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <QString>
#include <QStringList>
#include "instruction.h"

class Interpreter
{
public:
    Interpreter();
    ~Interpreter(){}

public:
    char* parseLine(QStringList);
};

#endif // INTERPRETER_H
