#ifndef OPERAND_H
#define OPERAND_H

#include <iostream>

class Operand {
private:
    std::string value;
public:
    Operand();
    Operand(std::string value);
    ~Operand();

    std::string getValue();
};

#endif