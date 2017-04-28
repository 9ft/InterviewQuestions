#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    vector<vector<int> > graph = {
        {0, 2, 10, 5, 3, -1},
        {-1,0, 12, -1, -1 ,10},
        {-1, -1, 0, -1, 7, -1},
        {2, -1, -1, 1, 0, -1},
        {4, -1, -1, 1, 0, -1},
        {3, -1, 1, -1, 2, 0}
    };
    int from, fog;
    while(cin >> from >> fog){
        string s = "123456";
        for(int i = 0; i < str.length(); i++){
            char tmp;
            switch (str[i]) {
                case 'R':
                    tmp = s[0];
                    s[0] = s[3];
                    s[3] = s[1];
                    s[1] = s[2];
                    s[2] = tmp;
                    break;
                case 'A':
                    tmp = s[0];
                    s[0] = s[4];
                    s[4] = s[1];
                    s[1] = s[5];
                    s[5] = tmp;
                    break;
            }
        }
        cout << s << endl;
    }
    return 0;
}
