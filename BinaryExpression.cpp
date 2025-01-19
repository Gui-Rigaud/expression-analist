#include "BinaryExpression.h"
#include "Literal.h"
#include "Error.h"
#include <iostream>

using namespace std;

BinaryExpression::BinaryExpression(Expression *left, Operand *op, Expression *right) : left(left), op(op), right(right) {}

BinaryExpression::~BinaryExpression(){ delete left, op, right; }

void BinaryExpression::display()
{
	if (dynamic_cast<Literal<int> *>(left) && (op->getValue() != "==" && op->getValue() != ">=" && op->getValue() != "<=" && op->getValue() != ">" && op->getValue() != "<"))
	{
		dynamic_cast<Literal<int> *>(this->eval())->display();
	}
	else if (dynamic_cast<Literal<bool> *>(left) || (op->getValue() == "==" || op->getValue() == ">=" || op->getValue() == "<=" || op->getValue() == ">" || op->getValue() == "<"))
	{
		dynamic_cast<Literal<bool> *>(this->eval())->display();
	}
	else if (dynamic_cast<BinaryExpression *>(left))
	{
		left = left->eval();
		this->display();
	}
}

Expression *BinaryExpression::eval()
{

	if (dynamic_cast<Literal<int> *>(this->left))
	{

		Expression *result = new Expression();

		bool isInt = true;

		Literal<int> *l = dynamic_cast<Literal<int> *>(this->left);

		Literal<int> *r;

		string opValue = op->getValue();

		if (dynamic_cast<Literal<int> *>(this->right))
		{
			r = dynamic_cast<Literal<int> *>(this->right);
		}
		else if (dynamic_cast<BinaryExpression *>(this->right) && (opValue == "*" || opValue == "/"))
		{
			Literal<int> *lr = dynamic_cast<Literal<int> *>(dynamic_cast<BinaryExpression *>(this->right)->left);
			if (opValue == "*")
			{
				l = *l * *lr;
			}
			else if (opValue == "/")
			{
				l = *l / *lr;
			}
			r = dynamic_cast<Literal<int> *>(dynamic_cast<BinaryExpression *>(this->right)->right->eval());
			op = dynamic_cast<BinaryExpression *>(this->right)->op;
			opValue = op->getValue();
		}
		else if (dynamic_cast<BinaryExpression *>(this->right))
		{
			r = dynamic_cast<Literal<int> *>(dynamic_cast<BinaryExpression *>(this->right)->eval());
		}
		else
		{
			throw new Error("error");
		}

		if (opValue == "+")
		{
			result = *l + *r;
		}
		else if (opValue == "-")
		{
			result = *l - *r;
		}
		else if (opValue == "*")
		{
			result = *l * *r;
		}
		else if (opValue == "/")
		{
			if (r->getValue() == 0)
				throw new Error("error");
			else
				result = *l / *r;
		}
		else if (opValue == "==")
		{
			result = *l == *r;
			isInt = false;
		}
		else if (opValue == ">=")
		{
			result = *l >= *r;
			isInt = false;
		}
		else if (opValue == "<=")
		{
			result = *l <= *r;
			isInt = false;
		}
		else if (opValue == ">")
		{
			result = *l > *r;
			isInt = false;
		}
		else if (opValue == "<")
		{
			result = *l < *r;
			isInt = false;
		}

		if (isInt)
			return dynamic_cast<Literal<int> *>(result);
		else
			return dynamic_cast<Literal<bool> *>(result);
	}
	else if (dynamic_cast<Literal<bool> *>(left))
	{
		Literal<bool> *result = new Literal<bool>();

		Literal<bool> *l = dynamic_cast<Literal<bool> *>(this->left);

		Literal<bool> *r;

		if (dynamic_cast<Literal<bool> *>(this->right))
			r = dynamic_cast<Literal<bool> *>(this->right);
		else if (dynamic_cast<BinaryExpression *>(this->right))
			r = dynamic_cast<Literal<bool> *>(dynamic_cast<BinaryExpression *>(this->right)->eval());
		else
			throw new Error("error");

		string opValue = op->getValue();

		if (opValue == "&&")
		{
			result = *l && *r;
		}
		else if (opValue == "||")
		{
			result = *l || *r;
		}
		else if (opValue == "==")
		{
			result = *l == *r;
		}

		return result;
	}
	else if (dynamic_cast<BinaryExpression *>(left))
	{
		left = dynamic_cast<BinaryExpression *>(left)->eval();
		right = right->eval();
		return this->eval();
	}
	else
	{
		throw new Error("error");
	}

	return this;
}