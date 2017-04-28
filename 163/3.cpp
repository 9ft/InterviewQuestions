#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, tmp;
    vector<int> v;
    while(cin >> n){
        v.clear();
        for(int i = 0; i < n; i++){
            cin >> tmp;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end(), [](int a, int b) {
        	return b < a;
    	});
        int task1 = 0;
        int task2 = 0;

        for(int i = 0; i < v.size(); i++){
            if(task1 <= task2){
                task1 += v[i];
            }else{
                task2 += v[i];
            }
        }
        int max = task1 > task2 ? task1 : task2;
        cout << max << endl;
    }
    return 0;
}
