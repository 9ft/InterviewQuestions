#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findDiff_N(string &word, vector<string> &dict, int diffCount) {
        vector<string> result;
        for(string &str : dict){
            int count = 0;
            for(int i = 0; i < word.size(); i++)
                if(word[i] != str[i])
                    count++;
            if(count == diffCount)
                result.push_back(str);
        }
        return result;
    }
    int ladderLength(string &start, string &target, vector<string> &dict) {
        queue<pair<string, int> > q;
        q.push(make_pair(start, 0));
        while(!q.empty()) {
            string word = q.front().first;
            int count = q.front().second;
            if(word==target)
                return count+1;
            q.pop();
            vector<string> diff_1 = findDiff_N(word, dict, 1);
            for(string &s : diff_1)
                q.push(make_pair(s, count+1));
        }
        return -1;
    }
};


int main(int argc, const char * argv[]) {
    /*
     input:
hot
dog
got dot god dog lot log
    */
    string begin, target, dictWords, tmp;
    vector<string> dict;
    getline(cin, begin);
    getline(cin, target);
    getline(cin, dictWords);
    istringstream is(dictWords);
    while(is >> tmp)
        dict.push_back(tmp);
    // output
    Solution sol;
    cout << sol.ladderLength(begin, target, dict) << endl;
    return 0;
}
