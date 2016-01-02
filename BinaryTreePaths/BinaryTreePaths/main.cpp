#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> result;
		if (!root) return result;
		binaryTreePathIter(result, root, std::to_string(root->val));
		return result;
	}
	void binaryTreePathIter( vector<string>& result,TreeNode* root,string str){
		if (!root->left&&!root->right)
			result.push_back(str);
		if (root->left)
			binaryTreePathIter(result, root->left, str + "->" + std::to_string(root->left->val));
		if (root->right)
			binaryTreePathIter(result, root->right, str + "->" + std::to_string(root->right->val));
	}
};
int main()
{ 
	return 0;
}