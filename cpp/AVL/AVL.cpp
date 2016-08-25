#include <iostream>
using namespace std;
#include "AVL.h"
#include <stack>
#include <assert.h>
#include <string>

bool AVLTree::Insert(string x,AVLNode *& ptr)						//����
{
	AVLNode * pr = NULL,		//���ڵ�
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
			return false;		//�Ѿ����ڽڵ���
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

	if(pr == NULL)				//AVL��Ϊ���������
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
		pr = st.top();				//��ȡջ���������ݣ���ʱ��pָ���pr���ӽڵ�
		st.pop();

		if(p == pr->left)		//�������ڵ��bf
			pr->bf--;
		else
			pr->bf++;

		if(pr->bf == 0)			//ƽ���ˣ��˳�
			break;

		if(pr->bf == 1 || pr->bf == -1)		//bf = |1|
			p = pr;				//���ڵ��Ϊ�µ��ӽڵ�
		else													//bf = |2|
		{
			d = (pr->bf<0)?-1:1;		//d��¼���ڵ������
			if(p->bf == d)		//ͬ�ţ���������ת�����ҵ���ת��
				//p��ƽ�����ӿ϶�������Ϊ0���ض�Ϊ1����-1
			{
				if(d == -1)			//���ţ�˵��Ҫ�����ҵ���ת
					this->RotateR(pr);
				else 
					this->RotateL(pr);
			}
			else						//��ţ�����˫��ת
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

//ͬ�ŵĻ��õ���ת
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

//��ŵĻ���˫��ת
void AVLTree::RotateLR(AVLNode *& ptr)						//�������˫��ת
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

void AVLTree::RotateRL(AVLNode *& ptr)						//���Һ���˫��ת
{
	AVLNode * subL = ptr,* subR = (AVLNode *)subL->right;
	ptr = (AVLNode *)subR->left;
	subR->left = ptr->right;			//�ҵ���
	ptr->right = subR;
	if(ptr->bf<0)
		subR->bf = 1;
	else						//ptr->bf == 1
		subR->bf = 0;
	subL->right = ptr->left;			//����
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

