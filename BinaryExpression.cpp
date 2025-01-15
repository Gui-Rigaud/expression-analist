#include "BinaryExpression.h"
#include "Literal.h"
#include <iostream>

BinaryExpression::BinaryExpression(Expression* left, Operand *op, Expression* right) : left(left), op(op), right(right) {}

BinaryExpression::~BinaryExpression(){ delete left; delete op; delete right; }

void BinaryExpression::display(){
    if(dynamic_cast<Literal<int>*>(left)){
        dynamic_cast<Literal<int>*>(left)->display();
        std::cout << op->getValue();
        dynamic_cast<Literal<int>*>(right)->display();
    }else if(dynamic_cast<Literal<float>*>(left)){
        dynamic_cast<Literal<float>*>(left)->display();
        std::cout << op->getValue();
        dynamic_cast<Literal<float>*>(right)->display();
    }else if(dynamic_cast<Literal<bool>*>(left)){
        dynamic_cast<Literal<bool>*>(left)->display();
        std::cout << op->getValue();
        dynamic_cast<Literal<bool>*>(right)->display();
    }
}

Expression* BinaryExpression::eval(){
    return this;
}