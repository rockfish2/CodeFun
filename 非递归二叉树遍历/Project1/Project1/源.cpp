#include <iostream>
#include <stack>


using namespace ::std;

/*感谢博主，提供的思路 https://blog.csdn.net/z_ryan/article/details/80854233 */
//Binary Tree Node
typedef struct node
{
	int data;
	struct node* lchild;  //左孩子
	struct node* rchild;  //右孩子
	node(int x) :data(x), lchild(NULL), rchild(NULL) {};
}BTNode;


		//中序遍历
//思路：所有的root 看作是左节点
void InOrderWithoutRecursion1(BTNode* root)
{
	//空树
	if (root == NULL)
		return;
	//树非空
	BTNode* p = root;
	stack<BTNode*> s;

	while (!s.empty() || p)
	{
		//一直遍历到左子树最下边，边遍历边保存根节点到栈中
		while (p)
		{
			s.push(p);
			p = p->lchild;
		}
		//当p为空时，说明已经到达左子树最下边，这时需要出栈了
		if (!s.empty())
		{
			p = s.top();
			s.pop();
			cout << p->data;
			//进入右子树，开始新的一轮左子树遍历(这是递归的自我实现)
			p = p->rchild;
		}
	}
}
//所有的节点都可看做是根节点
void PreOrderWithoutRecursion1(BTNode* root)
{
	if (root == NULL)
		return;
	BTNode* p = root;
	stack<BTNode*> s;
	while (!s.empty() || p)
	{
		//边遍历边打印，并存入栈中，
		while (p)
		{
			cout << p->data;//root
			s.push(p);
			p = p->lchild;
		}
		//当p为空时，说明根和左子树都遍历完了，该进入右子树了
		if (!s.empty())
		{
			p = s.top();
			s.pop();
			p = p->rchild;
		}
	}

}
//后序遍历
//后序遍历的难点在于：需要判断上次访问的节点是位于左子树，还是右子树。
//若是位于左子树，则需跳过根节点，
//先进入右子树，再回头访问根节点；
//若是位于右子树，则直接访问根节点。
void PostOrderWithoutRecursion(BTNode* root)
{
	if (root == NULL)
		return;
	stack<BTNode*> s;
	//pCur:当前访问节点，pLastVisit:上次访问节点
	BTNode* pCur, *pLastVisit;

	pCur = root;
	pLastVisit = NULL;

	//先把pCur移动到左子树最下边
	while (pCur)
	{
		s.push(pCur);
		pCur = pCur->lchild;
	}

	while (!s.empty())
	{
		//走到这里，pCur都是空，并已经遍历到左子树底端(看成扩充二叉树，则空，亦是某棵树的左孩子)
		pCur = s.top();
		s.pop();
		//一个根节点被访问的前提是：无右子树或右子树已被访问过
		if (pCur->rchild == NULL || pCur->rchild == pLastVisit)
		{
			cout<< pCur->data;
			//修改最近被访问的节点
			pLastVisit = pCur;
		}
		/*这里的else语句可换成带条件的else if:
		else if (pCur->lchild == pLastVisit)
		//若左子树刚被访问过，则需先进入右子树(根节点需再次入栈)
		因为：上面的条件没通过就一定是下面的条件满足。仔细想想！
		*/
		else
		{
			//根节点再次入栈
			s.push(pCur);
			//进入右子树，且可肯定右子树一定不为空
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