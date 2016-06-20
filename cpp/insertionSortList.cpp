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
		ListNode *insertionSortList(ListNode *head) {
			// write your code here
			if(!head || !head->next)
				return head;
			ListNode *sortedHead = head;
			ListNode *prev = head;
			ListNode *node = prev->next;

			while(node){
				ListNode **p = &sortedHead;
				while(*p!=node){
					if((*p)->val > node->val){
						break;
					}
					p = &((*p)->next);
				}
				if(*p == node){
//					prev->next = node;
					prev = node;
					node = node->next;
				} else {
					ListNode *next = *p;
					*p = node;
					prev->next = node->next;
					(*p)->next = next;
					node = prev->next;
				}
			}
			return sortedHead;
		}
};
int main()
{
	Solution s;
	ListNode *head = new ListNode(1);
	ListNode *p1 = new ListNode(3);
	ListNode *p2 = new ListNode(2);
	ListNode *p3 = new ListNode(0);

	head->next = p1;
	p1->next = p2;
	p2->next = p3;

	ListNode *node = s.insertionSortList(head);
	while(node){
		printf("%d\n", node->val);
		node = node->next;
	}
}
