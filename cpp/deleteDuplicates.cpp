/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// http://www.lintcode.com/zh-cn/problem/remove-duplicates-from-sorted-list/

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
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        if(!head || !head->next)
            return head;
        ListNode *prev = head;
        ListNode **p = &(head->next);
        ListNode *node = *p;
        while(node){
            if(node->val == prev->val){
                ListNode *temp = node->next;
                delete node;
                *p = temp;
                node = temp;
            } else {
                prev = node;
                p = &(node->next); // 二级指针的正确用法，p要指向的是node的next指向地址，而不是node的next的地址
                node = node->next;
								   // p = &node;这个就是取原node的next的地址，实际上我们需要的是保持原node的next指向的位置，而不关心下一个node的地址
            }
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
	ListNode *p3 = new ListNode(2);

	head->next = p1;
	p1->next = p2;
	p2->next = p3;

	ListNode *node = s.deleteDuplicates(head);
	while(node){
		printf("%d\n", node->val);
		node = node->next;
	}
}
