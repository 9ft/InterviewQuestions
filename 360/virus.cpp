/*
病毒（3602017秋招真题）
题目描述

小B最近对破解和程序攻击产生了兴趣，她迷上了病毒，然后可怕的事情就发生了。不知道什么原因，可能是小B的技术水平还不够高，小B编写的病毒程序在攻击一个服务器时出现了问题。尽管成功的侵入了服务器，但并没有按照期望的方式发挥作用。

小B的目的很简单:控制服务器的内存区域，试图在内存中装入从1到n之间的n个自然数，以覆盖内存区域。可能是小B对编程理解上的问题，病毒似乎没有完全成功。可能是由于保护机制的原因，内存写入只接受二进制的形式，所以十进制表达中除0和1之外的其他值都没有成功写入内存。小B希望知道，究竟有多少数成功的写入了服务器的内存！

样例输入
10
20

样例输出
2
3
*/


#include <iostream>
using namespace std;

int digit(int n){
    int res = 0;
    while(n>0){
        n /= 10;
        res++;
    }
    return res;
}
int pow(int a, int n){
    if(n==1) return a;
    int b = pow(a, n/2);
    if((n&1)==1) return b*b*a;
    else return b*b;
}
int main(){
    int n, res = 0;
    while(cin>>n){
        res = 0;
        int t = n;
        while(t>0){
            int d = digit(t);
            if(d>1){
                int u = pow(10, d-1);
                int r = t%u;
                int m = t/u;
                if(m > 1){
                    res += pow(2, d)-1;
                    break;
                }else{
                    res += pow(2, d-1);
                }
                t = r;
            }else{
                res++;
                break;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
