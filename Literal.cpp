#include <iostream>
#include "Literal.h"
using namespace std;

template <typename T>
Literal<T>::Literal() {}

template <typename T>
Literal<T>::Literal(T value) : value(value) {}

template <typename T>
Literal<T>::~Literal()
{
	value = 0;
}

template <typename T>
void Literal<T>::display()
{
	if (typeid(value) == typeid(bool))
	{
		if (value)
			cout << "true";
		else
			cout << "false";
	}
	else
		cout << value;
}

template <typename T>
Expression *Literal<T>::eval()
{
	return this;
}

template <typename T>
Literal<T> *Literal<T>::operator+(const Literal<T> &r)
{
	return new Literal<T>(this->value + r.value);
}

template <typename T>
Literal<T> *Literal<T>::operator-(const Literal<T> &r)
{
	return new Literal<T>(this->value - r.value);
}

template <typename T>
Literal<T> *Literal<T>::operator*(const Literal<T> &r)
{
	return new Literal<T>(this->value * r.value);
}

template <typename T>
Literal<T> *Literal<T>::operator/(const Literal<T> &r)
{
	return new Literal<T>(this->value / r.value);
}

template <typename T>
Literal<bool> *Literal<T>::operator==(const Literal<T> &r)
{
	return new Literal<bool>(this->value == r.value);
}

template <typename T>
Literal<bool> *Literal<T>::operator>=(const Literal<T> &r)
{
	return new Literal<bool>(this->value >= r.value);
}

template <typename T>
Literal<bool> *Literal<T>::operator<=(const Literal<T> &r)
{
	return new Literal<bool>(this->value <= r.value);
}

template <typename T>
Literal<bool> *Literal<T>::operator>(const Literal<T> &r)
{
	return new Literal<bool>(this->value > r.value);
}

template <typename T>
Literal<bool> *Literal<T>::operator<(const Literal<T> &r)
{
	return new Literal<bool>(this->value < r.value);
}

template <typename T>
Literal<bool> *Literal<T>::operator&&(const Literal<bool> &r)
{
	return new Literal<bool>(this->value && r.value);
}

template <typename T>
Literal<bool> *Literal<T>::operator||(const Literal<bool> &r)
{
	return new Literal<bool>(this->value || r.value);
}

template <typename T>
T Literal<T>::getValue()
{
	return value;
}