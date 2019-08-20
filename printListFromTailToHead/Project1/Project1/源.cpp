#include <iostream>
#include <vector>
using namespace::std;
//输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。

  struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
  };

class Solution {//头插法//或者是堆栈法
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		ListNode* newhead = NULL;
		ListNode* temphead = NULL;
		vector<int> a;
		while (head != NULL)
		{
			temphead = head->next;
			head->next = newhead;
			newhead = head;
			head = temphead;
		}
		while (newhead!=NULL)
		{
			a.push_back(newhead->val);
			cout << newhead->val << endl;
			newhead = newhead->next;
		}
		return a;
	}
};
int main()
{
	ListNode l1(1),l2(2),l3(3);
	ListNode* head = &l1;
	l1.next = &l2;
	l2.next = &l3;
	l3.next = NULL;

	Solution s;
	vector<int> v1;
	v1 = s.printListFromTailToHead(head);
	system("pause");

}