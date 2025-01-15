#include <iostream>
#include "Literal.h"
using namespace std;

template<typename T>
Literal<T>::Literal(T value): value(value) {}

template<typename T>
Literal<T>::~Literal() { value.clear(); }

template<typename T>
void Literal<T>::display(){
    cout << value;
}

template<typename T>
Expression* Literal<T>::eval(){
    return this;
}