#ifndef ERROR_H
#define ERROR_H

#include <exception>
#include <iostream>
using namespace std;

class Error : public exception {
private:
	string msg_;
public:
	explicit Error(const string& message) : msg_(message) {}
	
	virtual const char* what() const noexcept override {
		return msg_.c_str();
	}
};

#endif