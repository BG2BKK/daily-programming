#include <iostream>
#include <string.h>
#include <vector>
#include <stack>
using namespace std;

string test_str(){
	string str = "hello";
	return str;
}

int main(){
	string str_ref = test_str();
	cout << str_ref<<endl;

	vector<vector<int>> ret;
	vector<int> t;
	t.push_back(1);
	cout << t[0] <<endl;
	t.insert(t.begin(), 3);
	cout << t[0] <<endl;

	stack<int> s;

 std::string test = "abc\0\0abc";
 std::cout<<test<<std::endl;
   

}

