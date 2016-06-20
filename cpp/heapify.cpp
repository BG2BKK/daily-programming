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
		/**
		 *
		 *          * @param A: Given an integer array
		 *
		 *                   * @return: void
		 *
		 *                            */
		void adjust(vector<int> &A, int idx){
			while(1){
				int left = 2*idx+1;
				if(left >= A.size())
					break;
				int right = 2*idx+2;
				int pos = left;
				int val = A[pos];
				if(right < A.size()){
					if(A[left] > A[right]){
						pos = right;
						val = A[pos];
					}
				}
				if(A[idx] > val){
					int temp = A[idx];
					A[idx] = A[pos];
					A[pos] = temp;
				}
				idx = pos;
			}
		}
		void heapify(vector<int> &A) {
			// write your code here
			int len = A.size();
			for(int i = len/2 - 1; i>= 0; i--){
				adjust(A, i);
			}
		}
};
int main()
{
	vector<int> A = {3,2,1,4,5};
	Solution s;
	s.heapify(A);
	for (int i=0;i<A.size();i++)
	{
		printf("%d\t", A[i]);
	}
	printf("\n");
}
