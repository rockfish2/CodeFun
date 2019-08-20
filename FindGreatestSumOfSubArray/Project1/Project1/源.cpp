#include <iostream>
#include <vector>

using namespace::std;
//����: {6, -3, -2, 7, -15, 1, 2, 2}, ����������������Ϊ8(�ӵ�0����ʼ, ����3��Ϊֹ)��
//��һ�����飬��������������������еĺͣ���᲻�ᱻ������ס��(�������ĳ���������1)
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int size = array.size();

		int maxsum = 0;
		int cursum = array[0];
		for (int i = 1; i < size; i++) 
		{
			if (cursum < 0)//��һ��Ҳ����С��0
				cursum = array[i];
			else
				cursum += array[i];
			if (cursum > maxsum)
			{
				maxsum = cursum;
			}
		}
		return maxsum;
	}
}; 
int main()
{

	return 0;
}