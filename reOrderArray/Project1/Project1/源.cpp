#include <iostream>
#include <vector>
using namespace::std;
//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
//使得所有的奇数位于数组的前半部分，
//所有的偶数位于数组的后半部分，
//并保证奇数和奇数，偶数和偶数之间的相对位置不变。
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



