#include <iostream>
#include <stack>
//用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
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



