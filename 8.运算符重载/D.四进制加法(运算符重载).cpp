/*
题目描述

定义一个四进制的类，重定义“+”号实现四进制数的累加。

输入

第一行输入所需要的四进制数的个数
第二行开始，依次输入四进制数
输出

所有输入四进制数累加的和

样例输入

3
13
2
21
样例输出

102
*/
#include<iostream>
#include<string>
#include<cstring>
 
#define N 16
 
using namespace std;
 
 
class quan
{
protected:
    char num[N];
 
public:
    quan()
    {
        num[0]='0';
        num[1]=0;
    }
    quan(char *n)
    {
        strcpy(num,n);
    }
    quan(quan &a)
    {
        strcpy(num,a.num);
    }
    void reserve(char *str)
    {
        int len , i = 0;
        char temp;
         
        len = strlen(str);
        for (i = 0; i < len / 2; i++)
        {
            temp = str[i];
            str[i] = str[len - i - 1];
            str[len- i - 1] = temp;
        }
        str[len]=0;
    }
    void fillZero(char *str)
    {   
        int len=strlen(str);
        for(int i=len; i<N; i++)
            str[i]='0';
    }
    quan operator + (quan a)
    {
        reserve(num);
        fillZero(num);
        reserve(a.num);
        fillZero(a.num);
 
        int carry=0,i;
        quan sum;
         
        for(i=0; i<N-1; i++)
        {
            sum.num[i] = num[i]+a.num[i]-'0';
        }
 
        for(i=0; i<N-1; i++)
        {
            if(carry==1)
                sum.num[i]++,carry=0;
             
            if(sum.num[i]=='0'){
                sum.num[i]=0;
                break;
            }   
            if(sum.num[i]>='4')
                carry=1,sum.num[i]-=4;
        }
        reserve(sum.num);
        return sum;
    }
    void set(char *n)
    {
        strcpy(num,n);
    }
    void show()
    {
        cout << num;
    }
 
};
 
 
 
int main()
{
    int t,i;
    char n[N];
 
    cin >> t;
    quan ans;
    quan *num = new quan[t];
 
    for(i=0; i<t; i++)
    {
        cin >> n;
        num[i].set(n);
 
        ans = ans + num[i];
    }
    ans.show();
    return 0;
}