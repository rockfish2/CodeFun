#include <iostream>
using namespace::std;

//输入一个链表，反转链表后，输出新链表的表头。


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		//头插法
		ListNode* pNewHead = NULL,*pTemp =NULL;
		while (pHead)
		{
			pTemp = pHead->next;
			pHead->next = pNewHead;
			pNewHead = pHead;
			pHead = pTemp;

		}
		return pNewHead;


	}
};

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
class Solution_Merge {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		//类似于数组的合并//要建立一个实例，指针的话不行啊
		ListNode* pNewHead = NULL;
		ListNode pTag(0); 
		pNewHead = &pTag;
		if (pHead1 == NULL)
			return pHead2;
		if (pHead2 == NULL)
			return pHead1;
		while (pHead1 !=NULL && pHead2 != NULL)
		{
			if (pHead1->val < pHead2->val)

			{
				pNewHead->next = pHead1;
				pHead1 = pHead1->next;
			}
			else
			{
				pNewHead->next = pHead2;
				pHead2 = pHead2->next;
			}
			pNewHead = pNewHead->next;

		}                                                                              
		if(pHead1 != NULL)
		{
			pNewHead->next = pHead1;

		}
		if(pHead2 != NULL)
		{
			pNewHead->next = pHead2;
		}
		return pTag.next;
	}
};

int main()
{

	return 0;
}