#ifndef ERROR_H
#define ERROR_H

#include <exception>
#include <string>

class Error : public std::exception {
private:
    std::string msg_;
public:
    explicit Error(const std::string& message) : msg_(message) {}
    virtual const char* what() const noexcept override {
        return msg_.c_str();
    }
};

#endif