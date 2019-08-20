#include <iostream>

#include <string>

using namespace::std;
typedef struct fun
{
	int i;
	double j;
	char k;

};

int main()
{
	int num = sizeof(fun);
	int a = 9;
	string s = to_string(a);
	//to_string()

	return 0;
}