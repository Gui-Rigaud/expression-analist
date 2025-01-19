#include <iostream>
#include "UnaryExpression.h"

using namespace std;

UnaryExpression::UnaryExpression(Operand *op, Expression *e) : op(op), e(e) {}

UnaryExpression::~UnaryExpression(){ delete op, e; }

void UnaryExpression::display(){
	Literal<int> *r = dynamic_cast<Literal<int>*>(this->eval());
	if(r)
	{
		cout << r->getValue();
	}else
	{
		throw new Error("error");
	}
}

Expression* UnaryExpression::eval(){
	Literal<int> *r = dynamic_cast<Literal<int>*>(e->eval());
	if (r == NULL)
	{
		throw new Error("error");
	}else
	{
		return new Literal<int>(-(r->getValue()));
	}
}