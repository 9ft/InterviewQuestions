#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int length = sequence.size();
        if(!length) return false;
        int r = 0;
        for(; r <= length-1 && sequence[r] < sequence[length-1]; r++){}
        vector<int> left = r ? vector<int>(sequence.begin(), sequence.begin()+r-1) : vector<int>();
        vector<int> right = r!=length-1 ? vector<int>(sequence.begin()+r, sequence.begin()+length-2) : vector<int>();
        for(int &i : right)
            if(i < sequence[length-1])
                return false;
        return (left.size() ? VerifySquenceOfBST(left) : true)
            && (right.size() ? VerifySquenceOfBST(right) : true);
    }
};


int main(int argc, char const* argv[])
{

    return 0;
}
