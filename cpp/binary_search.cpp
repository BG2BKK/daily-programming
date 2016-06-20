#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        int st = 0;
        int ed = array.size();
        vector<int> a = array;
        while(st <= ed && st >=0 ){
            int mid = (st+ed)/2;
            if(a[mid] > target){
                ed = mid-1;
            } else if (a[mid] < target){
                st = mid+1;
            } else {
                int i = mid-1;
                while(i>=0) {
                    if (a[i] == target){
                        i--;
                    } else break; 
                }
                return i+1;
            }
        }
        return -1;
    }
};

int main(){
	vector<int> a = {2,6,8,13,15,17,17,18,19,20};
	Solution s;
	int n = s.binarySearch(a, 15);
	cout << n <<endl;
}
