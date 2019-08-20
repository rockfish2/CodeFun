#include <iostream>
#include <vector>
#include <stack>
using namespace::std;

//���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
//����ѹ��ջ���������־�����ȡ�
//��������1, 2, 3, 4, 5��ĳջ��ѹ��˳������4, 5, 3, 2, 1�Ǹ�ѹջ���ж�Ӧ��һ���������У�
//��4, 3, 5, 1, 2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {//û�� ˼·
		stack<int> a;
		for (int i=0,j =0;i < pushV.size();)
		{
			a.push(pushV[i++]);
			while (j < popV.size() && a.top() == popV[j])
			{
				j++;
				a.pop();
			}
		}
		return a.empty();
	}
};
int main()
{
	vector<int> a = {1,2,3,4,5}, b = {5,4,3,2,1};
	Solution s;
	bool result = s.IsPopOrder(a, b);
	return 0;
}