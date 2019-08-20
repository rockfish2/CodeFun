#include <iostream>
#include  <vector>

using namespace::std;

//请设计一个函数，用来判断在一个矩阵中是否存。
//路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
//如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。
//例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，
//但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，
//路径不能再次进入该格子。
class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		//问题：1，找出起始位置2，多个起始位置怎么办3，标记怎么处理
		if (matrix == NULL || rows<1|| cols<1 || str==NULL)
			return false;
		bool *flg = new bool[rows*cols];

		memset(flg, 0, rows*cols*sizeof(bool));

		int path_length = 0;
		for (int row=0; row< rows; row++)
		{
			for (int col=0; col< cols; col++)
			{
				if (hasPathCore(matrix, rows, cols, row, col, str, path_length, flg))
				{
					return true;
					delete[] flg;
				}


			}
		}
		delete[] flg;
		return false;

	}
	bool hasPathCore(char* matrix, int rows, int cols, int row, int col, char* str, int& pathLength, bool* visited)
	{
		if (str[pathLength] == '\0')
			return true;
		bool hasPath = false;
		if (row>=0&& row<rows&&
			col>=0 && col < cols&&
			matrix[row*cols + col] == str[pathLength]&&
			!visited[row*cols + col])
		{
			pathLength++;
			visited[row*cols + col] = true;
			hasPath =
				hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited)
				|| hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited)
				|| hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited)
				|| hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited);
			if (!hasPath)
			{
				--pathLength;
				visited[row*cols + col] = false;
			}

		}
		return hasPath;
	}



};

//地上有一个m行和n列的方格。一个机器人从坐标0, 0的格子开始移动，
//每一次只能向左，右，上，下四个方向移动一格，
//但是不能进入行坐标和列坐标的数位之和大于k的格子。
//例如，当k为18时，机器人能够进入方格（35, 37），
//因为3 + 5 + 3 + 7 = 18。但是，它不能进入方格（35, 38），
//因为3 + 5 + 3 + 8 = 19。请问该机器人能够达到多少个格子？
//适用于方格子的行走

class Solution_move {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		//问题：多少各个子？格子的数全部相加
		if (threshold < 0 || rows <= 0 || cols <= 0)
			return 0;
		bool* visited = new bool[rows*cols];

		memset(visited, false, rows*cols);
		int count = movingCountCore(threshold, rows, cols, 0, 0, visited);//0，0开始的


		delete[] visited;
		return count;
	}
private:
	int movingCountCore(int limitation, int rows, int cols, int row, int col, bool* visited) {
		int count = 0;

		if (check(limitation, rows, cols, row, col, visited))
		{
			//标记格子已经走过
			visited[row*cols + col] = true;

			//尝试向上下左右走出一步
			count = 1 + movingCountCore(limitation, rows, cols, row, col - 1, visited)
				+ movingCountCore(limitation, rows, cols, row, col + 1, visited)
				+ movingCountCore(limitation, rows, cols, row - 1, col, visited)
				+ movingCountCore(limitation, rows, cols, row + 1, col, visited);
		}

		return count;
	}


	bool check(int limitation, int rows, int cols, int row, int col, bool* visited) {

		if (row >= 0 && row < rows&&
			col >= 0 && col < cols &&
			!visited[row*cols + col] &&
			getSum(row) + getSum(col) <= limitation)
			return true;

		return false;
	}


	int getSum(int number) 
	{
		int sum = 0;
		while (number > 0) 
		{
			sum += number % 10;
			number /= 10;
		}
		return sum;
	}

};




int main()
{
	//bool* visited = new bool[5*4];
	//visited[1] = false;

	Solution_move move_f;
	move_f.movingCount(16, 6, 6);

	return 0;
}