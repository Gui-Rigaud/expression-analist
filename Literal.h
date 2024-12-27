#ifndef LITERAL_H_
#define LITERAL_H_

#include "Expression.h"

template<typename E> class Literal: public Expression{
private:
    E value;
public:
    Literal();
    Literal(E value);

    void display();

    ~Literal();
};

#endif