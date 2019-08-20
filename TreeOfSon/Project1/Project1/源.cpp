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
		bool flg = false;//�ο�ǰ�˵�˼·
		if (pRoot1 == NULL || pRoot2 == NULL)
			return flg; 
		if(pRoot1->val == pRoot2->val)
			flg = TreeRoootToTree(pRoot1, pRoot2);
		if (flg == false)
			flg = HasSubtree(pRoot1->left, pRoot2);//������
		if (flg == false)
			flg = HasSubtree(pRoot1->right, pRoot2);
		return flg;
	}
	bool TreeRoootToTree(TreeNode* pRoot1, TreeNode* pRoot2)
	{

		if (pRoot2 == NULL)//�����ϴε����Ѿ���ɣ���ĩβ�ڵ�
			return true;

		if (pRoot1 == NULL)
			return false;

		if (pRoot1->val != pRoot2->val)//�����ں����
		{
			return false;
		}

		return TreeRoootToTree(pRoot1->left, pRoot2->left) && TreeRoootToTree(pRoot1->right, pRoot2->right);

	}

};

/*˼·���ο���ָoffer
1���������ñ�־λresult = false����Ϊһ��ƥ��ɹ�result����Ϊtrue��
ʣ�µĴ��벻��ִ�У����ƥ�䲻�ɹ���Ĭ�Ϸ���false
2���ݹ�˼�룬������ڵ���ͬ��ݹ����DoesTree1HaveTree2������
������ڵ㲻��ͬ�����ж�tree1����������tree2�Ƿ���ͬ��
���ж���������tree2�Ƿ���ͬ
3��ע��null��������HasSubTree�У��������������Ϊ�ղŽ����жϣ�
DoesTree1HasTree2�У����Tree2Ϊ�գ���˵���ڶ������������ˣ���ƥ��ɹ���
tree1Ϊ�������������1�����tree1Ϊ��&&tree2��Ϊ��˵����ƥ�䣬
��2�����tree1Ϊ�գ�tree2Ϊ�գ�˵��ƥ�䡣

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

//�������ľ����壺Դ������
//8
/// \
//6   10
/// \ / \
//5  7 9 11
//���������
//8
/// \
//10   6
/// \ / \
//11 9 7  5
//���ҷ���һ�£�����������ָ�뽻��һ��
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