class Solution {
public:
    bool HasSubtree(TreeNode* pRootA, TreeNode* pRootB){
        if (pRootA == NULL || pRootB == NULL) return false;
        return isSubtree(pRootA, pRootB) ||
            HasSubtree(pRootA->left, pRootB) ||
            HasSubtree(pRootA->right, pRootB);
    }
private:
    bool isSubtree(TreeNode* pRootA, TreeNode* pRootB) {
        if (pRootB == NULL) return true;
        if (pRootA == NULL) return false;
        if (pRootB->val == pRootA->val) {
            return isSubtree(pRootA->left, pRootB->left)
                && isSubtree(pRootA->right, pRootB->right);
        } else
            return false;
    }
};

