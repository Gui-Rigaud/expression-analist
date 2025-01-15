#include <iostream>
#include <bits/stdc++.h>
#include "Expression.h"
#include "Error.h"
#include "Operand.cpp"
#include "BinaryExpression.cpp"
#include "UnaryExpression.cpp"
#include "Literal.cpp"

using namespace std;

static vector<string> operators = {
    "||", "&&", "==", "!=", "<", ">", "<=", ">=", "+", "-", "*", "/", "-", "(", ")"
};

// Expression *e1 = new Expression();

bool isOperand;

Expression::Expression(string token) : current_token(token) {}

Expression::Expression() : current_token("") {}

Expression::~Expression(){ current_token.clear(); }

void Expression::read_next_token(){ cin >> current_token; }

Expression* Expression::parse_exp(){ return parse_or_exp(); }

Expression* Expression::parse_or_exp()
{
    isOperand = false;

    Expression *e1 = parse_and_exp(NULL);
    read_next_token();
    if (current_token == "||"){
        Operand *op = new Operand(current_token);
        read_next_token();
        Expression *e2 = parse_and_exp(NULL);
        return new BinaryExpression(e1, op, e2);
    }else if
    (std::find(operators.begin(), operators.end(), current_token) != operators.end()){
        isOperand = true;
        return parse_and_exp(e1);
    }
    else{
        return e1;
    }
}

Expression* Expression::parse_and_exp(Expression *prev_token)
{
    Expression *e1 = new Expression();
    if(!isOperand && (prev_token == NULL)) e1 = parse_eq_exp(NULL);
    else e1 = prev_token;
    if (current_token == "&&"){
        Operand *op = new Operand(current_token);
        read_next_token();
        Expression *e2 = new Expression();
        e2 = parse_eq_exp(NULL);
        return new BinaryExpression(e1, op, e2);
    }else if(isOperand){
        return parse_eq_exp(e1);
    }
    else{
        return e1;
    }
}

Expression* Expression::parse_eq_exp(Expression *prev_token)
{
    Expression *e1 = new Expression();
    if(!isOperand && (prev_token == NULL)) e1 = parse_rel_exp(NULL);
    else e1 = prev_token;
    if (current_token == "==" || current_token == "!="){
        Operand *op = new Operand(current_token);
        read_next_token();
        Expression *e2 = new Expression();
        e2 = parse_rel_exp(NULL);
        return new BinaryExpression(e1, op, e2);
    }else if
    (isOperand){
        return parse_rel_exp(e1);
    }
    else{
        return e1;
    }
}

Expression* Expression::parse_rel_exp(Expression *prev_token)
{
    Expression *e1 = new Expression();
    if(!isOperand && (prev_token == NULL)) e1 = parse_add_exp(NULL);
    else e1 = prev_token;
    if (current_token == "<" || current_token == ">" || current_token == "<=" || current_token == ">="){
        Operand *op = new Operand(current_token);
        read_next_token();
        Expression *e2 = new Expression();
        e2 = parse_add_exp(NULL);
        return new BinaryExpression(e1, op, e2);
    }else if
    (isOperand){
        return parse_add_exp(e1);
    }
    else{
        return e1;
    }
}

Expression* Expression::parse_add_exp(Expression *prev_token)
{
    Expression *e1 = new Expression();
    if(!isOperand && (prev_token == NULL)) e1 = parse_mul_exp(NULL);
    else e1 = prev_token;
    if (current_token == "+" || current_token == "-"){
        Operand *op = new Operand(current_token);
        read_next_token();
        Expression *e2 = new Expression();
        e2 = parse_mul_exp(NULL);
        return new BinaryExpression(e1, op, e2);
    }else if
    (isOperand){
        return parse_mul_exp(e1);
    }
    else{
        return e1;
    }
}

Expression* Expression::parse_mul_exp(Expression *prev_token)
{
    Expression *e1 = new Expression();
    if(!isOperand && (prev_token == NULL)) e1 = parse_unary_exp();
    else e1 = prev_token;
    if (current_token == "*" || current_token == "/"){
        Operand *op = new Operand(current_token);
        read_next_token();
        Expression *e2 = new Expression();
        e2 = parse_unary_exp();
        return new BinaryExpression(e1, op, e2);
    }else{
        return e1;
    }
}

Expression* Expression::parse_unary_exp()
{
    if (current_token == "-"){
        Operand *op = new Operand(current_token);
        read_next_token();
        Expression *e = new Expression();
        e = parse_primary_exp();
        return new UnaryExpression(op, e);
    }
    else{
        return parse_primary_exp();
    }
}

Expression* Expression::parse_primary_exp()
{
    if (current_token == "("){
        read_next_token();
        Expression *e = new Expression(current_token);
        e = parse_exp();
        read_next_token();
        if (current_token != ")"){
            throw new Error("error");
        }
        return e;
    }else{
        return parse_literal();
    }
}

Expression* Expression::parse_literal(){
    if (isdigit(current_token[0])) {
        int value = std::stoi(current_token);
        return new Literal<int>(value);
    } else if (current_token == "true" || current_token == "false") {
        bool value = (current_token == "true");
        return new Literal<bool>(value);
    } else {
        throw new Error("error");
    }
}

string Expression::get_token(){ return current_token; }

Expression* Expression::operator-(const Expression& e){
    return parse_literal();
}

void Expression::display(){
    cout << current_token;
}

Expression* Expression::eval(){
    cout << "evaluating" << endl;
}