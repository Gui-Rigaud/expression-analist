#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
#include "E.h"

class Expression: public E {
private:
    std::string current_token;
public:
    Expression();
    Expression(std::string token);
    ~Expression();

    virtual Expression* parse_exp();
    virtual Expression* parse_or_exp();
    virtual Expression* parse_and_exp(Expression *prev_token);
    virtual Expression* parse_eq_exp(Expression *prev_token);
    virtual Expression* parse_rel_exp(Expression *prev_token);
    virtual Expression* parse_add_exp(Expression *prev_token);
    virtual Expression* parse_mul_exp(Expression *prev_token);
    virtual Expression* parse_unary_exp();
    virtual Expression* parse_primary_exp();
    virtual Expression* parse_literal();

    virtual void read_next_token();
    virtual std::string get_token();

    Expression* operator-(const Expression& e);

    void display();
    Expression* eval();
};

#endif