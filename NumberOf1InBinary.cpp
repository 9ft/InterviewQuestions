#include<iostream>

using namespace std;

class Solution {
public:
     int NumberOf1(int n) {
         int count = 0;
         unsigned int flag = 1;
         while(flag){
             if(n & flag){
                 count++;
             }
             flag = flag << 1;
         }
         return count;
     }
};

int main(int argc, char const* argv[])
{
    Solution sol;
    cout << sol.NumberOf1(9) << endl;
    return 0;
}
