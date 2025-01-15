#ifndef BINARYEXPRESSION_H_
#define BINARYEXPRESSION_H_

#include "Expression.h"
#include "Operand.h"

class BinaryExpression : public Expression {
private:
    Expression* left;
    Operand* op;
    Expression* right;
public:
    BinaryExpression(Expression* left, Operand *op, Expression* right);
    ~BinaryExpression();
    
    void display();
    Expression* eval();
};

#endif