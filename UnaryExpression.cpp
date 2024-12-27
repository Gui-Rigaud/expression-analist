#include <iostream>
#include "UnaryExpression.h"

using namespace std;

UnaryExpression::UnaryExpression(Operand *op, Expression *e) : op(op), e(e) {}

UnaryExpression::~UnaryExpression(){ delete op; delete e; }