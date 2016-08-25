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
	bool Insert(string x,AVLNode *& ptr);						//插入
	bool Remove(string x,AVLNode *& ptr);
	void RotateL(AVLNode *& ptr);							//左单旋转
	void RotateR(AVLNode *& ptr);							//右单旋转
	void RotateLR(AVLNode *& ptr);						//先左后右双旋转
	void RotateRL(AVLNode *& ptr);						//先右后左双旋转
	int Height(AVLNode * ptr);								//高度
	void InOrder(AVLNode * ptr);							//利用前序遍历
	AVLNode *& GetRoot()
	{return this->root;}

	friend istream& operator >>(istream& is, AVLTree& at);
};

#endif