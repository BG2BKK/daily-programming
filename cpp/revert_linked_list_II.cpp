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
		ListNode *reverseBetween(ListNode *head, int m, int n) {
			ListNode **st = &head;
			while(--m)
				st = &((*st)->next);
			ListNode **ed = &head;
			while(--n)
			{
				ed = &((*ed)->next);
			}
			ListNode *p = *st;
			ListNode *tail = (*ed)->next;
			ListNode *prev = (*ed)->next;
			while(p != tail){
				ListNode *next = p->next;
				p->next = prev;
				prev = p;
				p = next;
			}
			*st = prev;
			return head;
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

	ListNode *node = s.reverseBetween(head, 1, 3);
	while(node){
		printf("%d\n", node->val);
		node = node->next;
	}
}
