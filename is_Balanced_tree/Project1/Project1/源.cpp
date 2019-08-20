#include <iostream>

using namespace::std;

typedef struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
//ÿ����һ���ڵ㣬���ж��Ըý��Ϊ�������������Ƿ���ƽ���������ͨ�����������������ߣ�
//��Ȼ�����жϸý�����������Ϊ���������Ƿ���ƽ���������
//�����ͱ�������ÿһ����㣬��ÿ����㶼�ж��Ƿ�ƽ���������

class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		//����dfs
		if (pRoot == NULL)
			return true;
		int left = deep(pRoot->left);
		int right = deep(pRoot->right);
		int diff = left - right;

		if (abs(diff)>1)
			return false;
		return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
	}
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL)
			return 0;
		int left = deep(pRoot->left)+1;
		int right = deep(pRoot->right) + 1;
		return left > right ? left : right;

	}
	//��ڵ�߶�
	//��ʵ��һ�������������ж�һ�Ŷ������ǲ��ǶԳƵġ�
	//ע�⣬���һ��������ͬ�˶������ľ�����ͬ���ģ�������Ϊ�ԳƵġ�
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (pRoot == NULL)
			return true;
		//TreeNode* pRoot;
		//if (pRoot != NULL)
		//{
		//	//Change_child_pointer(pRoot);
		//	if (pRoot->left->val != pRoot->right->val)
		//	{
		//		return false;
		//	}
		//	isSymmetrical(pRoot->left);
		//	isSymmetrical(pRoot->right);

		//	return true;
		return is_Symmetrical(pRoot->left, pRoot->right);

		}
	bool is_Symmetrical(TreeNode* leftpRoot, TreeNode* rightpRoot)
	{
		if (leftpRoot == NULL && rightpRoot == NULL)
		{
			return true;
		}
		if (leftpRoot == NULL || rightpRoot == NULL)
		{
			return false;
		}
		return leftpRoot->val == rightpRoot->val && is_Symmetrical(leftpRoot->left, rightpRoot->right);
	}

	void Change_child_pointer(TreeNode *pRoot)
	{
		TreeNode *temp_child = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = temp_child;
	}

private:
	int deep(TreeNode* pRoot)
	{
		if (pRoot == NULL)
			return 0;
		int left = deep(pRoot->left);
		int right = deep(pRoot->right);

		return (left > right) ? left + 1 : right + 1;
	}
};


//public static boolean IsBalanced_Solution(TreeNode root) {
//
//	if (root == null) {
//		return true;
//	}
//	int left = iterTree(root.left);
//	int right = iterTree(root.right);
//
//	if (Math.abs(left - right) > 1) {
//		return false;
//	}
//	return true;
//}
//
//private static int iterTree(TreeNode root) {
//	if (root == null) {
//		return 0;
//	}
//	int left = iterTree(root.left);
//	int right = iterTree(root.right);
//
//	return left > right ? (left + 1) : (right + 1);
//}



typedef struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next; //ͬʱ����ָ�򸸽���ָ�롣
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};
//����һ�������������е�һ����㣬
//���ҳ��������˳�����һ����㲢�ҷ��ء�
//ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣
/*
struct TreeLinkNode {
int val;
struct TreeLinkNode *left;
struct TreeLinkNode *right;
struct TreeLinkNode *next;
TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
}
};
*/
//��������������һ���ڵ㣬һ�������������
//1.������Ϊ�գ��򷵻ؿգ�
//2.�ڵ��Һ��Ӵ��ڣ�������һ��ָ��Ӹýڵ���Һ��ӳ�����һֱ����ָ�����ӽ���ָ���ҵ���Ҷ�ӽڵ㼴Ϊ��һ���ڵ㣻
//3.�ڵ㲻�Ǹ��ڵ㡣����ýڵ����丸�ڵ�����ӣ��򷵻ظ��ڵ㣻����������ϱ����丸�ڵ�ĸ��ڵ㣬�ظ�֮ǰ���жϣ����ؽ����
class Solution_TreeLinkNode {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == NULL)
			return NULL;
		if (pNode->right != NULL)
		{
			pNode = pNode->right;
			while (pNode->left != NULL)
				pNode = pNode->left;
			return pNode;
		}
		while (pNode->next != NULL)
		{
			TreeLinkNode *proot = pNode->next;
			if (proot->left == pNode)
				return proot;
			pNode = pNode->next;
		}
		return NULL;
	}
};
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
*/

int main()
{
	TreeNode *t1 = new TreeNode(5);
	t1->right = new TreeNode(7);
	t1->left = new TreeNode(3);
	t1->left->left = new TreeNode(2);
	t1->left->right = new TreeNode(4);
	t1->left->left->left = new TreeNode(1);
	Solution s1;
	bool flg;

	flg = s1.IsBalanced_Solution(t1);

	return 0;
}