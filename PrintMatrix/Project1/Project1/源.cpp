#include <iostream>
#include <vector>

//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
//例如，如果输入如下4 X 4矩阵：
//1 2 3 4
//5 6 7 8 
//9 10 11 12 
//13 14 15 16
//则依次打印出数字1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.

using namespace::std;

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		int h = matrix.size();  //行数
		int l = matrix[1].size();//列数
		vector<int> result;
		if (h==0 &&l==0)
			return result;
		int left = 0, right = l - 1;
		int top = 0, buttom = h - 1;
		while (left<=right && top<=buttom)
		{
			for (int i=left;i<=right;i++)//left to right
			{
				result.push_back(matrix[top][i]);
			}

			for (int i = top+1; i <= buttom; i++)//up to down
			{
				result.push_back(matrix[i][right]);
			}
			if (top != buttom)//ribght to left
			{
				for (int i = right-1; i >= left; i--)
				{
					result.push_back(matrix[buttom][i]);
				}
			}
			if (right != left)//down to up
			{
				for (int i = buttom-1 ; i > top; i--)
				{
					result.push_back(matrix[i][left]);
				}
			}

			left++, right--, top++, buttom--;
		}

		return result;
	}
};

int main()
{
	Solution s;
	vector<vector<int> > n = { {1,2,3,4}, {5,6,7,8} ,{9,10,11,12}, {13,14,15,16} };
	vector<int> result = s.printMatrix(n);

	return 0;
}