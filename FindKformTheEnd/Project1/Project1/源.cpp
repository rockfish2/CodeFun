#include <iostream>

using namespace::std;
//输入一个链表，输出该链表中倒数第k个结点。
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		//int sum = 0;
		//ListNode* pTest = pListHead;
		//while (pListHead != NULL)
		//{
		//	pTest = pTest->next;
		//	sum++;
		//}
		//sum = sum - k;
		//pTest = pListHead;
		//while (sum)
		//{
		//	pTest = pTest->next;
		//	sum--;
		//}
		//return pTest;
		ListNode* pTest = pListHead;
		while (k-- && pTest!= NULL)
		{
			pTest = pTest->next;
		}
		if (k < -1)
			return NULL;
		while (pTest != NULL) {
			pListHead = pListHead->next;
			pTest = pTest->next;
		}
		return pListHead;

	}
};

int main()
{
	Solution s;
	ListNode l1(1), l2(2), l3(3), l4(4);
	ListNode* p;
	p = &l1;
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = NULL;

	cout<<s.FindKthToTail(p,3)->val;
	return 0;

}


