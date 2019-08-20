#include <iostream>
#include <vector>

using namespace::std;
//例如: {6, -3, -2, 7, -15, 1, 2, 2}, 连续子向量的最大和为8(从第0个开始, 到第3个为止)。
//给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int size = array.size();

		int maxsum = 0;
		int cursum = array[0];
		for (int i = 1; i < size; i++) 
		{
			if (cursum < 0)//第一个也可能小于0
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