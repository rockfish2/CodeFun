#include <iostream>

using namespace::std;

//����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩
//���ؽ��Ϊ���ƺ��������head�����ƽڵ㡢
//��ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�


struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
			label(x), next(NULL), random(NULL) {
	}
};

class Solution {
public:
	//��¡ÿһ���ڵ㣬������¡�Ľڵ���뵽ԭʼ�ڵ�ĺ���
	void cloneNode(RandomListNode* pHead)
	{
		RandomListNode* Head = pHead;
		while (Head != NULL)
		{
			//�����½ڵ�
			//��ʽһ��
			//RandomListNode* insert = (RandomListNode*)malloc(sizeof(RandomListNode));
			//��ʽ���������½ڵ�,����ʼ����ֵ
			RandomListNode *insert = new RandomListNode(0);
			insert->label = Head->label;
			insert->next = Head->next;
			insert->random = NULL;
			Head->next = insert;
			Head = insert->next;
		}
	}

	void connectRandomNode(RandomListNode* pHead)
	{
		//RandomListNode* Head = pHead;
		RandomListNode *pCloneNode = NULL;
		while (pHead != NULL)
		{
			// newHeadָ���¡�����Ľڵ�, ��pHead��һ�ڵ�
			pCloneNode = pHead->next;
			// newHead��randomָ��pHead��random��һ�ڵ�
			if (NULL != pHead->random) {
				pCloneNode->random = pHead->random->next;
			}
			// pHeadԽ����¡�ڵ�, ָ���¡�ڵ����һ�ڵ�
			pHead = pCloneNode->next;
		}
	}
	//������һ��Ϊ��
	RandomListNode* retCloneList(RandomListNode* pHead) {
		RandomListNode *pNode = pHead;
		RandomListNode *pClonedHead = nullptr;
		RandomListNode *pClonedNode = nullptr;

		if (pNode != nullptr)
		{
			pClonedHead = pClonedNode = pNode->next;
			pNode->next = pClonedNode->next;
			pNode = pClonedNode->next;
		}

		while (pNode != nullptr)
		{
			//��pClonedNode��pNextָ��ǰԭ����ڵ����һ���ڵ�
			pClonedNode->next = pNode->next;
			//��pClonedNode��Ϊԭ����ڵ����һ���ڵ�
			pClonedNode = pClonedNode->next;
			//��ԭ����ڵ��pNextָ��pClonedNode����һ���ڵ㣬����ԭ����ͶϿ���
			pNode->next = pClonedNode->next;
			//��ԭ����ڵ����
			pNode = pNode->next;
		}
		return pClonedHead;
	}

	RandomListNode* Clone(RandomListNode* pHead)
	{
		cloneNode(pHead);
		connectRandomNode(pHead);
		return retCloneList(pHead);
	}
};



int main()
{

}

