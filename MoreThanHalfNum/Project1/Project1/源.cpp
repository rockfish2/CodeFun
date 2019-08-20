#include <iostream>
#include <vector>

using namespace::std;


class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		if (numbers.empty()) 
			return 0;

		// ����ÿ��Ԫ�أ�����¼����������ǰһ��Ԫ����ͬ���������1�����������1
		int result = numbers[0];
		int times = 1; // ����

		for (int i = 1; i < numbers.size(); ++i)
		{
			if (times == 0)
			{
				// ����result��ֵΪ��ǰԪ�أ����ô���Ϊ1
				result = numbers[i];
				times = 1;
			}
			else if (numbers[i] == result)
			{
				++times; // ��ͬ���1
			}
			else
			{
				--times; // ��ͬ���1               
			}
		}//Ѱ�ҳ��ִ���������

		// �ж�result�Ƿ���������������ִ����������鳤�ȵ�һ��
		times = 0;
		for (int i = 0; i < numbers.size(); ++i)
		{
			if (numbers[i] == result) 
				++times;
		}

		return (times > numbers.size() / 2) ? 1 : 0;
	}
};

int main()
{

	return 0;
}