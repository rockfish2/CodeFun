#include <iostream>
#include <vector>

using namespace::std;

//����һ������ͻ������ڵĴ�С���ҳ����л�����������ֵ�����ֵ��
//���磬�����������{ 2,3,4,2,6,2,5,1 }���������ڵĴ�С3��
//��ôһ������6���������ڣ����ǵ����ֵ�ֱ�Ϊ{ 4,4,6,6,6,5 }�� 
//�������{ 2,3,4,2,6,2,5,1 }�Ļ�������������6����
//{ [2,3,4],2,6,2,5,1 }��{ 2,[3,4,2],6,2,5,1 }��
//{ 2,3,[4,2,6],2,5,1 }��{ 2,3,4,[2,6,2],5,1 }��
//{ 2,3,4,2,[6,2,5],1 }��{ 2,3,4,2,6,[2,5,1] }��
//array
class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		//˼·���Ƚ�
		vector<int> result;
		
		int vector_size = num.size();
		if (num.empty() || size > vector_size ||size < 1 )//��һ���ύ��ʱ��û�п���size<1�����
			return result;
		for (int i =0; i <= vector_size-size;i++)
		{
			int  temp_max = num[ i ];
			for (int j = 0;j < size;j++)
			{
				if (num[i + j] > temp_max)
				{
					temp_max = num[i + j];
				}
				
			}

			result.push_back(temp_max);
		}
		return result;

	}
};

int main()
{
	return 0;

}