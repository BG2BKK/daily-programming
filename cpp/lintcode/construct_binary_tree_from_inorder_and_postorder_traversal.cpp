
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
		TreeNode *getTree(vector<int> &inorder, int in_st, int in_ed, vector<int> &postorder, int po_st, int po_ed){
			if(in_st > in_ed)
				return NULL;
			else if(in_st == in_ed)
				return new TreeNode(inorder[in_st]);
			TreeNode *root = new TreeNode(postorder[po_ed]);

			int idx = in_st;
			for(; idx <= in_ed; idx++){
				if(postorder[po_ed] == inorder[idx])
					break;
			}
			root->left = getTree(inorder, in_st, idx-1, postorder, po_st, po_st+idx-1-in_st);
			root->right = getTree(inorder, idx+1, in_ed, postorder, idx, po_ed-1);
			return root;
		}
		TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
			// write your code here
			TreeNode *root = NULL;
			if(inorder.size() != postorder.size())
				return root;
			if(inorder.size() < 1)
				return root;
			else if(inorder.size() == 1) {
				root = new TreeNode(inorder[0]);
				return root;
			} else{
				int len = postorder.size();
				root = new TreeNode(postorder[len-1]);
				int idx = 0;
				for(; idx < len; idx++){
					if(postorder[len-1] == inorder[idx])
						break;
				}
				root->left = getTree(inorder, 0, idx-1, postorder,0,idx-1);
				root->right = getTree(inorder, idx+1, len-1, postorder, idx, len-2);
				return root;
			}
		}
};

void Traverse(TreeNode *root){
	if(!root) 
		return;
	cout << root->val <<endl;
	Traverse(root->left);
	Traverse(root->right);
}

int main(){
	vector<int> v1 = {3,4,5,6,7,8,9,10,11,15,17,1};
	vector<int> v2 = {17,15,11,10,9,8,7,6,5,4,3,1};
	Solution s;
	TreeNode *node = s.buildTree(v1, v2);
	Traverse(node);
}
