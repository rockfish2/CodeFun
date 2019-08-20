#include <iostream>
#include <vector>
using namespace::std;

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		if (array.empty())return false;
		//if (target < array[0][0])return false;
		int _length = array.size();
		for (int i = 0; i < _length; i++)
		{
			if (array[i].empty())continue;

			else if (target >= array[i][0])
			{
				if (target <= array[i][array[i].size() - 1])//array[i].size() - 1
				{
					//for (int j = array[i].size() - 1; j >= 0; j--)
					//{
					//	if (target == array[i][j])return 1;
					//	else if (target > array[i][j])break;
					//}
					//int len = array[i].size();
					int low = 0, high = array[i].size() - 1,mid;
					while (low<=high)
					{
						mid = (low+high) / 2;
						if (target == array[i][mid])
							return true;
						else if (target > array[i][mid])
							low = mid + 1;
						else
							high = mid - 1;

					}
					//return false;
				}
				else
					continue;
				
			}
			//else return false;
		}
		return false;
	}




};

bool BinarySearch(int target, vector<int> array)
{
	int size = array.size();
	int low = 0, high = size - 1;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (array[mid] == target)
			return true;
		if (array[mid] > target)
			high = mid - 1;
		else
			low = high - 1;
	}
	return false;
}
int main(void)
{
	//int b[] = { 1,2,3,4,5,6,7 };
	vector<vector<int>> a = { {1, 2, 8, 9},{2, 4, 9, 12},{4, 7, 10, 13},{6, 8, 11, 15} };
	Solution s;

	bool c = s.Find(7, a);
	//int length = a.size();
	system("pause");

}