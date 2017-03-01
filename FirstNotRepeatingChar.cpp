class Solution {
public:
    int FirstNotRepeatingChar(string s) {
        vector<int> count(256, -1);
        for(int i = 0; i < s.length(); i++){
            if(count[s[i]] == -1){
                count[s[i]] = i;
            }else if(count[s[i]] != -2){
                count[s[i]] = -2;
            }
        }
        int first = INT_MAX;
        for(int i = 0; i < count.size(); i++){
            if(count[i] != -2 && count[i] != -1){
                first = min(first, count[i]);
            }
        }
        return first == INT_MAX ? -1 : first;
    }
};
