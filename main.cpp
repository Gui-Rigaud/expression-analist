#include <iostream>
#include <vector>
#include "Expression.cpp"
using namespace std;

int main()
{
	vector<Expression *> expressions;
	string token;
	int count;

	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> token;
		Expression *e = new Expression(token);
		try
		{
			e = e->parse_exp();
			e->display();
		}catch(Error *e)
		{
			cout << e->what();
		}
		cout << endl;
	}

	return 0;
}