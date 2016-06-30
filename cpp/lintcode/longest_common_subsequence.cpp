#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
	public:
		int longestCommonSubsequence(string A, string B) {
			int lenA = A.length();
			int lenB = B.length();
			int matrix[lenA+1][lenB+1];
			for(int i=0; i <= lenA; i++)
				matrix[i][0] = 0;
			for(int j=0; j <= lenB; j++)
				matrix[0][j] = 0;
			for(int i=1;i<=lenA;i++){
				for (int j=1; j<=lenB; j++){
					if(A[i-1] == B[j-1]){
						matrix[i][j] = matrix[i-1][j-1] + 1;
					} else {
						matrix[i][j] = matrix[i-1][j] > matrix[i][j-1] ? matrix[i-1][j] : matrix[i][j-1];
					}
				}
			}
			return matrix[lenA][lenB];
		}

		string LCS(string A, string B){
			int lenA = A.length();
			int lenB = B.length();
			int matrix[lenA+1][lenB+1];
			char mark[lenA+1][lenB+1];
			for(int i=0; i <= lenA; i++)
				matrix[i][0] = 0;
			for(int j=0; j <= lenB; j++)
				matrix[0][j] = 0;
			for(int i=1;i<=lenA;i++){
				for (int j=1; j<=lenB; j++){
					if(A[i-1] == B[j-1]){
						matrix[i][j] = matrix[i-1][j-1] + 1;
						mark[i][j] = '*';
					} else {
						if(matrix[i-1][j] >= matrix[i][j-1]){
							matrix[i][j] =matrix[i-1][j];
							mark[i][j] = '|';
						} else {
							matrix[i][j] =matrix[i][j-1];
							mark[i][j] = '-';
						}
					}
				}
			}
			string s = "";
			while(lenA > 0 && lenB > 0){
				if(mark[lenA][lenB] == '*'){
					s = A[lenA - 1] + s;
					lenA --;
					lenB --;
				} else if(mark[lenA][lenB] == '|'){
					lenA --;
				} else {
					lenB --;
				}
			}
			return s;
		}
};

int main(){

	string A = "gccctagcg";
	string B = "gcgcaatg";
	Solution s;
	cout << s.longestCommonSubsequence(A, B) << endl;
	cout << s.LCS(A, B) << endl;
}
