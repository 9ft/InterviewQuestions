#include<iostream>

using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
        int exponentVal = exponent >=0 ? exponent : -exponent;

        double result = 1.0;
        for(int i = 0; i < exponentVal; i++){
            result *= base;
        }

        cout << "result = " << result << endl;
        return exponent>0 ? result : (result!=0 ? 1/result : 0);
    }
};

int main(int argc, char const* argv[])
{
    Solution sol;
    cout << sol.Power(0,-2) << endl;
    return 0;
}
