/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// http://www.lintcode.com/zh-cn/problem/insertion-sort-list/
#include <vector>
#include <iostream>
using namespace std;
class ListNode {
	public:
		int val;
		ListNode *next;
		ListNode(int val) {
			this->val = val;
			this->next = NULL;
		}
};
class Solution {
	public:
		ListNode *mergeKLists(vector<ListNode *> &lists) {
			// write your code here
			int size = lists.size();
			if(size < 1) return NULL;
			else if(size == 1) return lists[0];
			ListNode *node = NULL;
			ListNode **p = &node;
			vector<ListNode *> l;
			for(int i=0;i<size;i++){
				l.push_back(lists[i]);
			}
			while(1){
				ListNode *temp = NULL;
				int pos = 0;
				for(int i=0;i<size;i++){
					if(l[i]){
						temp = l[i];
						pos = i;
						break;
					}
				}
				if(!temp)
					break;
				for(int i=0;i<size;i++){
					if(!l[i]) continue;
					if(l[i]->val < temp->val ){
						temp = l[i];
						pos = i;
					}
				}
				*p = temp;
				if(! temp) 
					break;
				p = &((*p)->next);
				if(l[pos])
					l[pos] = l[pos]->next;

//				for(int i=0;i<l.size();i++){
//					if(l[i])
//						printf("%d\n", l[i]->val);
//					else 
//						printf("--\n");
//				}
			}
			return node;
		}
};

ListNode *makeList(vector<int> a){
	ListNode *node = NULL;
	ListNode **p = &node;
	for(int i=0;i<a.size();i++){
		*p = new ListNode(a[i]);
		p = &((*p)->next);
	}
	return node;
}
int main()
{
	Solution s;
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = NULL;

	vector<int> v1 = {2};
	vector<int> v2 = {};
	vector<int> v3 = {-1};
	ListNode *l1 = makeList(v1);
	ListNode *l2 = makeList(v2);
	ListNode *l3 = makeList(v3);

	vector<ListNode *> l;
	l.push_back(l1);
	l.push_back(l2);
	l.push_back(l3);


	ListNode *node = s.mergeKLists(l);
	while(node){
		printf("%d\n", node->val);
		node = node->next;
	}

	for(int i=0;i<l.size();i++){
		ListNode *p = l[i];
		while(p){
			printf("%d\t", p->val);
			p = p->next;
		}
		printf("\n");
	}
}
