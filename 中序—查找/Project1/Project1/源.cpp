#include<iostream>
#include<vector>


using namespace ::std;
//输入描述:
//输入两行，分别代表层序和中序遍历结果，节点编号按单个空格分开
//
//输出描述 :
//依次输出  从左向右叶子节点 ，先序， 后序 遍历 。 节点编号按空格分开
//
//输入例子1 :
//3 5 4 2 6 7 1
//2 5 3 6 4 7 1
//
//输出例子1 :
//	2 6 1
//	3 5 2 4 6 7 1
//	2 5 6 1 7 4 3
typedef struct TreeNode
{
	int val;
	TreeNode *left, *right;
	TreeNode(int v) :val(v), left(nullptr), right(nullptr) {}
};
TreeNode* mid_inorder_rebuild(vector<int> &mid_order,int mid_start,int mid_end, vector<int> &in_order, int in_start, int in_end)
{
	TreeNode* root = new TreeNode(mid_order[mid_start]);

	if (in_start == in_end)
	{
		return root;
	}
	int index_in = 0;
	for (index_in = in_start; index_in<= in_end; index_in++)
	{
		if (in_order[index_in] == mid_order[mid_start])
			break;

	}
	
	if (index_in > in_start)
	{
		root->left = mid_inorder_rebuild(mid_order, mid_start + 1, mid_end, in_order, in_start, index_in - 1);
	}

	if (index_in < in_end)
	{
		root->right = mid_inorder_rebuild(mid_order, mid_start + 1, mid_end, in_order, index_in+1,in_end);

	}
	return root;
}
TreeNode* createTree(vector<int>inorder, vector<int>seq, int begin, int end)
{
	if (seq.size() <= 0) return nullptr;

	TreeNode *root = new TreeNode(seq[0]);
	vector<int>left;
	vector<int>right;
	int k;
	for (k = begin; k <= end; ++k)
		if (inorder[k] == seq[0])
			break;

	bool isleft;
	for (int i = 1; i < seq.size(); ++i)//层次遍历
	{
		isleft = false;
		for (int j = begin; j < k; ++j)
		{
			if (seq[i] == inorder[j])
			{
				isleft = true;
				break;
			}
		}
		if (isleft)
			left.push_back(seq[i]);
		else
			right.push_back(seq[i]);
	}

	root->left = createTree(inorder, left, begin, k - 1);//
	root->right = createTree(inorder, right, k + 1, end);
	return root;
}
int main()
{

	//char *str = new char[100];

	//vector<int> s_order,in_order;
 //
	//cin.getline(str, 100);
	////指针操作为什么有问题？？
	////str = str+2;
	////cout << *str << endl;
	////while ((*str) != 0x00)
	////{
	////	if ((*str) != 0x20)
	////		a.push_back((*str)-'0');
	////	str++;

	////}
	////非要数组的操作
	//for (int i = 0;i<100;i++)
	//{
	//	if (str[i] == '\0')//
	//		break;
	//	if(str[i] != ' ')//
	//		s_order.push_back(str[i] - '0');

	//}
	//cin.getline(str, 100);

	//for (int i = 0; i < 100; i++)
	//{
	//	if (str[i] =='\0')//
	//		break;
	//	if (str[i] != ' ')//
	//		in_order.push_back(str[i] - '0');
	//}

	vector<int > seq =      {3,5,4,2,6,7,1};
	vector<int > inorder = { 2,5,3,6,4,7,1 };
	TreeNode* root = createTree(inorder, seq, 0, 6);

	return 0;
}
