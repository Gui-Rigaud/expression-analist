#ifndef LITERAL_H_
#define LITERAL_H_

#include "Expression.h"

template<typename T> class Literal: public Expression {
private:
	T value;
public:
	Literal();
	Literal(T value);
	
	~Literal();
	
	Literal<T>* operator+(const Literal<T>& r);
	Literal<T>* operator-(const Literal<T>& r);
	Literal<T>* operator*(const Literal<T>& r);
	Literal<T>* operator/(const Literal<T>& r);
	Literal<bool>* operator==(const Literal<T>& r);
	Literal<bool>* operator>=(const Literal<T>& r);
	Literal<bool>* operator<=(const Literal<T>& r);
	Literal<bool>* operator>(const Literal<T>& r);
	Literal<bool>* operator<(const Literal<T>& r);
	
	Literal<bool>* operator&&(const Literal<bool>& r);
	Literal<bool>* operator||(const Literal<bool>& r);

	T getValue();

	void display();
	Expression* eval();
};

#endif