#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;
int main() {
    string str;
    while(cin >> str){
        vector<char> oper;
        for(int i = 0; i < str.length(); i++){
            if(str[i] == '+' || str[i] == '-' || str[i] == '*'){
                oper.push_back(str[i]);
            }
        }
        replace(str.begin(), str.end(), '+', ' ');
        replace(str.begin(), str.end(), '-', ' ');
        replace(str.begin(), str.end(), '*', ' ');
        //cout << str <<endl;
        //for(char c: oper){
        //    cout << c;
        //}
        //cout <<endl;
        istringstream is(str);
        int a, b;
        is >> a;
        for(int i = 0; i < oper.size(); i++){
            is >> b;
            if(oper[i] == '+'){
                a = a+b;
            }
            if(oper[i] == '-'){
                a = a-b;
            }
            if(oper[i] == '*'){
                a = a*b;
            }
        }
        cout << a << endl;
    }
    return 0;
}
