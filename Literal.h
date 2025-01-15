#ifndef LITERAL_H_
#define LITERAL_H_

#include "Expression.h"

template<typename T> class Literal: public Expression{
private:
    E value;
public:
    Literal();
    Literal(T value);

    void display();
    Expression* eval();

    ~Literal();
};

#endif