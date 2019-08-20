#include <iostream>
//#include
//大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
//n <= 39
class Solution {
public:
	int Fibonacci(int n) {
		if (1==n)
			return 1;
		if (2 == n)
			return 1;
		if (0 == n)
			return 0;
		int before = 1,now = 1;
		int n1 = (n-1) / 2;
		for (int i=0; i<n1 ;i++)
		{
			now = before + now;
			before = now + before;

		}
		if ((n-1) % 2)
			return before;
		else
			return now;

	}
};

int main()
{
	Solution s;
	int a = s.Fibonacci(6);
	return 0;
}




























