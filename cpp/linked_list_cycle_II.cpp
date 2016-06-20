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
		ListNode *detectCycle(ListNode *head) {
			if(!head)
				return NULL;
			ListNode *slow = head;
			ListNode *fast = head->next;
			while(fast){
				if(slow == fast)
					break;
				fast = fast->next;
				if(!fast)
					return NULL;
				fast = fast->next;
				slow = slow->next;
			}
			if(!fast)
				return NULL;
//			printf("%d %d\n", fast->val, slow->val);

			ListNode *meet = fast;
			ListNode *listA = meet->next;
			ListNode *listB = head;
			int lenA = 0;
			while(listA != meet){
				listA = listA -> next;
				lenA ++;
			}
			int lenB = 0;
			while(listB != meet){
				listB = listB->next;
				lenB ++;
			}
			int diff = lenA - lenB;
			slow = diff > 0 ? head : meet->next;
			fast = diff <= 0 ? meet->next : head;
			diff = diff > 0 ? diff : -diff;
			while(diff--)
				fast = fast->next;
			while(slow != fast){
				slow = slow->next;
				fast = fast->next;
			}
			return fast;        
		}
};
int main()
{
	Solution s;
	ListNode *head = new ListNode(0);
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(2);
	ListNode *p3 = new ListNode(3);
	ListNode *p4 = new ListNode(4);
	head->next = p1;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p1;
	ListNode *node = s.detectCycle(head);
	if(node)
		printf("%d\n", node->val);
	else 
		printf("NULL\n");
}
