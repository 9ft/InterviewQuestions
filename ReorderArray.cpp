#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int p1 = 0, p2 = array.size()-1;
        while(p1 != p2){
            if((array[p1] & 1) == 1){
                p1++;
            }
            if((array[p2] & 1) == 0){
                p2--;
            }
            if((array[p1] & 1) == 0 && (array[p2] & 1) == 1){
                swap(array[p1], array[p2]);
            }
        }
    }
};

int main(int argc, char const* argv[])
{
    Solution sol;
    //sol.reOrderArray();
    return 0;
}
