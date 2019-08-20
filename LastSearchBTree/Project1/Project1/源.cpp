#include <iostream>
#include <vector>
using namespace::std;

//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
//如果是则输出Yes, 否则输出No。
//假设输入的数组的任意两个数字都互不相同。



//思路：
//已知条件：后序序列最后一个值为root；二叉搜索树左子树值都比root小，右子树值都比root大。
//1、确定root；
//2、遍历序列（除去root结点），找到第一个大于root的位置，则该位置左边为左子树，右边为右子树；
//3、遍历右子树，若发现有小于root的值，则直接返回false；
//4、分别判断左子树和右子树是否仍是二叉搜索树（即递归步骤1、2、3）

class Solution {
public://关于二叉树基本是使用递归形式
	bool VerifySquenceOfBST(vector<int> sequence) {//借助前人的思路
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
			// 即有左子树
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