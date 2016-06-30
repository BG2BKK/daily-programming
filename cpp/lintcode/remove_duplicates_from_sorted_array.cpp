#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int removeDuplicates(vector<int> &nums) {
			// write your code here
			int len = nums.size();
			if(len <= 1) return len;
			int prev = nums[len - 1];
			int pos = len - 1;
			for (int i = pos - 1; i >= 0; i--){
				if(prev == nums[i]){
				} else {
					nums[--pos] = nums[i];
					prev = nums[i];
				}
			}
			for(int i=0;i<len - pos;i++){
				nums[i] = nums[pos+i];
			}
			return len - pos ;
		}
};
int main(){
	vector<int> a = {-10,0,1,1,2,3}; 
	Solution s;
	int n = s.removeDuplicates(a);
	for(int i=0; i<a.size();i++){
		printf("%d\t", a[i]);
	}
	cout << endl;
	cout << n <<endl;
}
