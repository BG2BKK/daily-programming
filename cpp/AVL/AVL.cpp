#include <iostream>
using namespace std;
#include "AVL.h"
#include <stack>
#include <assert.h>
#include <string>

bool AVLTree::Insert(string x,AVLNode *& ptr)						//插入
{
	AVLNode * pr = NULL,		//父节点
		* p = ptr,
		*q;
	int d;
	stack<AVLNode *> st;
	while(p != NULL)
	{
		int result = x.compare(p->word);
		if(result == 0)
		{
			p->count++;
			return false;		//已经存在节点了
		}
		pr = p;st.push(pr);
		if(result<0)
			p = (AVLNode *)p->left;
		else
			p = (AVLNode *)p->right;
	}
	p = new AVLNode(x);
	assert(p);
	p->count++;

	if(pr == NULL)				//AVL树为空树的情况
	{
		ptr = p;
		ptr->count ++;
		return true;
	}

	if(x.compare(pr->word)<0)
		pr->left = p;
	else
		pr->right = p;

	while(!st.empty())
	{
		pr = st.top();				//获取栈顶部的数据，此时的p指向的pr的子节点
		st.pop();

		if(p == pr->left)		//调整父节点的bf
			pr->bf--;
		else
			pr->bf++;

		if(pr->bf == 0)			//平衡了，退出
			break;

		if(pr->bf == 1 || pr->bf == -1)		//bf = |1|
			p = pr;				//父节点成为新的子节点
		else													//bf = |2|
		{
			d = (pr->bf<0)?-1:1;		//d记录父节点的正负
			if(p->bf == d)		//同号，进行左单旋转或者右单旋转，
				//p的平衡因子肯定不可能为0，必定为1或者-1
			{
				if(d == -1)			//负号，说明要进行右单旋转
					this->RotateR(pr);
				else 
					this->RotateL(pr);
			}
			else						//异号，进行双旋转
			{
				if(d == -1)
					this->RotateLR(pr);
				else 
					this->RotateRL(pr);
			}
			break;
		}
	}
	if(st.empty() == true)
		ptr = pr;
	else
	{
		q = st.top();
		if(q->word.compare(pr->word)>0)
			q->left = pr;
		else
			q->right = pr;
	}
	return true;
}

//同号的话用单旋转
void AVLTree::RotateL(AVLNode *& ptr)
{
	AVLNode * subL = ptr;
	ptr = (AVLNode *)subL->right;
	subL->right = ptr->left;
	ptr->left = subL;
	ptr->bf = subL->bf = 0;
}

void AVLTree::RotateR(AVLNode *& ptr)
{
	AVLNode * subR = ptr;
	ptr = (AVLNode *)subR->left;
	subR->left = ptr->right;
	ptr->right = subR;
	ptr->bf = subR->bf = 0;
}

//异号的话用双旋转
void AVLTree::RotateLR(AVLNode *& ptr)						//先左后右双旋转
{
	AVLNode * subR = ptr,* subL = (AVLNode *)subR->left;
	ptr = (AVLNode *)subL->right;
	subL->right = ptr->left;
	ptr->left = subL;
	if(ptr->bf<=0)
		subL->bf = 0;
	else						//ptr->bf == 1
		subL->bf = -1;
	subR->left = ptr->right;
	ptr->right = subR;
	if(ptr->bf == -1)
		subR->bf = 1;
	else						//ptr->bf == 0
		subR->bf = 0;
	ptr->bf = 0;
}

void AVLTree::RotateRL(AVLNode *& ptr)						//先右后左双旋转
{
	AVLNode * subL = ptr,* subR = (AVLNode *)subL->right;
	ptr = (AVLNode *)subR->left;
	subR->left = ptr->right;			//右单旋
	ptr->right = subR;
	if(ptr->bf<0)
		subR->bf = 1;
	else						//ptr->bf == 1
		subR->bf = 0;
	subL->right = ptr->left;			//左单旋
	ptr->left = subL;
	if(ptr->bf == 1)
		subL->bf = -1;
	else						//ptr->bf == -1
		subL->bf = 0;
	ptr->bf = 0;
}

void AVLTree::InOrder(AVLNode * ptr)
{
	if(ptr == NULL)
		return;
	InOrder((AVLNode *)ptr->left);
	cout << ptr->word << ":" << ptr->count << endl;
	InOrder((AVLNode *)ptr->right);
}

istream& operator >>(istream& is, AVLTree& at)
{
	string p;
	string replace = "\0";
	while(!is.eof())
	{
		is >> p;
		/*if(p.empty())
		break;*/
		/*if(p.find(",")!=-1)
		p.replace(p.find(","),1,replace);
		if(p.find(".")!=-1)
		p.replace(p.find("."),1,replace);
		if(p.find("!")!=-1)
		p.replace(p.find("!"),1,replace);
		if(p.find("?")!=-1)
		p.replace(p.find("?"),1,replace);
		if(p.find("\"")!=-1)
		p.replace(p.find("\""),1,replace);
		if(p.find("'")!=-1)
		p.replace(p.find("'"),1,replace);*/
		at.Insert(p,at.GetRoot());
	}
	return is;
}

