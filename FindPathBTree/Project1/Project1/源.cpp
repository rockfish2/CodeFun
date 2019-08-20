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
//����һ�Ŷ������ĸ��ڵ��һ��������
//��ӡ���������н��ֵ�ĺ�Ϊ��������������·����
//·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
//(ע��: �ڷ���ֵ��list�У����鳤�ȴ�����鿿ǰ)

//����ת��Ϊ�ҳ����������ĳЩ���ĺ�

//˼·�� ���Ƕ���������
//�ݹ������������ �ѽ�����·��
//���ý����Ҷ�ӽ����Ƚϵ�ǰ·�����Ƿ�����ڴ��͡�
//������㣬ÿһ�ֵݹ鷵�ص������ʱ����ǰ·��ҲӦ�û���һ�����



class Solution {
public:
	void findAllPath(TreeNode* root, int expectNumber, int currentSum, vector<vector<int> >& allpath, vector<int>& path) 
	{

		//��¼��ǰ���ʵĽ��
		path.push_back(root->val);

		//��¼���ʵ���ǰ�ڵ� ���н��ĺ�
		currentSum += root->val;

		//�ж��Ƿ�ΪҶ�ӽ�� true-��
		bool isLeaf = root->left == NULL && root->right == NULL;

		//���ΪҶ�ӽ�㣬 �ж�·���ĺ��Ƿ�����Ҫ�����㣬�����·��
		if (currentSum == expectNumber && isLeaf)
			allpath.push_back(path);

		if (root->left != NULL)
			findAllPath(root->left, expectNumber, currentSum, allpath, path);
		if (root->right != NULL)
			findAllPath(root->right, expectNumber, currentSum, allpath, path);

		//�����Ҷ�ӽ���ֲ�����Ҫ���˻ص�����㣬ɾ����ǰ�ڵ�
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
		//�����������Ŀһʱû�����������Ŀ�����ƺ�������
		//�Ƿ����������� Ҫ��Ҫ����root�أ�
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

		path.pop_back();//��ǰ�Ľڵ㲻��

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
	
//����һ�ö��������������ö���������ת����һ�������˫������
//Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��

class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		//���ڼ�¼˫������β���
		TreeNode* pLastNodeInList = NULL;

		//��ʼת�����
		ConvertNode(pRootOfTree, &pLastNodeInList);

		//pLastNodeInListָ��˫�������β��㣬������Ҫ���·���ͷ���
		TreeNode* pHeadOfList = pLastNodeInList;
		while (pHeadOfList != NULL && pHeadOfList->left != NULL) {
			pHeadOfList = pHeadOfList->left;
		}
		return pHeadOfList;
	}

	void ConvertNode(TreeNode* pNode, TreeNode** pLastNodeInList) {
		//Ҷ���ֱ�ӷ���
		if (pNode == NULL) {
			return;
		}
		TreeNode* pCurrent = pNode;
		//�ݹ�������
		if (pCurrent->left != NULL)
			ConvertNode(pCurrent->left, pLastNodeInList);

		//��ָ��
		pCurrent->left = *pLastNodeInList;

		//��ָ��
		if (*pLastNodeInList != NULL) 
		{
			(*pLastNodeInList)->right = pCurrent;
		}
		//����˫������β���
		*pLastNodeInList = pCurrent;
		//�ݹ�������
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

        TreeNode *pCurrent = pNode;     // ����ʹ��pNode������pCurrent
        
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

// ��������˫�����ͷ�ڵ�
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
		// ���ص��������ͷ�ڵ㣬������Ҫ�ƶ���β��

		TreeNode leftNode = head;

		while (leftNode.right != null)
			leftNode = leftNode.right;
		// ���ø��ڵ����������
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
		//���õݹ�Ľ�������

		if (pRootOfTree->left == NULL && pRootOfTree->right == NULL)
		{
			return pRootOfTree;
		}

		//TreeNode* node_head = NULL,*run_node = NULL ,*run_node2 = NULL;

		//�������
		TreeNode* left = Convert(pRootOfTree->left);

		TreeNode* run_node = left;
		//��������ߵĽڵ�
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

