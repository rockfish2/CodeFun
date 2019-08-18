#include <iostream>
#include <stack>


using namespace ::std;

/*��л�������ṩ��˼· https://blog.csdn.net/z_ryan/article/details/80854233 */
//Binary Tree Node
typedef struct node
{
	int data;
	struct node* lchild;  //����
	struct node* rchild;  //�Һ���
	node(int x) :data(x), lchild(NULL), rchild(NULL) {};
}BTNode;


		//�������
//˼·�����е�root ��������ڵ�
void InOrderWithoutRecursion1(BTNode* root)
{
	//����
	if (root == NULL)
		return;
	//���ǿ�
	BTNode* p = root;
	stack<BTNode*> s;

	while (!s.empty() || p)
	{
		//һֱ���������������±ߣ��߱����߱�����ڵ㵽ջ��
		while (p)
		{
			s.push(p);
			p = p->lchild;
		}
		//��pΪ��ʱ��˵���Ѿ��������������±ߣ���ʱ��Ҫ��ջ��
		if (!s.empty())
		{
			p = s.top();
			s.pop();
			cout << p->data;
			//��������������ʼ�µ�һ������������(���ǵݹ������ʵ��)
			p = p->rchild;
		}
	}
}
//���еĽڵ㶼�ɿ����Ǹ��ڵ�
void PreOrderWithoutRecursion1(BTNode* root)
{
	if (root == NULL)
		return;
	BTNode* p = root;
	stack<BTNode*> s;
	while (!s.empty() || p)
	{
		//�߱����ߴ�ӡ��������ջ�У�
		while (p)
		{
			cout << p->data;//root
			s.push(p);
			p = p->lchild;
		}
		//��pΪ��ʱ��˵���������������������ˣ��ý�����������
		if (!s.empty())
		{
			p = s.top();
			s.pop();
			p = p->rchild;
		}
	}

}
//�������
//����������ѵ����ڣ���Ҫ�ж��ϴη��ʵĽڵ���λ����������������������
//����λ���������������������ڵ㣬
//�Ƚ������������ٻ�ͷ���ʸ��ڵ㣻
//����λ������������ֱ�ӷ��ʸ��ڵ㡣
void PostOrderWithoutRecursion(BTNode* root)
{
	if (root == NULL)
		return;
	stack<BTNode*> s;
	//pCur:��ǰ���ʽڵ㣬pLastVisit:�ϴη��ʽڵ�
	BTNode* pCur, *pLastVisit;

	pCur = root;
	pLastVisit = NULL;

	//�Ȱ�pCur�ƶ������������±�
	while (pCur)
	{
		s.push(pCur);
		pCur = pCur->lchild;
	}

	while (!s.empty())
	{
		//�ߵ����pCur���ǿգ����Ѿ��������������׶�(�����������������գ�����ĳ����������)
		pCur = s.top();
		s.pop();
		//һ�����ڵ㱻���ʵ�ǰ���ǣ������������������ѱ����ʹ�
		if (pCur->rchild == NULL || pCur->rchild == pLastVisit)
		{
			cout<< pCur->data;
			//�޸���������ʵĽڵ�
			pLastVisit = pCur;
		}
		/*�����else���ɻ��ɴ�������else if:
		else if (pCur->lchild == pLastVisit)
		//���������ձ����ʹ��������Ƚ���������(���ڵ����ٴ���ջ)
		��Ϊ�����������ûͨ����һ����������������㡣��ϸ���룡
		*/
		else
		{
			//���ڵ��ٴ���ջ
			s.push(pCur);
			//�������������ҿɿ϶�������һ����Ϊ��
			pCur = pCur->rchild;
			while (pCur)
			{
				s.push(pCur);
				pCur = pCur->lchild;
			}
		}
	}

}
int main()
{
	BTNode * root = new BTNode(5);
	root->rchild= new BTNode(7);
	root->lchild = new BTNode(3);
	root->lchild->lchild = new BTNode(2);
	root->lchild->rchild = new BTNode(4);
	root->rchild->lchild = new BTNode(6);
	root->rchild->rchild = new BTNode(8);

	InOrderWithoutRecursion1(root);
	cout << endl;
	PreOrderWithoutRecursion1(root);
	cout << endl;
	PostOrderWithoutRecursion(root);
	return 0;
}