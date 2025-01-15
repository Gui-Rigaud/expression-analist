#include <iostream>
#include <vector>
#include "Expression.cpp"
using namespace std;

int main() {
    vector<Expression*> expressions;
    string token;
    int count;

    // cin >> count;
    // for(int i = 0; i < count; i++) {
    //     while(cin >> token){
    //         Expression *e = new Expression(token);
    //         e = e->parse_exp();
    //         expressions.push_back(e);
    //     }
    // }

    cin >> token;
    Expression *e = new Expression();
    e = e->parse_exp();

    BinaryExpression *b = dynamic_cast<BinaryExpression*>(e);

    if(b){
        b->display();
    }else{
        cout << "There is no binary expression" << endl;
    }

    return 0;
}