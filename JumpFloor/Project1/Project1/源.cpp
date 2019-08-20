#include <iostream>


//一只青蛙一次可以跳上1级台阶，也可以跳上2级。
//求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
using namespace::std;
class Solution 
{
public:
	int jumpFloor(int number) 
	{//fibnaci
		if (1==number)
			return 1;
		if (2==number)
			return 2;
		int a = 1, b = 2, result = 0;
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
//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
//求该青蛙跳上一个n级的台阶总共有多少种跳法。
class Solution_hard {
public:
	int jumpFloorII(int number) {
		if (1==number)//找规律
			return 1;
		int a = 1, b = 0, result = 0;
		number--;
		while (number--)
		{
			b = 2 * a;
			result = b;
			a = b;
		}
		return result;

	}
};

int  main()
{
	Solution s;
	Solution_hard s2;
	cout << s2.jumpFloorII(5) << endl;
	
	cout << s.jumpFloor(5) << endl;
	return 0;
}




