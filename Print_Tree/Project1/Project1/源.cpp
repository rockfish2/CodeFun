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

//��ʵ��һ����������֮���δ�ӡ��������
//����һ�а��մ����ҵ�˳���ӡ��
//�ڶ��㰴�մ��������˳���ӡ��
//�����а��մ����ҵ�˳���ӡ���������Դ����ơ�
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
//������ǰ�˵�˼·��
		//ʹ��������stack��һ��������������һ������ż����
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
				//ż���з�ջ2
				cur = stack1.top();
				if (cur->left)
					stack2.push(cur->left);
				if (cur->right)
					stack2.push(cur->right);
				//ջ1��
				ret1.push_back(stack1.top()->val);  //��������������
				stack1.pop();
			}
			if (ret1.size())
				result.push_back(ret1);

			while (!stack2.empty())
			{
				//�����з�ջ1
				cur = stack2.top();
				if (cur->right)
					stack1.push(cur->right);
				if (cur->left)
					stack1.push(cur->left);

				ret2.push_back(stack2.top()->val); //����ż��������
				stack2.pop();
			}
			if (ret2.size())
				result.push_back(ret2);
		}
		return result;
	}
	//���ϵ��°����ӡ��������ͬһ����������������
	//ÿһ�����һ�С�
	vector<vector<int> > Print_2(TreeNode* pRoot) {
		//��֮ǰ�����Ƶ�
		//ʹ�ö�������֮ǰ��������

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
	//��ʵ�������������ֱ��������л��ͷ����л�������
	//���л�(Serialization)�ǽ������״̬��Ϣת��Ϊ���Դ洢�������ʽ�Ĺ��̡�
	//�����л��ڼ䣬�����䵱ǰ״̬д�뵽��ʱ��־��Դ洢����
	//�Ժ󣬿���ͨ���Ӵ洢���ж�ȡ�����л������״̬�����´����ö���
	//��ʵ�����û��˵���ر����ף�
	//���л����ǰ���ǰ�������˳�������Ϊһ���ַ�����
	//�ڵ�Ϊ������#���棬�����л����ǽ�һ���ַ����ָ���Ϊһ������
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

		strcpy(ret, r.c_str());//r.c_str();ֻ�ǿ���

		strcat(ret, left);
		strcat(ret, right);

		return ret;
	}
	TreeNode* Deserialize(char *str) {
		return decode(str);
	}
};