#ifndef E_H_
#define E_H_

class E{
public:
    E();
    ~E();
    virtual void display() = 0;
    virtual E* eval() = 0;
};

#endif