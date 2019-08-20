#include <iostream>

using namespace::std;

//输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点）
//返回结果为复制后复杂链表的head。复制节点、
//（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）


struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
			label(x), next(NULL), random(NULL) {
	}
};

class Solution {
public:
	//克隆每一个节点，并将克隆的节点插入到原始节点的后面
	void cloneNode(RandomListNode* pHead)
	{
		RandomListNode* Head = pHead;
		while (Head != NULL)
		{
			//创建新节点
			//方式一：
			//RandomListNode* insert = (RandomListNode*)malloc(sizeof(RandomListNode));
			//方式二：创建新节点,并初始化其值
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
			// newHead指向克隆出来的节点, 是pHead下一节点
			pCloneNode = pHead->next;
			// newHead的random指向pHead的random下一节点
			if (NULL != pHead->random) {
				pCloneNode->random = pHead->random->next;
			}
			// pHead越过克隆节点, 指向克隆节点的下一节点
			pHead = pCloneNode->next;
		}
	}
	//将链表一分为二
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
			//将pClonedNode的pNext指向当前原链表节点的下一个节点
			pClonedNode->next = pNode->next;
			//将pClonedNode置为原链表节点的下一个节点
			pClonedNode = pClonedNode->next;
			//将原链表节点的pNext指向pClonedNode的下一个节点，否则原链表就断开了
			pNode->next = pClonedNode->next;
			//将原链表节点后移
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

