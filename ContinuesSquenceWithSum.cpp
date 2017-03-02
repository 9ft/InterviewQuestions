class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > results;
        int a = 1, b = 2, a_b = 3;
        while(b <= (sum+1)/2){
            if(a_b < sum){
                b++;
                a_b += b;
            }else if(a_b > sum){
                a++;
                a_b -= (a-1);
            }else{
                vector<int> result;
                for(int i = a; i <= b; i++)
                    result.push_back(i);
                results.push_back(result);
                b++;
                a_b += b;
            }
        }
        return results;
    }
};
