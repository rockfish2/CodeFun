#include <iostream>

using namespace::std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
//����һ�ö����������������ȡ�
//�Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�
class Solution1 {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL)
		{
			return 0;
		}
		int left = TreeDepth(pRoot->left) + 1;
		int right = TreeDepth(pRoot->right) + 1;
		return left > right ? left : right;

	}
};

