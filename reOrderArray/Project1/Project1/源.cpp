#include <iostream>
#include <vector>
using namespace::std;
//����һ���������飬ʵ��һ�����������������������ֵ�˳��
//ʹ�����е�����λ�������ǰ�벿�֣�
//���е�ż��λ������ĺ�벿�֣�
//����֤������������ż����ż��֮������λ�ò��䡣
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int len = array.size();
		vector<int> a, b;
		int j = 0;
		for (int i=0;i<len;i++)
		{
			if(array[i]%2)
				a.push_back(array[i]);
			else
				b.push_back(array[i]);
		}

		for (int i =0;i<a.size();i++)
		{
			array[j++] = a[i];

		}
		for (int i = 0; i < b.size(); i++)
		{
			array[j++] = b[i];
		}
	}
};



