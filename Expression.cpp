#include <iostream>
#include <bits/stdc++.h>
#include "Expression.h"
#include "Error.h"
#include "Operand.cpp"
#include "BinaryExpression.cpp"
#include "UnaryExpression.cpp"
#include "Literal.cpp"

using namespace std;

Expression::Expression(string token) : current_token(token) {}

Expression::Expression() : current_token("") {}

Expression::~Expression() { current_token.clear(); }

void Expression::read_next_token() { 
	if(cin.peek() != '\n' && cin.peek() != '\0') cin >> current_token;
	else cin.ignore();
}

Expression *Expression::parse_exp() { return parse_or_exp(); }

Expression *Expression::parse_or_exp()
{
	Expression *e1 = parse_and_exp();
	
	while (current_token == "||")
	{
		Operand *op = new Operand(current_token);
		read_next_token();
		Expression *e2 = parse_and_exp();
		e1 = new BinaryExpression(e1, op, e2);
	}
	
	return e1;
}

Expression *Expression::parse_and_exp()
{
	Expression *e1 = parse_eq_exp();
	
	while (current_token == "&&")
	{
		Operand *op = new Operand(current_token);
		read_next_token();
		Expression *e2 = new Expression();
		e2 = parse_eq_exp();
		e1 = new BinaryExpression(e1, op, e2);
	}
	
	return e1;
}

Expression *Expression::parse_eq_exp()
{
	Expression *e1 = parse_rel_exp();
	
	while (current_token == "==" || current_token == "!=")
	{
		Operand *op = new Operand(current_token);
		read_next_token();
		Expression *e2 = new Expression();
		e2 = parse_rel_exp();
		e1 = new BinaryExpression(e1, op, e2);
	}
	
	return e1;
}

Expression *Expression::parse_rel_exp()
{
	Expression *e1 = parse_add_exp();
	
	while (current_token == "<" || current_token == ">" || current_token == "<=" || current_token == ">=")
	{
		Operand *op = new Operand(current_token);
		read_next_token();
		Expression *e2 = new Expression();
		e2 = parse_add_exp();
		e1 = new BinaryExpression(e1, op, e2);
	}
	
	return e1;
}

Expression *Expression::parse_add_exp()
{
	Expression *e1 = parse_mul_exp();
	
	while (current_token == "+" || current_token == "-")
	{
		Operand *op = new Operand(current_token);
		read_next_token();
		Expression *e2 = new Expression();

		if (current_token == "+")
		{
			read_next_token();
		}
		else if (current_token == "-")
		{
			if (op->getValue() == "-")
			{				
				op->setValue("+");
			}
			else if(op->getValue() == "+")
			{
				op->setValue("-");				
			}
			
			read_next_token();
		}

		e2 = parse_mul_exp();
		e1 = new BinaryExpression(e1, op, e2);
	}
	
	return e1;
}

Expression *Expression::parse_mul_exp()
{
	Expression *e1 = parse_unary_exp();
	
	while (current_token == "*" || current_token == "/")
	{
		Operand *op = new Operand(current_token);
		read_next_token();
		Expression *e2 = new Expression();
		e2 = parse_add_exp();
		e1 = new BinaryExpression(e1, op, e2);
	}
	
	return e1;
}

Expression *Expression::parse_unary_exp()
{
	while (current_token == "-")
	{
		Operand *op = new Operand(current_token);
		read_next_token();
		Expression *e = new Expression();
		e = parse_primary_exp();
		return new UnaryExpression(op, e);
	}
	
	return parse_primary_exp();
}

Expression *Expression::parse_primary_exp()
{
	while (current_token == "(")
	{
		read_next_token();
		Expression *e = new Expression(current_token);
		e = parse_exp();
		
		if (current_token != ")")
		{
			throw new Error("error");
		}

		e = e->eval();
		read_next_token();

		return e;
	}
	
	return parse_literal();
}

Expression *Expression::parse_literal()
{
	if (isdigit(current_token[0]) || isdigit(current_token[1]))
	{
		int value = std::stoi(current_token);
		read_next_token();
		return new Literal<int>(value);
	}
	else if (current_token == "true" || current_token == "false")
	{
		bool value = (current_token == "true");
		read_next_token();
		return new Literal<bool>(value);
	}
	else
	{
		throw new Error("error");
	}
}

void Expression::display()
{
	if (dynamic_cast<BinaryExpression *>(this))
	{
		BinaryExpression *b = dynamic_cast<BinaryExpression *>(this);
		b->display();
	}
	else if (dynamic_cast<UnaryExpression *>(this))
	{
		UnaryExpression *u = dynamic_cast<UnaryExpression *>(this);
		u->display();
	}
	else
	{
		if(dynamic_cast<Literal<int>*>(this))
		{
			dynamic_cast<Literal<int>*>(this)->display();
		}
		else if(dynamic_cast<Literal<bool>*>(this))
		{
			dynamic_cast<Literal<bool>*>(this)->display();
		}else
		{
			throw new Error("error");
		}
	}
	cout << endl;
}

Expression *Expression::eval()
{
	if (dynamic_cast<BinaryExpression *>(this))
	{
		BinaryExpression *b = dynamic_cast<BinaryExpression *>(this);
		return b->eval();
	}
	else if (dynamic_cast<UnaryExpression *>(this))
	{
		UnaryExpression *u = dynamic_cast<UnaryExpression *>(this);
		return u->eval();
	}
	else
	{
		return this;
	}
}