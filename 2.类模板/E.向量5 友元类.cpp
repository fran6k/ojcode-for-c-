/*
题目描述



在向量CVector类的代码上，定义n阶矩阵类CMatrix，包含私有数据成员M存储矩阵数据，n存储矩阵阶数。

将CMatrix定义为CVector的友元类。

为CMatrix添加成员函数：CVector Multi(const CVector &V1)，计算n阶矩阵与n维向量V1的乘积。

为CMatrix添加成员函数，判定矩阵与向量V1是否可计算乘积。

为CMatrix添加需要的构造函数、析构函数和其它成员函数。

主函数输入数据，测试矩阵与向量的乘积。

附：n阶矩阵包含n*

输入

测试次数t

对每组测试数据，格式如下

第一行，矩阵阶数n 向量维数m

n阶矩阵

m维向量

输出

对每组测试数据，若矩阵与向量不能计算乘积，输出error；否则输出计算结果

样例输入

1
3
1 0 0
0 1 0
0 0 1
3
1 2 3
样例输出
1 2 3
*/
#include <iostream>
#include <cstring>
using namespace std;
class CVector{
private:
    int *v;
    int m;
    friend class CMatrix;
public:
    CVector(int _m):m(_m){}
    void input(){
        int i;
        v = new int[m];
        for(i=0;i<m;i++){
            cin>>v[i];
        }
    }

};
class CMatrix{
private:
    int n;
    int **arr;
public:
    CMatrix(int _n):n(_n){}

    void input(){
        int i,j;
        arr=new int*[n];
        for(i=0;i<n;i++)
            arr[i] = new int[n];
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }
    }
    int judge(const CVector &V1){
        if (n==V1.m)return 0;
        else return 1;
    }
    void CVector_Multi(const CVector &V1){
        int i,j;
        int *x = new int[n];
        memset(x,0,n);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                //矩阵计算
                x[i]=x[i]+arr[i][j]*V1.v[j];
            }
        }
        for(i=0;i<n;i++)
            cout<<x[i]<<" ";
        cout<<endl;
    }
};

int main(){
    int m,n,a;
    cin>>a;
    while(a--){
        cin>>n;
        CMatrix m1(n);
        m1.input();
        cin>>m;
        CVector v1(m);
        v1.input();

        if(m1.judge(v1)==0){
            m1.CVector_Multi(v1);
        }
        else cout<<"error"<<endl;
            
    }

    return 0; 
}