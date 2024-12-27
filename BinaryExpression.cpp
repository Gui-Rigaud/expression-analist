#include "BinaryExpression.h"
#include "Literal.h"
#include <iostream>

BinaryExpression::BinaryExpression(Expression* left, Operand *op, Expression* right) : left(left), op(op), right(right) {}

BinaryExpression::~BinaryExpression(){ delete left; delete op; delete right; }

void BinaryExpression::display(){
    dynamic_cast<Literal<bool>*>(left)->display();
    std::cout << op->getValue();
    dynamic_cast<Literal<bool>*>(right)->display();
}