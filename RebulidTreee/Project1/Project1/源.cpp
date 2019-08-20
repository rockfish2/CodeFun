#include <iostream>
#include <vector>

using namespace::std;
  struct TreeNode {
     int val;
      TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

  //����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
	 // ���������ǰ���������������Ľ���ж������ظ������֡�
	 // ��������ǰ���������{ 1,2,4,7,3,5,6,8 }
     //�������������{ 4,7,2,1,5,3,8,6 }��
	 // ���ؽ������������ء�

//ǰ��Ļ���root �� �� 
//���� �� root ��
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) 
	{
		
		if (pre.empty()  || vin.empty()  || pre.size() != vin.size())
			return NULL;
		int length_vector = pre.size();
		return build_tree(pre , vin, 0, pre.size() -1, 0, vin.size()-1);

	}
	TreeNode* build_tree(vector<int> &pre, vector<int> &vin,int start_pre ,int end_pre, int start_in, int end_in )
	{
		//int root_value = pre[0];//new root
		TreeNode* root = new TreeNode(pre[start_pre]);

		if (start_pre == end_pre )
		{
			if (start_in == end_in && pre[start_pre] == vin[start_in])
				return root;

		}
		//��������ҵ�root
		int root_inorder = pre[start_pre];
		int index_in = start_in;
		while (index_in <= end_in)
		{
			
			if (vin[index_in] == root_inorder)
				break;
			index_in++;
		}
		int length = index_in - start_in;

		int left_pre_end = start_pre + length;
		//����������
		if (length>0)
		{
			root->left = build_tree(pre, vin, start_pre + 1, left_pre_end, start_in, index_in - 1);

		}
		//����������
		if (length < end_pre - start_pre)
		{
			root->right = build_tree(pre, vin, left_pre_end+1, end_pre, index_in+1, end_in);
		}
		return root;
	}
	
};

//{1, 2, 5, 3, 4, 6, 7}
//
//������Ϊ:
//
//{1, 2, 5, 3, 4, 6}


int main()
{
	//int enter;

	//cin >> enter;
	//if (enter == '\r')
	//	cout << "Enter" << endl;
	vector<int>  pre_order = {1,2,4,7,3,5,6,8};
	vector<int>  in_order =  {4,7,2,1,5,3,8,6};
	Solution s1;
	s1.reConstructBinaryTree(pre_order, in_order);
	return 0;
}