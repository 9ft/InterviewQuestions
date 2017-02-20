#include<iostream>

using namespace std;

bool Increment(string &num){
    for(int i = num.length()-1; i >= 0; i--){
        if(num[i] - '0' + 1 >= 10){
            num[i] = (num[i] - '0' + 1) % 10 + '0';
        }else{
            num[i] = num[i] + 1;
            return true;
        }
    }

    return false;
}

void PrintNum(string &num){
    bool isPrint = false;
    for(char &c : num){
        if(c != '0'){
            isPrint = true;
        }
        if(isPrint){
            cout << c;
        }
    }
}

void Print1ToMaxOfNDigits(int n){
    string num(n, '0');
    while(Increment(num)){
        PrintNum(num);
        cout << " ";
    }
}


int main(int argc, char const* argv[])
{
    Print1ToMaxOfNDigits(4);
    return 0;
}
