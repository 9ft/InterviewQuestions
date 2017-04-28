#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int reverseAdd(int a, int b){
    string aStr = to_string(a);
    string bStr = to_string(b);
    reverse(aStr.begin(), aStr.end());
    reverse(bStr.begin(), bStr.end());
    a = stoi(aStr);
    b = stoi(bStr);
    return a + b;
}

int main(){
    string str;
    while(cin >> str){
        replace(str.begin(), str.end(), ',', ' ');
        istringstream is(str);
        int a, b;
        is >> a >> b;
        cout << reverseAdd(a, b) << endl;
    }
    return 0;
}
