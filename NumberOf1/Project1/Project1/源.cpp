#include <iostream>

using namespace::std;
class Solution {
public:
	int  NumberOf1(int n) {
		//��λ������,ȫ���ò����ʾ
		int i = 1,count=0,n = 0;
		while (i)
		{
			if (n&i)
				count++;
			i = i << 1;//����1λ��
		}

		return count;
	}
};

int main()
{
	Solution s;
	s.NumberOf1(2);
	return 0;


}







