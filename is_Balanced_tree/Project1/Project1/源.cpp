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
//每碰到一个节点，就判断以该结点为根的左右子树是否是平衡二叉树（通过求左右子树的树高）
//，然后在判断该结点的左右子树为根的子树是否是平衡二叉树。
//这样就遍历树中每一个结点，对每个结点都判断是否平衡二叉树。

class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		//借助dfs
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
	//求节点高度
	//请实现一个函数，用来判断一颗二叉树是不是对称的。
	//注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
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
	struct TreeLinkNode *next; //同时包含指向父结点的指针。
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};
//给定一个二叉树和其中的一个结点，
//请找出中序遍历顺序的下一个结点并且返回。
//注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
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
//分析二叉树的下一个节点，一共有以下情况：
//1.二叉树为空，则返回空；
//2.节点右孩子存在，则设置一个指针从该节点的右孩子出发，一直沿着指向左子结点的指针找到的叶子节点即为下一个节点；
//3.节点不是根节点。如果该节点是其父节点的左孩子，则返回父节点；否则继续向上遍历其父节点的父节点，重复之前的判断，返回结果。
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