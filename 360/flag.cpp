/*
最强大脑（3602017秋招真题）
题目描述

小B乘火车和朋友们一起在N市到M市之间旅行。她在路途中时睡时醒。当她醒来观看窗外的风景时，注意到每个火车站都有一种特别颜色的旗帜，但是她看到的旗帜仅仅是经过的一小部分。小B在乘车过程中有两次清醒的时间，她到达旅程终点时处于睡梦中。出站时，她和朋友们谈论着一路的见闻，朋友们觉得很有意思。
他们把N到和M之间经过车站的旗帜颜色依次列出来，然后告诉你小B记得的旗帜颜色序列，让你判断小B究竟是从N和M之间哪些方向才能看到所说颜色的旗帜，还是根本就不可能看到？颜色用字母代表，相同的字母代表相同的颜色，不同的字母则表示不同的颜色。

样例输入
atob
a
b
aaacaaa
aca
aa

样例输出
forward
both
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const* argv[])
{
    string flags, flag1, flag2, res;
    while(cin >> flags){
        cin >> flag1;
        cin >> flag2;
        res = "invalid";
        //forward – 由N到M方向；
        if(flags.find(flag1) != -1){
            if(flags.substr(flags.find(flag1) + flag1.length()).find(flag2) != -1){
                res = "forward";
            }
        }
        //backward – 由M到N方向；
        reverse(flag1.begin(), flag1.end());
        reverse(flag2.begin(), flag2.end());
        if(flags.find(flag2) != -1){
            if(flags.substr(flags.find(flag2) + flag2.length()).find(flag1) != -1){
                if(res == "forward")
                    res = "both";
                else
                    res = "backward";
            }
        }
        cout << res << endl;
    }
    return 0;
}
