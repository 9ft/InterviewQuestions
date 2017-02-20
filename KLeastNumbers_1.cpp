#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int len=input.size();
        if(len<=0||k>len) return vector<int>();
        //仿函数中的greater<T>模板，从大到小排序
        multiset<int, greater<int> > leastNums;
        vector<int>::iterator vec_it=input.begin();
        for(;vec_it!=input.end();vec_it++){
            //将前k个元素插入集合
            if(leastNums.size()<k)
                leastNums.insert(*vec_it);
            else{
                //第一个元素是最大值
                multiset<int, greater<int> >::iterator greatest_it=leastNums.begin();
                //如果后续元素<第一个元素，删除第一个，加入当前元素
                if(*vec_it<*(leastNums.begin())){
                    leastNums.erase(greatest_it);
                    leastNums.insert(*vec_it);
                }
            }
        }
        return vector<int>(leastNums.begin(),leastNums.end());
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
