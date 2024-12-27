#include <iostream>
#include "Literal.h"
using namespace std;

template<typename E>
Literal<E>::Literal(E value): value(value) {}

template<typename E>
void Literal<E>::display(){
    cout << value;
}

template<typename E>
Literal<E>::~Literal() { value.clear(); }