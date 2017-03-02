class Solution {
public:
    string ReverseSentence(string &s) {
        int i = 0, j = s.length() - 1;
        while(i < j)
            swap(s[i++], s[j--]);
        i = 0;
        j = 0;
        while(j < s.length()){
            for(i = j; i < s.length() && s[i] == ' '; i++){}
            for(j = i; j < s.length() && s[j] != ' '; j++){}
            j--;
            int tmp = j;
            while(i < j)
                swap(s[i++], s[j--]);
            j = tmp+1;
        }
        return s;
    }
};

