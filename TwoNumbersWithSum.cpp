class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> &numbers, int target) {
        int a = 0, b = numbers.size()-1;
        while(a < b){
            if(numbers[a] + numbers[b] < target)
                a++;
            else if(numbers[a] + numbers[b] > target)
                b--;
            else
                return vector<int>{numbers[a], numbers[b]};
        }
        return vector<int>();
    }
};

