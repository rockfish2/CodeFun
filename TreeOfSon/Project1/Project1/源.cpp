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
class Solution {
public:
	//bool TreeRoootToTree(TreeNode* pRoot1, TreeNode* pRoot2);
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool flg = false;//参考前人的思路
		if (pRoot1 == NULL || pRoot2 == NULL)
			return flg; 
		if(pRoot1->val == pRoot2->val)
			flg = TreeRoootToTree(pRoot1, pRoot2);
		if (flg == false)
			flg = HasSubtree(pRoot1->left, pRoot2);//遍历树
		if (flg == false)
			flg = HasSubtree(pRoot1->right, pRoot2);
		return flg;
	}
	bool TreeRoootToTree(TreeNode* pRoot1, TreeNode* pRoot2)
	{

		if (pRoot2 == NULL)//表明上次迭代已经完成，是末尾节点
			return true;

		if (pRoot1 == NULL)
			return false;

		if (pRoot1->val != pRoot2->val)//必须在后面的
		{
			return false;
		}

		return TreeRoootToTree(pRoot1->left, pRoot2->left) && TreeRoootToTree(pRoot1->right, pRoot2->right);

	}

};

/*思路：参考剑指offer
1、首先设置标志位result = false，因为一旦匹配成功result就设为true，
剩下的代码不会执行，如果匹配不成功，默认返回false
2、递归思想，如果根节点相同则递归调用DoesTree1HaveTree2（），
如果根节点不相同，则判断tree1的左子树和tree2是否相同，
再判断右子树和tree2是否相同
3、注意null的条件，HasSubTree中，如果两棵树都不为空才进行判断，
DoesTree1HasTree2中，如果Tree2为空，则说明第二棵树遍历完了，即匹配成功，
tree1为空有两种情况（1）如果tree1为空&&tree2不为空说明不匹配，
（2）如果tree1为空，tree2为空，说明匹配。

*/

public class Solution2 {
	public boolean HasSubtree(TreeNode root1, TreeNode root2) {
		boolean result = false;
		if (root1 != null && root2 != null) 
		{
			if (root1.val == root2.val) 
			{
				result = DoesTree1HaveTree2(root1, root2);
			}
			if (!result)
			{ 
				result = HasSubtree(root1.left, root2);
			}
			if (!result)
			{ 
				result = HasSubtree(root1.right, root2);
			}
		}
		return result;
	}
	public boolean DoesTree1HaveTree2(TreeNode root1, TreeNode root2) 
	{
		if (root1 == null && root2 != null) 
			return false;
		if (root2 == null) 
			return true;
		if (root1.val != root2.val) 
			return false;
		return DoesTree1HaveTree2(root1.left, root2.left) && DoesTree1HaveTree2(root1.right, root2.right);
	}
}

//二叉树的镜像定义：源二叉树
//8
/// \
//6   10
/// \ / \
//5  7 9 11
//镜像二叉树
//8
/// \
//10   6
/// \ / \
//11 9 7  5
//自我分析一下：左右子树的指针交换一下
class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		if (pRoot != NULL)
		{
			Change_child_pointer(pRoot);
			Mirror(pRoot->left);
			Mirror(pRoot->right);
		}

	}
	void Change_child_pointer(TreeNode *pRoot)
	{
		TreeNode *temp_child = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = temp_child;
	}
};