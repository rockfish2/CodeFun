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
//
//输入一颗二叉树的根节点和一个整数，
//打印出二叉树中结点值的和为输入整数的所有路径。
//路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
//(注意: 在返回值的list中，数组长度大的数组靠前)

//问题转化为找出数组里面的某些数的和

//思路： 这是二叉排序树
//递归先序遍历树， 把结点加入路径
//若该结点是叶子结点则比较当前路径和是否等于期待和。
//弹出结点，每一轮递归返回到父结点时，当前路径也应该回退一个结点



class Solution {
public:
	void findAllPath(TreeNode* root, int expectNumber, int currentSum, vector<vector<int> >& allpath, vector<int>& path) 
	{

		//记录当前访问的结点
		path.push_back(root->val);

		//记录访问到当前节点 所有结点的和
		currentSum += root->val;

		//判断是否为叶子结点 true-是
		bool isLeaf = root->left == NULL && root->right == NULL;

		//如果为叶子结点， 判断路径的和是否满足要求，满足，保存该路径
		if (currentSum == expectNumber && isLeaf)
			allpath.push_back(path);

		if (root->left != NULL)
			findAllPath(root->left, expectNumber, currentSum, allpath, path);
		if (root->right != NULL)
			findAllPath(root->right, expectNumber, currentSum, allpath, path);

		//如果是叶子结点又不满足要求，退回到父结点，删除当前节点
		path.pop_back();

	}

	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {

		vector<vector<int> > allpath;
		vector<int> path;

		if (root == NULL)
			return allpath;
		int currentSum = 0;
		findAllPath(root, expectNumber, currentSum, allpath, path);
		return allpath;
	}
};

class Solution {
public:
	void Find_path(TreeNode* root, int expectNumber, vector<vector<int> > &all_list, vector<int> &path, int current_number);
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		//讲道理，这个题目一时没看懂，这个题目表述似乎有问题
		//是否是排序树呢 要不要包含root呢？
		vector<vector<int> > all_list;
		vector<int> path;
		int current_number = 0;

		if (root == NULL)
		{
			return all_list;
		}
		Find_path(root, expectNumber, all_list, path, current_number);
		return all_list;



	}

	void Find_path(TreeNode* root, int expectNumber , vector<vector<int> > &all_list, vector<int> &path,int current_number)
	{
		path.push_back(root->val);
		current_number += root->val;

		//bool leaf = root->left == NULL && root->right == NULL;

		if(current_number == expectNumber && root->left == NULL && root->right == NULL)
		{
			all_list.push_back(path);
		}
		if (root->left != NULL)
			Find_path(root->left, expectNumber, all_list, path, current_number);
		if (root->right != NULL)
			Find_path(root->right, expectNumber, all_list, path, current_number);

		path.pop_back();//但前的节点不合

	}
};



struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
	
//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
//要求不能创建任何新的结点，只能调整树中结点指针的指向。

class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		//用于记录双向链表尾结点
		TreeNode* pLastNodeInList = NULL;

		//开始转换结点
		ConvertNode(pRootOfTree, &pLastNodeInList);

		//pLastNodeInList指向双向链表的尾结点，我们需要重新返回头结点
		TreeNode* pHeadOfList = pLastNodeInList;
		while (pHeadOfList != NULL && pHeadOfList->left != NULL) {
			pHeadOfList = pHeadOfList->left;
		}
		return pHeadOfList;
	}

	void ConvertNode(TreeNode* pNode, TreeNode** pLastNodeInList) {
		//叶结点直接返回
		if (pNode == NULL) {
			return;
		}
		TreeNode* pCurrent = pNode;
		//递归左子树
		if (pCurrent->left != NULL)
			ConvertNode(pCurrent->left, pLastNodeInList);

		//左指针
		pCurrent->left = *pLastNodeInList;

		//右指针
		if (*pLastNodeInList != NULL) 
		{
			(*pLastNodeInList)->right = pCurrent;
		}
		//更新双向链表尾结点
		*pLastNodeInList = pCurrent;
		//递归右子树
		if (pCurrent->right != NULL)
		{
			ConvertNode(pCurrent->right, pLastNodeInList);
		}
	}
};

class Solution {
public:
    void convertNode(TreeNode* pNode, TreeNode **pLastInList) {
        if (nullptr == pNode)    return;

        TreeNode *pCurrent = pNode;     // 可以使用pNode来代替pCurrent
        
        if (nullptr != pCurrent->left) {
            convertNode(pCurrent->left, pLastInList);
        }
        
        pCurrent->left = *pLastInList;
        if (nullptr != *pLastInList) {
            (*pLastInList)->right = pCurrent;
        }
        *pLastInList = pCurrent;
        
        if (nullptr != pCurrent->right) {
            convertNode(pCurrent->right, pLastInList);
        }
    }
    
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode *pLastInList = nullptr;
        
        convertNode(pRootOfTree, &pLastInList);
        
        TreeNode *pHead = pLastInList;
        while ((nullptr != pHead) && (nullptr != pHead->left)) {
            pHead = pHead->left;
        }
        
        return pHead;
    }
};

class Solution {
public:
	TreeNode* pre = nullptr;

	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (!pRootOfTree) 
			return nullptr;

		Convert(pRootOfTree->right);

		if (pre) 
		{
			pre->left = pRootOfTree;
		}

		pRootOfTree->right = pre;
		pre = pRootOfTree;
		Convert(pRootOfTree->left);
		return pre;
	}
};

// 返回排序双链表的头节点
public TreeNode Convert(TreeNode pRootOfTree) 
{
	//robust
	if (pRootOfTree == null)
		return null;
	//edge condition
	if (pRootOfTree.left == null && pRootOfTree.right == null)
		return pRootOfTree;

	TreeNode head = null;
	if (pRootOfTree.left != null) 
	{
		head = Convert(pRootOfTree.left);
		// 返回的是链表的头节点，所以需要移动到尾部

		TreeNode leftNode = head;

		while (leftNode.right != null)
			leftNode = leftNode.right;
		// 设置根节点的左右链接
		leftNode.right = pRootOfTree;
		pRootOfTree.left = leftNode;
	}

	if (pRootOfTree.right != null)
	{
		TreeNode rightNode = Convert(pRootOfTree.right);
		pRootOfTree.right = rightNode;
		rightNode.left = pRootOfTree;
	}

	return head != null ? head : pRootOfTree;
}
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
		//设置递归的结束条件

		if (pRootOfTree->left == NULL && pRootOfTree->right == NULL)
		{
			return pRootOfTree;
		}

		//TreeNode* node_head = NULL,*run_node = NULL ,*run_node2 = NULL;

		//向左遍历
		TreeNode* left = Convert(pRootOfTree->left);

		TreeNode* run_node = left;
		//保存最左边的节点
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

