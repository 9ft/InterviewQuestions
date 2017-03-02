#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data. size () == 0 ) return 0 ;
        else if (data. size() == 1 ) return 1 ;
        else {
            vector<int> copy(data);
            return InversePairs(data, copy, 0 , data.size()- 1);
        }
    }
private:
    int InversePairs(vector<int> &data, vector<int> &copy, int start, int end){
        if(start == end)
            return 0;
        long mid = (start + end) >> 1;
        long left = InversePairs(copy, data, start, mid); // 递归，归并排序，并计算本次逆序对数
        long right = InversePairs(copy, data, mid+1, end);
        long crossCount = 0 ;       // 记录交叉的逆序对数
        long i = mid, j = end, temp = end;  //i：前半部分的下标，j：后半部分的下标，temp：辅助数组的下标

        while(i >= start && j > mid) {   // 存在交叉的逆序对，先统计一下，然后依次将较大值放进辅助数组
            if (data[i] > data[j]) {
                copy[temp--] = data[i--];
                crossCount += j - start - (mid-start);
            } else {
                copy[temp--] = data[j--];   // 不存在交叉的逆序对，依次将较大值放进辅助数组
            }
        }
        while(i >= start) {
            copy[temp--] = data[i--];
        }
        while(j > mid) {
            copy[temp--] = data[j--];
        }
        return (left + right + crossCount) % 1000000007; //数值过大时求余, 防止溢出
    }
};

int main(int argc, char const* argv[])
{
    Solution sol;
    cout << sol.InversePairs(vector<int>{7,5,6,4});
    return 0;
}
