#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> result;
		if (k > input.size())
			return result;
		sort(input.begin(), input.end());
		for (int i =0;i<k;i++)
		{
			result.push_back(input[i]);
		}
		return result;
	}
};

int main()
{

	return 0;
}