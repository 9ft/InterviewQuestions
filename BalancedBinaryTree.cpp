class Solution {
public:
    bool IsBalanced_Solution(TreeNode* root) {
        int height = 0;
        return isBalanced(root, height);
    }

private:
    bool isBalanced(TreeNode* root, int &height){
        int left, right;
        if(!root){
            height = 0;
            return true;
        }
        if(isBalanced(root->left, left) && isBalanced(root->right, right)){
            int diff = left - right;
            if(diff <=1 && diff >= -1){
                height = 1 + max(left, right);
                return true;
            }
        }
        return false;
    }
};
