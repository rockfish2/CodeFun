#include <iostream>
#include <stack>
//������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�
using namespace::std;

class Solution
{
public:
	int cou = 0;
	void push(int node) {
		stack1.push(node);
	}

	int pop() {//
		if (stack2.empty()) 
		{
			while (!stack1.empty() ) //while (stack1.empty() != NULL)
			{
				stack2.push(stack1.top());
				stack1.pop();//void object.pop();
			}
		}
		int res = stack2.top();
		stack2.pop();
		return res;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};



