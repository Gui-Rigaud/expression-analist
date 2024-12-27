#include <iostream>
#include "Operand.h"

Operand::Operand(std::string value) : value(value) {}

Operand::~Operand(){ value.clear(); }

std::string Operand::getValue(){ return value; }