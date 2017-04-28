#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    string str;
    long result;
    while(cin >> str){
        reverse(str.begin(), str.end());
        result = 0;
        long j = 1;
        for(char &c : str){
            result += (c-'a') * j;
            j *= 26;
        }
        cout << result << endl;
    }
    return 0;
}
