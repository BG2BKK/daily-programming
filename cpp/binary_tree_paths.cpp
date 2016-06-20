#include <iostream>
#include <vector>
using namespace std;
class TreeNode {
	public:
		int val;
		TreeNode *left, *right;
		TreeNode(int val) {
			this->val = val;
			this->left = this->right = NULL;
		}
};
class Solution {
	public:
		vector<string> treepath(TreeNode *root, vector<string> &vec, string str){
			if(!root->left && !root->right){
				if(str != ""){
					vec.push_back(str);
					return vec;
				}
			}
			//if(root->left)
			treepath(root->left, vec, str == "" ? str+(char)('0' + root->val) : str+","+(char)('0' + root->val));
			// if(root->right)
			treepath(root->right, vec, str == "" ? str+(char)('0' + root->val) : str+","+(char)('0' + root->val));
			return vec;
		}
		vector<string> binaryTreePaths(TreeNode* root) {
			// Write your code here
			vector<string> vec;
			if(!root){
				return vec;
			}
			string str = "";
			return treepath(root, vec, str);
		}
};

int main(){
	TreeNode *root = new TreeNode(1);
	TreeNode *p1 = new TreeNode(2);
	TreeNode *p2 = new TreeNode(3);
	TreeNode *p3 = new TreeNode(5);

	root->left = p1;
	root->right = p2;
	p1->right = p3;

	Solution s;
	vector<string> v = s.binaryTreePaths(root);
	for(int i=0;i<v.size();i++){
		cout << v[i] << endl;
	}	
}
