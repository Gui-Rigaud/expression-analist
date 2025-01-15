#ifndef UNARYEXPRESSION_H_
#define UNARYEXPRESSION_H_

#include "Expression.h"
#include "Operand.h"

class UnaryExpression:public Expression {
private:
    Operand *op;
    Expression *e;

public:
    UnaryExpression(Operand *op, Expression *e);
    ~UnaryExpression();

    void display();
    Expression* eval();
};

#endif