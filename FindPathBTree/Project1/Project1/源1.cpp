#include <iostream>
#include <vector>
using  namespace::std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
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