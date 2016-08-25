#include <iostream>
using namespace std;
#include <string>

#ifndef _AVL_H_
#define _AVL_H_

struct BSTNode
{
	int count;
	string word;
	BSTNode * left,* right;
	BSTNode()
	{
		left = NULL;
		right = NULL;
		count = 0;
	}
	void SetData(string  x)
	{
		word = x;
	}
	string GetData()
	{
		return word;
	}
};

struct AVLNode : public BSTNode
{
	int bf;
	AVLNode():BSTNode(){bf = 0;}
	AVLNode(string x):BSTNode()
	{
		word = x;
		bf = 0;
	}
};


class AVLTree
{
	AVLNode * root;
public:
	AVLTree():root(NULL){}
	bool Insert(string x,AVLNode *& ptr);						//����
	bool Remove(string x,AVLNode *& ptr);
	void RotateL(AVLNode *& ptr);							//����ת
	void RotateR(AVLNode *& ptr);							//�ҵ���ת
	void RotateLR(AVLNode *& ptr);						//�������˫��ת
	void RotateRL(AVLNode *& ptr);						//���Һ���˫��ת
	int Height(AVLNode * ptr);								//�߶�
	void InOrder(AVLNode * ptr);							//����ǰ�����
	AVLNode *& GetRoot()
	{return this->root;}

	friend istream& operator >>(istream& is, AVLTree& at);
};

#endif