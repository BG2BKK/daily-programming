#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
	public:

		vector<int> singleNumberIII(vector<int> &A) {
			vector<int> ret;
			int len = A.size();
			if(len % 2 !=0)
				return ret;
			int temp = 0;
			for(auto n : A){
				temp = temp ^ n;
			}
			for(auto n : A){
				temp = temp ^ n;
			}
		}
};

int main(){
	vector<int> A = {1,1,2,2,6,4,5,0,4,5,6,7};
	Solution s;
	vector<int> ret = s.singleNumberIII(A);
	for(auto n:ret){
		cout << n<<endl;
	}
}
