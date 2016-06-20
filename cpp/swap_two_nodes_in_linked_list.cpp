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
		ListNode* swapNodes(ListNode* head, int val1, int val2) {
			if(!head)
				return head;

			ListNode **node;

			node = &head;
			while(*node && (*node)->val != val1) 
				node = &((*node)->next);
			if(!*node ) 
				return head;
			ListNode **v1_node = node;

			node = &head;
			while(*node && (*node)->val != val2) 
				node = &((*node)->next);
			if(!*node ) 
				return head;
			ListNode **v2_node = node;

			if( (*v1_node)->next == *v2_node) {

				ListNode *temp = *v1_node;
				ListNode *temp_next = (*v2_node)->next;
				(*v2_node)->next = *v1_node;
				*v1_node = *v2_node;
				temp->next = temp_next;

			} else if ((*v2_node)->next == *v1_node){
				ListNode *temp = *v2_node;
				ListNode *temp_next = (*v1_node)->next;
				(*v1_node)->next = *v2_node;
				*v2_node = *v1_node;
				temp->next = temp_next;

			} else {
				ListNode *temp1_next = (*v1_node)->next;
				ListNode *temp2_next = (*v2_node)->next;

				(*v1_node)->next = temp2_next;
				(*v2_node)->next = temp1_next;

				ListNode *temp = *v1_node;
				*v1_node = *v2_node;
				*v2_node = temp;
			}

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
	ListNode *node = s.swapNodes(head, 3, 2);
	while(node){
		printf("%d\n", node->val);
		node = node->next;
	}
}
