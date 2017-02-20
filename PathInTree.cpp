#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > results;
        vector<int> result;
        pathSum(root, results, expectNumber, result);
        return results;
    }
private:
    void pathSum(TreeNode *root, vector<vector<int> > &results, int sum, vector<int> &result){
        if(!root) return;
        result.push_back(root->val);
        sum -= root->val;
        if(!sum && !root->left && !root->right){
            results.push_back(result);
        }
        pathSum(root->left, results, sum, result);
        pathSum(root->right, results, sum, result);
        result.pop_back();
    }
};
