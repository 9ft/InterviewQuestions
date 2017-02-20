#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(!input.size()) return vector<int>();
        int start = 0, end = input.size()-1;
        int index = Partition(input, start, end);
        while(index != k-1){
            if(index > k-1){
                end = index - 1;
            }else{
                start = index + 1;
            }
            index = Partition(input, start, end);
        }
        vector<int> results(input.begin(), input.begin()+k);
        return results;
    }
private:
    int Partition(vector<int> &numbers, int start, int end){
        int pivot = numbers[start];
        while(start < end){
            while(start < end && numbers[end] >= pivot)
                --end;
            numbers[start] = numbers[end];
            while(start < end && numbers[start] <= pivot)
                ++start;
            numbers[end] = numbers[start];
        }
        numbers[start] = pivot;
        return start;
    }
};

int main(int argc, char const* argv[])
{
    vector<int> results;
    Solution sol;
    vector<int> input{4,5,1,6,2,7,3,8};
    results = sol.GetLeastNumbers_Solution(input, 4);
    for(int &i : results)
        cout<< i <<" ";
    return 0;
}
