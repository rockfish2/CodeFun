#include <iostream>
//#include
//��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n���0��ʼ����0��Ϊ0����
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




























