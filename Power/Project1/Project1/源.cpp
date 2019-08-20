#include <iostream>
#include <cmath>

using namespace::std;

//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

class Solution {
public:
	double Power(double base, int exponent) {
		if (exponent == 0)
		{
			return 1.0;
		}
		double res = base;
		int n = abs(exponent);
		for (int uLoop = 1; uLoop < n; uLoop++)
		{
			res *= base;
		}
		return exponent > 0 ? res : 1 / res;
		//return pow(base, exponent);
	}
};

int main()
{

	return 0;
}