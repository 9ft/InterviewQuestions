#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> results;
        sort(str.begin(), str.end());
        Permutation(str, 0, results);
        return results;
    }
private:
    void Permutation(string str, int begin, vector<string> &results){
        if(begin == str.length()-1){
            results.push_back(str);
            return;
        }
        for(int i = begin; i < str.length(); i++){
            if(i != begin && str[i]==str[begin])
                continue;
            swap(str[begin], str[i]);
            Permutation(str, begin+1, results);
        }

    }
};

int main(int argc, char const* argv[])
{
    Solution sol;
    vector<string> results;
    results = sol.Permutation("abbc");
    for(string &s : results){
        cout << s << endl;
    }
    return 0;
}
