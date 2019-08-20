#include <iostream>
using namespace::std;

//����һ��������ת��������������ı�ͷ��


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
		//ͷ�巨
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
//���������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������
class Solution_Merge {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		//����������ĺϲ�//Ҫ����һ��ʵ����ָ��Ļ����а�
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