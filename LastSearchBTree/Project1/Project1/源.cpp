#include <iostream>
#include <vector>
using namespace::std;

//����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
//����������Yes, �������No��
//�������������������������ֶ�������ͬ��



//˼·��
//��֪�����������������һ��ֵΪroot������������������ֵ����rootС��������ֵ����root��
//1��ȷ��root��
//2���������У���ȥroot��㣩���ҵ���һ������root��λ�ã����λ�����Ϊ���������ұ�Ϊ��������
//3����������������������С��root��ֵ����ֱ�ӷ���false��
//4���ֱ��ж����������������Ƿ����Ƕ��������������ݹ鲽��1��2��3��

class Solution {
public://���ڶ�����������ʹ�õݹ���ʽ
	bool VerifySquenceOfBST(vector<int> sequence) {//����ǰ�˵�˼·
		vector<int > leftTree, rightTree;
		if (sequence.empty())
			return false;

		int len = sequence.size();
		int root = sequence[len - 1];
		int i = 0;
		for (i = 0; i < len - 1; i++)
		{

			if (sequence[i] > root)
				break;
		}
		for (int j = i; j < len - 1; ++j)
		{

			rightTree.push_back(sequence[j]);
			if (sequence[j] < root)
			{
				return false;
			}
		}
		if (i != 0)
		{
			// ����������
			for (int m = 0; m < i; ++m)
			{
				leftTree.push_back(sequence[m]);
			}
		}
		if (!leftTree.empty())
			VerifySquenceOfBST(leftTree);
		if (!rightTree.empty())
			VerifySquenceOfBST(rightTree);
		return true;
	}
};

int main()
{
	int i = 0;
	for (;i>0;i++)
	{
		cout << "in to for:" << endl;
	}
	cout << "out to for:" << endl;
	return 0;
}