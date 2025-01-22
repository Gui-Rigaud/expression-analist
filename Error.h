#ifndef ERROR_H
#define ERROR_H

#include <iostream>
using namespace std;

class Error{
private:
	string msg;
public:
	Error(const string& message) : msg(message) {}
	
	string getMessage() const{
		return msg;
	}
};

#endif