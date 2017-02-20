#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int start = 0, end = numbers.size()-1, mid = numbers.size() >> 1;
        int index = Partition(numbers, start, end);
        while(index != mid){
            if(index > mid){
                end = index-1;
            }else{
                start = index+1;
            }
            index = Partition(numbers, start, end);
        }
        int result = numbers[mid];
        return checkMoreThanHalf(numbers, result) ? result : 0;
    }
private:
    int Partition(vector<int> &numbers, int start, int end){
        int pivot = numbers[start];
        while(start < end){
            while(start < end && numbers[end >= pivot])
                --end;
            numbers[start] = numbers[end];
            while(start < end && numbers[start] <= pivot)
                ++start;
            numbers[end] = numbers[start];
        }
        numbers[start] = pivot;
        return start;
    }
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
