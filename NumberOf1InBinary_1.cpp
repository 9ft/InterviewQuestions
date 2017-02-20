#include<iostream>

using namespace std;

class Solution {
public:
     int NumberOf1(int n) {
         int count = 0;
         while(n){
            count++;
            n = (n-1) & n;
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
