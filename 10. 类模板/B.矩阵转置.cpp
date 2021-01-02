/*
题目描述

设计一个矩阵类模板Matrix，支持任意数据类型的数据。

要求至少包含2个成员函数：矩阵转置函数transport、以及打印输出函数print

编写main函数进行测试，调用类的成员函数完成转置和输出。

输入

第一行先输入t，表示有t个测试用例

从第二行开始输入每个测试用例的数据。

首先输入数据类型，I表示int，D表示double，C表示char，接着输入两个参数m和n，分别表示矩阵的行和列

接下来输入矩阵的元素，一共m行，每行n个数据

输出

输出转置后的矩阵

样例输入

2
I 2 3
1 2 3
4 5 6
C 3 3
a b c
d e f
g h i
样例输出

1 4
2 5
3 6
a d g
b e h
c f i

*/


#include <iostream>
using namespace std;
template<class type>
class matrix{
protected:
    type **arr;
    int m,n;
public:
    matrix(int _m,int _n):m(_m),n(_n){}
    void input(){
        int i,j;
        arr=new type*[m];
        for(i=0;i<m;i++)
            arr[i] = new type[n];
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }
    }
    void transport(){
        type **tem;
        int i,j;
        tem=new type*[n];
        for(i=0;i<n;i++)
            tem[i] = new type[m];
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                tem[j][i]=arr[i][j];
            }
        }
        int c=0;
        c=m;
        m=n;
        n=c;
        arr=tem;
            
    }
    void print(){
        int i,j;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }

};

int main(){
    int t;
    cin>>t;
    while(t--){
        char c;
        int m,n;
        cin>>c;
        cin>>m>>n;
        switch (c){
        case 'I':{
            matrix<int> t1(m,n);
            t1.input();
            t1.transport();
            t1.print();
            break;
        }
        case 'D':{
            matrix<double> t2(m,n);
            t2.input();
            t2.transport();
            t2.print();
            break;
        }
        case 'C':{
            matrix<char> t3(m,n);
            t3.input();
            t3.transport();
            t3.print();
            break;

            break;
        }

        }
    }
    return 0;
}
