#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return reConstructBinaryTree_recursive(pre, vin, 0, pre.size()-1, 0, vin.size()-1);
    }

private:
    TreeNode* reConstructBinaryTree_recursive(vector<int> &pre, vector<int> &in, int ps, int pe, int is, int ie){
        if(ps > pe)
            return NULL;
        TreeNode *node = new TreeNode(pre[ps]);
        int pos = is;
        for(; pos<= ie && in[pos] != pre[ps]; pos++){}
        node->left = reConstructBinaryTree_recursive(pre,in,ps+1,ps-is+pos,is,pos-1);
        node->right = reConstructBinaryTree_recursive(pre,in,pe-ie+pos+1,pe,pos+1,ie);

        return node;
    }
};

int main(int argc, char const* argv[])
{
    vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> in = {4, 7, 2, 1, 5, 3, 8, 6};
    Solution sol;
    sol.reConstructBinaryTree(pre,in);
    return 0;
}
