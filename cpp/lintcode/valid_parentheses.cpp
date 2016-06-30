#include <iostream>
#include <map>
#include <stack>
using namespace std;
class Solution {
	public:
		bool isValidParentheses(string& s) {
			// Write your code here
			int len = s.length();
			if(len < 1 || len%2!=0)
				return false;
			stack<char> st;
			map<char,char> m;
			m['('] = ')';
			m['{'] = '}';
			m['['] = ']';
			for(int i=0;i<len;i++){
				if(!st.empty() && m[st.top()] == s[i]){
					st.pop();
				} else{
					st.push(s[i]);
				}
			}
			if(!st.empty())
				return false;
			return true;
		}
};
int main()
{
	string str = "()";
	Solution s;
	cout << s.isValidParentheses(str) <<endl;

}
