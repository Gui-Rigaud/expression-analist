#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>

class Expression {
private:
    std::string current_token;
public:
    Expression();
    Expression(std::string token);
    ~Expression();

    virtual Expression* parse_exp();
    virtual Expression* parse_or_exp();
    virtual Expression* parse_and_exp();
    virtual Expression* parse_eq_exp();
    virtual Expression* parse_rel_exp();
    virtual Expression* parse_add_exp();
    virtual Expression* parse_mul_exp();
    virtual Expression* parse_unary_exp();
    virtual Expression* parse_primary_exp();
    virtual Expression* parse_literal();

    virtual void read_next_token();
    virtual std::string get_token();
};

#endif