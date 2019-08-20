#include <iostream>
#include <vector>

using namespace::std;

//给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
//例如，如果输入数组{ 2,3,4,2,6,2,5,1 }及滑动窗口的大小3，
//那么一共存在6个滑动窗口，他们的最大值分别为{ 4,4,6,6,6,5 }； 
//针对数组{ 2,3,4,2,6,2,5,1 }的滑动窗口有以下6个：
//{ [2,3,4],2,6,2,5,1 }，{ 2,[3,4,2],6,2,5,1 }，
//{ 2,3,[4,2,6],2,5,1 }，{ 2,3,4,[2,6,2],5,1 }，
//{ 2,3,4,2,[6,2,5],1 }，{ 2,3,4,2,6,[2,5,1] }。
//array
class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		//思路：比较
		vector<int> result;
		
		int vector_size = num.size();
		if (num.empty() || size > vector_size ||size < 1 )//第一次提交的时候没有考虑size<1的情况
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