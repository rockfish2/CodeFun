#include <iostream>
using namespace::std;
//#include <>
//我们可以用2 * 1的小矩形横着或者竖着去覆盖更大的矩形。
//请问用n个2 * 1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
class Solution {
public:
	int rectCover(int number) {
		//fibnaci
		if (1== number)
			return 1;
		if (2 == number)
			return 2;
		int a = 1, b = 2, result ;
		number = number - 2;
		while (number--)
		{
			result = a + b;
			a = b;
			b = result;
			

		}
		return result;
	}
};

int main()
{
	Solution s;
	cout << s.rectCover(7);
	return 0;
}