#include <iostream>


//һֻ����һ�ο�������1��̨�ף�Ҳ��������2����
//�����������һ��n����̨���ܹ��ж������������Ⱥ����ͬ�㲻ͬ�Ľ������
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
//һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n����
//�����������һ��n����̨���ܹ��ж�����������
class Solution_hard {
public:
	int jumpFloorII(int number) {
		if (1==number)//�ҹ���
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




