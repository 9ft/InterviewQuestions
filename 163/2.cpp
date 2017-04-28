#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
int main() {
    int w,x,y,z;
    int count;
    set<float> s;
    while(cin >> w >> x >> y >> z){
        s.clear();
        for(int p = w; p <= x; p++){
            for(int q = y; q <= z; q++){
                s.insert((float)p/(float)q);
            }
        }


        cout << s.size() << endl;
    }
    return 0;
}
