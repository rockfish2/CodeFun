#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>

using namespace::std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

//请实现一个函数按照之字形打印二叉树，
//即第一行按照从左到右的顺序打印，
//第二层按照从右至左的顺序打印，
//第三行按照从左到右的顺序打印，其他行以此类推。
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
//借助于前人的思路：
		//使用了两个stack：一个保存奇数，另一个保存偶数，
		vector<vector<int> > result;
		if (pRoot == NULL)
			return result;
		stack<TreeNode*> stack1, stack2;
		//vector<int> ret1, ret2;
		stack1.push(pRoot);
		while (!stack1.empty() || !stack2.empty())
		{
			vector<int> ret1, ret2;
			TreeNode* cur = NULL;

			while (!stack1.empty())
			{
				//偶数行放栈2
				cur = stack1.top();
				if (cur->left)
					stack2.push(cur->left);
				if (cur->right)
					stack2.push(cur->right);
				//栈1的
				ret1.push_back(stack1.top()->val);  //保存奇数行数据
				stack1.pop();
			}
			if (ret1.size())
				result.push_back(ret1);

			while (!stack2.empty())
			{
				//奇数行放栈1
				cur = stack2.top();
				if (cur->right)
					stack1.push(cur->right);
				if (cur->left)
					stack1.push(cur->left);

				ret2.push_back(stack2.top()->val); //保存偶数行数据
				stack2.pop();
			}
			if (ret2.size())
				result.push_back(ret2);
		}
		return result;
	}
	//从上到下按层打印二叉树，同一层结点从左至右输出。
	//每一层输出一行。
	vector<vector<int> > Print_2(TreeNode* pRoot) {
		//和之前的类似的
		//使用队列来和之前的相区别

		vector<vector<int> > result;
		if (pRoot == NULL)
			return result;
		queue<TreeNode*> queue_root;
		queue_root.push(pRoot);

		while (!queue_root.empty())
		{
			int length = queue_root.size();
			int i = 0;
			vector<int> temp;
			while ( i++ < length)
			{
				TreeNode* t = queue_root.front();
				if (t->left != NULL)
					queue_root.push(t->left);
				if(t->right != NULL)
					queue_root.push(t->right);
				temp.push_back(t->val);
				queue_root.pop();
			}
			result.push_back(temp);

		}
		return result;
	}
	//请实现两个函数，分别用来序列化和反序列化二叉树
	//序列化(Serialization)是将对象的状态信息转换为可以存储或传输的形式的过程。
	//在序列化期间，对象将其当前状态写入到临时或持久性存储区。
	//以后，可以通过从存储区中读取或反序列化对象的状态，重新创建该对象。
	//其实这道题没有说的特别明白，
	//序列化就是按照前序遍历的顺序将其输出为一个字符串，
	//节点为空则用#代替，反序列化就是讲一个字符串恢复成为一个树。
	char* Serialize(TreeNode *root) {

	}

	TreeNode* Deserialize(char *str) {

	}

};

class Solution {
private:
	TreeNode* decode(char *&str) {
		if (*str == '#') {
			str++;
			return NULL;
		}
		int num = 0;
		while (*str != ',')
			num = num * 10 + (*(str++) - '0');
		str++;
		TreeNode *root = new TreeNode(num);
		root->left = decode(str);
		root->right = decode(str);
		return root;
	}
public:
	char* Serialize(TreeNode *root) {
		if (!root) 
			return "#";

		string r = to_string(root->val);//to_string

		r.push_back(',');
		char *left = Serialize(root->left);
		char *right = Serialize(root->right);

		char *ret = new char[strlen(left) + strlen(right) + r.size()];

		strcpy(ret, r.c_str());//r.c_str();只是拷贝

		strcat(ret, left);
		strcat(ret, right);

		return ret;
	}
	TreeNode* Deserialize(char *str) {
		return decode(str);
	}
};