#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size() == 0) return false;
        vector<int> stack;
        for(int i = 0, j = 0; i < pushV.size();){
            stack.push_back(pushV[i++]);
            while(j < popV.size() && stack.back() == popV[j]){
                stack.pop_back();
                j++;
            }
        }
        return stack.empty();
    }
};

int main(int argc, char const* argv[])
{

    return 0;
}
