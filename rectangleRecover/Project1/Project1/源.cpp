#include <iostream>
using namespace::std;
//#include <>
//���ǿ�����2 * 1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�
//������n��2 * 1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����
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