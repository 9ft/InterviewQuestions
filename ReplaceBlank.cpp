#include <iostream>

using namespace std;

void ReplaceBlank(char string[], int length){
    int blankCount = 0;
    for(int i = 0; i < length; i++){
        if(string[i] == ' '){
            blankCount++;
        }
    }
    int newLength = length + blankCount * 2;

    for(int i = newLength, p = length-1; i >= 0;){
        if(string[p] != ' '){
            string[i--] = string[p--];
        }else{
            string[i--] = '0';
            string[i--] = '2';
            string[i--] = '%';
            p--;
        }
    }

}

int main(int argc, char const* argv[])
{
    char string[20] = "we are happy";
    ReplaceBlank(string, 12);
    for(int i = 0; i < 20; i++){
        cout << string[i];
    }
    return 0;
}
