#include <iostream>
#include  <vector>

using namespace::std;

//�����һ�������������ж���һ���������Ƿ�档
//·�����ԴӾ����е�����һ�����ӿ�ʼ��ÿһ�������ھ������������ң����ϣ������ƶ�һ�����ӡ�
//���һ��·�������˾����е�ĳһ�����ӣ���֮�����ٴν���������ӡ�
//���� a b c e s f c s a d e e ������3 X 4 �����а���һ���ַ���"bcced"��·����
//���Ǿ����в�����"abcb"·������Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��
//·�������ٴν���ø��ӡ�
class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		//���⣺1���ҳ���ʼλ��2�������ʼλ����ô��3�������ô����
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

//������һ��m�к�n�еķ���һ�������˴�����0, 0�ĸ��ӿ�ʼ�ƶ���
//ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ��
//���ǲ��ܽ�������������������λ֮�ʹ���k�ĸ��ӡ�
//���磬��kΪ18ʱ���������ܹ����뷽��35, 37����
//��Ϊ3 + 5 + 3 + 7 = 18�����ǣ������ܽ��뷽��35, 38����
//��Ϊ3 + 5 + 3 + 8 = 19�����ʸû������ܹ��ﵽ���ٸ����ӣ�
//�����ڷ����ӵ�����

class Solution_move {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		//���⣺���ٸ����ӣ����ӵ���ȫ�����
		if (threshold < 0 || rows <= 0 || cols <= 0)
			return 0;
		bool* visited = new bool[rows*cols];

		memset(visited, false, rows*cols);
		int count = movingCountCore(threshold, rows, cols, 0, 0, visited);//0��0��ʼ��


		delete[] visited;
		return count;
	}
private:
	int movingCountCore(int limitation, int rows, int cols, int row, int col, bool* visited) {
		int count = 0;

		if (check(limitation, rows, cols, row, col, visited))
		{
			//��Ǹ����Ѿ��߹�
			visited[row*cols + col] = true;

			//���������������߳�һ��
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