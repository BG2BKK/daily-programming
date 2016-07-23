#include <vector>
#include <iostream>
using namespace std;

void print_circle(vector<vector<int>> &array, int x, int y) {
	int len = array.size();
	int s_x = x;
	int s_y = y;
	int e_x = x;
	int e_y = len - 1 - x;

	if(e_y < s_y)
		return;
	for(int i = s_y; i <= e_y; i++) {
		printf("%d\t", array[s_x][i]);
	}

	s_x = x;
	s_y = len - 1 - x;
	e_x = len - 1 - x;
	e_y = len - 1 - x;

	
}

void print_array(vector<vector<int>> &array) {
	int len = array.size();

	for(int i=0; i<len; i++) {
		print_circle(array, i, i);
	}
}

int main(){
	vector<vector<int>> array = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
}
