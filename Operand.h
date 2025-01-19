#ifndef OPERAND_H
#define OPERAND_H

#include <iostream>
using namespace std;

class Operand {
private:
	string value;
public:
	Operand();
	Operand(string value);
	~Operand();

	string getValue();
	void setValue(string value);
};

#endif