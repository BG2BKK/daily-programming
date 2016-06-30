/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// http://www.lintcode.com/zh-cn/problem/insertion-sort-list/
#include <stdio.h>
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
		ListNode *partition(ListNode *head, int x){
			if(!head || !head->next)
				return head;
			ListNode *newhead = NULL;
			ListNode **ptail = &newhead;
			ListNode **p = &head;

			ListNode *res = NULL;

			ListNode *equal = NULL;
			ListNode **pequal = &equal;
			while(*p){
				if((*p)->val < x) {
					ListNode *node = &(**p);
					ListNode *next = (*p)->next;
					*p = next;

					*ptail = node;
					ptail = &((*ptail)->next);
				
				} else if ((*p)->val == x){
					ListNode *node = &(**p);
					ListNode *next = (*p)->next;
					*p = next;

//					node->next = NULL;
					*pequal = node;
					pequal = &((*pequal)->next);
				}
				else {
					if(!res){
						res = *p;
					}
					p = &((*p)->next);
				}
			}

			*pequal = NULL;
			if(equal){
				*ptail = equal;
				while(equal != *pequal){
					equal = equal->next;
				}
				ptail = pequal;
			}
//			while(equal!=*pequal){
//				*ptail = equal;
//				ptail = &((*ptail)->next);
//				equal = equal->next;
//			}

			*ptail = res;
			return newhead;


		}
};
int main()
{
	Solution s;
	ListNode *head = new ListNode(1);
	ListNode *p1 = new ListNode(4);
	ListNode *p2 = new ListNode(3);
	ListNode *p3 = new ListNode(2);
	ListNode *p4 = new ListNode(5);
	ListNode *p5 = new ListNode(2);
	head->next = p1;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;


	ListNode *node = s.partition(head, 3);
	while(node){
		printf("%d\n", node->val);
		node = node->next;
	}
}
