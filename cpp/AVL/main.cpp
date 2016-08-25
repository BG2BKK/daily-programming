#include <iostream>
#include <fstream>
#include <time.h>
#include "AVL.h"
using namespace std;

int main()
{
	long beg = clock();

	AVLTree avl;
	fstream fs("data.txt",ios::in);
	fs >> avl;
	fs.close();
	avl.InOrder(avl.GetRoot());	

	long end = clock();
	cout << end << endl;
	cout << beg << endl;
	cout << end - beg << endl;
}