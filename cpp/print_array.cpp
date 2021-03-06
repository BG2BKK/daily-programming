#include <vector>
#include <iostream>
using namespace std;

void print_circle(vector<vector<int>> arr, int start) {
	int len = arr.size();
	int endX = len - 1 - start;
	int endY = len - 1 - start;

	for(int i = start; i <= endY; i++) {
		printf("%d\t", arr[start][i]);
	}
	if(start + 1 <= endX) {
		for(int i = start+1; i <= endX; i++) {
			printf("%d\t", arr[i][endY]);
		}
	}
	if(start <= endY - 1) {
		for(int i = endY - 1; i >= start; i--) {
			printf("%d\t", arr[endX][i]);
		}
	}

	if(start <= endY - 1 && start + 1 <= endX - 1) {
		for(int i = endX - 1; i > start; i--) {
			printf("%d\t", arr[i][start]);
		}
	}
}

void print_array(vector<vector<int>> arr) {
	int len = arr.size();
	int start = 0;
	while(2*start < len) {
		print_circle(arr, start);
		start ++;
	}
	printf("\n");
}

int main(){
	vector<vector<int>> arr = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16},

	};
	print_array(arr);
}
