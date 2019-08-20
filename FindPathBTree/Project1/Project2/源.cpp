#include <iostream>
#include <vector>

using  namespace::std;

typedef struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
}TreeNode;
class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == NULL)
		{
			return NULL;
		}

		if (pRootOfTree->left == NULL && pRootOfTree->right == NULL)
		{
			return pRootOfTree;
		}

		TreeNode* left = Convert(pRootOfTree->left);

		TreeNode* run_node = left;

		while (run_node && run_node->right)
		{
			run_node = run_node->right;
		}

		if (left)
		{
			run_node->right = pRootOfTree;
			pRootOfTree->left = run_node;
		}
		TreeNode* right = Convert(pRootOfTree->right);
		if (right)
		{
			right->left = pRootOfTree;
			pRootOfTree->right = right;
		}
		return left != NULL ? left : pRootOfTree;
	}
};
class Solution2 {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == NULL)
		{
			return NULL;
		}

		if (pRootOfTree->left == NULL && pRootOfTree->right == NULL)
		{
			return pRootOfTree;
		}

		TreeNode* left = Convert(pRootOfTree->left);

		TreeNode* run_node = left;

		while (run_node && run_node->right)
		{
			run_node = run_node->right;
		}

		if (left)
		{
			run_node->right = pRootOfTree;
			pRootOfTree->left = run_node;
		}
		TreeNode* right = Convert(pRootOfTree->right);
		if (right)
		{
			right->left = pRootOfTree;
			pRootOfTree->right = right;
		}
		return left != NULL ? left : pRootOfTree;
	}
};
int main()
{
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	 
	Solution s1;

	Solution2 s2;

	s1.Convert(root);
	return 0;
}
