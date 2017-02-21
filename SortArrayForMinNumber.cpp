#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> nums;
        for(int &i : numbers)
            nums.push_back(to_string(i));
        sort(nums.begin(), nums.end(), cmp);
        string result = "";
        for(string &s : nums)
            result += s;
        return result;
    }
private:
    static bool cmp(string a, string b){
        return a+b < b+a;
    }
};

int main(int argc, char const* argv[])
{

    return 0;
}
