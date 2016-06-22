#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
	public:
		int longestCommonSubstring(string A, string B) {
			int maxlen = 0;
			int lenA = A.length();
			int lenB = B.length();
			int matrix[lenA+1][lenB+1];
			for(int i=0; i <= lenA; i++)
			for(int j=0; j <= lenB; j++)
				matrix[i][j] = 0;
			for(int i=1;i<=lenA;i++){
				for (int j=1; j<=lenB; j++){
					if(A[i-1] == B[j-1]){
						matrix[i][j] = matrix[i-1][j-1] + 1;
						if(matrix[i][j] > maxlen)
							maxlen = matrix[i][j];
					}
				}
			}
			return maxlen;
		}

		string LCS(string A, string B){
			int maxlen = 0;
			int lenA = A.length();
			int lenB = B.length();
			int matrix[lenA+1][lenB+1];
			char mark[lenA+1][lenB+1];
			for(int i=0; i <= lenA; i++)
				for(int j=0; j <= lenB; j++)
				{
					matrix[i][j] = 0;
					mark[i][j] = 0;
				}
			for(int i=1;i<=lenA;i++){
				for (int j=1; j<=lenB; j++){
					if(A[i-1] == B[j-1]){
						matrix[i][j] = matrix[i-1][j-1] + 1;
						if(matrix[i][j] > maxlen)
							maxlen = matrix[i][j];
						mark[i][j] = '*';
					} else if (matrix[i-1][j] > matrix[i][j-1]){
						matrix[i][j] = 0;
						mark[i][j] = '|';
					} else {
						matrix[i][j] = 0;
						mark[i][j] = '-';
					}
				}
			}

			string s = "";
			for(int i=1;i<=lenA;i++){
				for (int j=1; j<=lenB; j++){
					s = "";
					int len = 0;
					int ii = i;
					int jj = j;
					while(ii <= lenA && jj <= lenB && mark[ii][jj] == '*'){
						s = s + A[ii-1];
						len ++;
						if(len == maxlen)
							return s;
						ii ++;
						jj ++;
					}

				}
			}

			return s;
		}
};

int main(){

	string A = "gccctagcg";
	string B = "gcgcaatg";
	Solution s;
	cout << s.longestCommonSubstring(A, B) << endl;
	cout << s.LCS(A, B) << endl;
}
