#include <iostream>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int i){
        val = i;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode *PreInCreate(vector<int> pre, vector<int> in, int l1, int h1, int l2, int h2){
    TreeNode *root = new TreeNode(pre[l1]);
    int i;
    for (i = l2; in[i] != root->val; i++) {};
    int llen = i-l2;
    int rlen = h2-i;
    if(llen)
        root->left = PreInCreate(pre, in, l1+1, l1+llen, l2, l2+llen-1);
    else
        root->left = nullptr;
    if(rlen)
        root->right = PreInCreate(pre, in, h1-rlen+1, h1, h2-rlen+1, h2);
    else
        root->right = nullptr;
    return root;
}

void LevelOrder(TreeNode *root){
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *tmp;
    while(!q.empty()){
        tmp = q.front();
        if(tmp->left)
            q.push(tmp->left);
        if(tmp->right)
            q.push(tmp->right);
        cout << tmp->val << " ";
        q.pop();
    }
}

void Order(TreeNode *root){
    cout << "abc";
    if(root){
        cout << root->val << " ";
        Order(root->left);
        Order(root->right);
    }
}

int main(int argc, const char * argv[]) {
    int nodeNum;
    //5
    //1 2 4 5 3
    //4 2 5 1 3
    vector<int> pre, in;
    cin >> nodeNum;
    int tmp;
    for (int i = 0; i < nodeNum; i++) {
        cin >> tmp;
        pre.push_back(tmp);
    }
    for (int i = 0; i < nodeNum; i++) {
        cin >> tmp;
        in.push_back(tmp);
    }
    
    TreeNode *tree = PreInCreate(pre, in, 0, pre.size()-1, 0, in.size()-1);
    
    LevelOrder(tree);
    //Order(tree);
    
    
    return 0;
}
