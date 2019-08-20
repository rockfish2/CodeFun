#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace::std;


typedef struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
}TreeNode;


class Solution {
public:
	char* Serialize(TreeNode* root)
	{
		string str; 

		if (root == NULL)
			return NULL;

		queue<TreeNode*> temp;//��α�����ʹ��

		temp.push(root);

		TreeNode* test;

		while (!temp.empty()) 
		{
			if (temp.front()) 
			{
				
				str += to_string(temp.front()->val) + ' ';//str��+=�÷������м���ո񣿣���Ҳ���Բ�����ո��
				temp.push(temp.front()->left);
				temp.push(temp.front()->right);
			}
			else 
			{
				str += '# ';
				//str.push_back('# ');
			}
			temp.pop();
		}

		
		char* res = strdup(str.c_str());//����û�г�ʼ����ָ�룬��strcpy����
		return res;
	}

	TreeNode* Deserialize(char* str)
	{
		if (!str)
			return nullptr;

		int k = 0;

		auto ret = nextNode(str, k);

		deque<TreeNode*> q;

		q.push_back(ret);

		while (!q.empty()) {
			int n = q.size();
			for (int i = 0; i < n; ++i) {
				q.front()->left = nextNode(str, k);
				q.front()->right = nextNode(str, k);
				if (q.front()->left)
					q.push_back(q.front()->left);
				if (q.front()->right)
					q.push_back(q.front()->right);
				q.pop_front();
			}
		}
		return ret;
	}
	TreeNode* nextNode(char* str, int& i)
	{
		string s;
		while (str[i] != '\0' && str[i] != ' ') {
			if (str[i] == '#') {
				i += 2;
				return nullptr;
			}
			s += str[i];
			i++;
		}
		if (str[i] == ' ')
			i++;
		if (!s.empty())
			return new TreeNode(stoi(s));
		return nullptr;
	}
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		//stack,zhongxu bianli
		//stack<TreeNode*> inorder_queue;
		if (pRoot == NULL)
			return NULL;
		vector<TreeNode*> inorder_queue;
		//inorder_queue.pu
		Inorder_Traverse(pRoot, inorder_queue);
		//while (k--)
		//{
		//	inorder_queue.pop();

		//}
		if (k > inorder_queue.size() || k < 1)
			return NULL;
		return inorder_queue[k-1];
	}
	void Inorder_Traverse(TreeNode* pRoot, vector<TreeNode*> &inorder_queue)
	{
		if (pRoot == NULL )
		{
			return;
		}
		Inorder_Traverse(pRoot->left, inorder_queue);
		inorder_queue.push_back(pRoot);
		Inorder_Traverse(pRoot->right, inorder_queue);

	}
};

//����һ�ö��������������ҳ����еĵ�kС�Ľ�㡣
//���磬 ��5��3��7��2��4��6��8���У��������ֵ��С˳�����С����ֵΪ4��


//����������λ��
class Solution_midNum {
public:
	void Insert(int num)
	{
		// �Ȱ�Ԫ�ؽ��в��룬�ٽ������������С�ѵ�ƽ��
		if (max_heap.empty() || max_heap.top() > num)
			max_heap.push(num);
		else
			min_heap.push(num);

		// ƽ��
		if (max_heap.size() > (min_heap.size() + 1))
		{
			min_heap.push(max_heap.top());
			max_heap.pop();
		}
		else if (max_heap.size() + 1 < min_heap.size())
		{
			max_heap.push(min_heap.top());
			min_heap.pop();
		}

	}

	double GetMedian()
	{
		if (max_heap.size() == min_heap.size())
			return max_heap.empty() ? 0 : ((max_heap.top() + min_heap.top()) / 2.0);
		else
			return (max_heap.size() > min_heap.size()) ? max_heap.top() : min_heap.top();

	}
private:
	priority_queue<int>    max_heap;
	priority_queue<int, vector<int>, greater<int>>    min_heap;
};
//��ͨ�Ķ�����һ���Ƚ��ȳ������ݽṹ��Ԫ���ڶ���β׷�ӣ����Ӷ���ͷɾ����
//�����ȶ����У�Ԫ�ر��������ȼ���������Ԫ��ʱ������������ȼ���Ԫ������ɾ����
//���ȶ��о�����߼��ȳ� ��first in, largest out������Ϊ������

class Solution {
public:
	//����С��
	priority_queue<int> large;
	priority_queue<int, vector<int>, greater<int>> small;
	void adjust()
	{
		if (large.size() > small.size() + 1)//size�����Ӵ���+1
		{
			int tmp = large.top();
			large.pop();
			small.push(tmp);
		}
		if (small.size() > large.size() + 1)//
		{
			int tmp = small.top();
			small.pop();
			large.push(tmp);
		}
	}
	void Insert(int num)
	{
		if (!large.empty())
		{
			if (large.top() < num)
				small.push(num);
			else 
				large.push(num);
			adjust();
		}
		else
			large.push(num);
	}

	double GetMedian()
	{
		int num = large.size() + small.size();
		if (num % 2 == 0)
			return double(large.top() + small.top()) / 2;
		else
		{
			if (large.size() > small.size())
				return double(large.top());
			else 
				return double(small.top());
		}
	}

};


int main()
{
	TreeNode *t = new TreeNode(5);
	t->left = new TreeNode(3);
	t->right = new TreeNode(7);
	t->left->left = new TreeNode(2);
	t->left->right = new TreeNode(4);
	t->right->left = new TreeNode(6);
	t->right->right = new TreeNode(8);
	Solution s1;
	string serlize = s1.Serialize(t);



	return 0;
}



