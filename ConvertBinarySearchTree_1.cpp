#include <iostream>

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
    TreeNode* Convert(TreeNode* pRootOfTree){
        if(!pRootOfTree)
            return NULL;
        TreeNode *tail = NULL;
        Convert(pRootOfTree, tail);
        while(pRootOfTree->left)
            pRootOfTree = pRootOfTree->left;
        return pRootOfTree;
    }
private:
    void Convert(TreeNode *root, TreeNode *&tail){
        if(!root) return;
        Convert(root->left, tail);
        if(tail) tail->right = root;
        root->left = tail;
        tail = root;
        Convert(root->right, tail);
    }
};

int main(int argc, char const* argv[])
{

    return 0;
}
