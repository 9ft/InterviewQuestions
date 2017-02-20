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
        TreeNode *head = NULL;
        Convert(pRootOfTree, head);
        return head;
    }
private:
    void Convert(TreeNode *root, TreeNode *&head){
        if(!root) return;
        Convert(root->right, head);
        root->right = head;
        if(head) head->left = root;
        head = root;
        Convert(root->left, head);
    }
};

int main(int argc, char const* argv[])
{

    return 0;
}
