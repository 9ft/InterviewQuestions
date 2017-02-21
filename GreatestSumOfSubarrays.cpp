#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int sum = 0, result = array[0];
        for(int i = 0; i < array.size(); i++){
            sum += array[i];
            result = max(sum, result);
            sum = max(sum, 0);
        }
        return result;
    }
};

int main(int argc, char const* argv[])
{

    return 0;
}
