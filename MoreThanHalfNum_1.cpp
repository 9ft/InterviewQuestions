#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int result = numbers[0];
        int times = 1;
        for(int i = 1; i < numbers.size(); i++){
            if(!times){
                result = numbers[i];
                times = 1;
            }else if(numbers[i] == result)
                times++;
            else
                times--;
        }
        return checkMoreThanHalf(numbers, result) ? result : 0;
    }
private:
    bool checkMoreThanHalf(vector<int> &numbers, int target){
        int count = 0;
        for(int i = 0; i < numbers.size(); i++)
            if(numbers[i] == target)
                count++;
        return count*2 > numbers.size();
    }
};

int main(int argc, char const* argv[])
{

    return 0;
}
