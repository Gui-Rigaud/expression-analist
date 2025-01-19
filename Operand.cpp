#include <iostream>
#include "Operand.h"

using namespace std;

Operand::Operand(string value) : value(value) {}

Operand::~Operand(){ value.clear(); }

string Operand::getValue(){ return value; }

void Operand::setValue(string value){ this->value = value; }