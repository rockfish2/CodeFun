#include <iostream>
#include <cmath>

using namespace::std;

//����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���

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