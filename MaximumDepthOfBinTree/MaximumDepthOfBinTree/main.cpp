/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
#include <iostream>
#include <vector>
#include <algorithm>
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (!root) return NULL;
		return std::max(maxDepth(root->left),maxDepth(root->right)) + 1;
	}
};
int main(void){
	TreeNode *tr0 = new TreeNode(0);
	TreeNode *tr1 = new TreeNode(1);
	TreeNode *tr2 = new TreeNode(2);
	tr0->left = tr1;
	tr0->right = tr2;
	Solution s;
	std::cout<<s.maxDepth(tr0)<<std::endl;
	return 0;
}