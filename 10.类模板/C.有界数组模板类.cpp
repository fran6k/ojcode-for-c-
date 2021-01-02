/*
题目描述

编写有界数组模板BoundArray（即检查对数组元素下标引用并在下标越界时终止程序的执行），能够存储各种类型的数据。要求实现对数组进行排序的方法sort，及对数组进行查找的方法search。

输入

第一行先输入t，表示有t个测试用例

从第二行开始输入每个测试用例的数据。

首先输入数据类型，I表示int，D表示double，C表示char，接着输入数组的元素个数

然后输入每个元素

最后输入要查找的元素

输出

首先输出从小到大排序的元素

然后输出查找元素的结果，找到则输出下标，下标为排序后的下标，没找到则输出-1

样例输入

2
I 2
1 2
2
D 3
3.5 6.2 2.9
2.1
样例输出

1 2 
1
2.9 3.5 6.2 
-1
*/

#include <iostream>
using namespace std;

template<class type>
class matrix{
protected:
    type *arr;
    int n;
public:
    matrix(int _n):n(_n){}
    void input(){
        int i;
        arr=new type[n];
        for(i=0;i<n;i++)cin>>arr[i];
    }
    void transport(){
        int i,j;
        for(i=0;i<n-1;i++){
            for(j=i;j<n;j++){
                if(arr[i]>arr[j]){
                    type tem;
                    tem = arr[i];
                    arr[i]=arr[j];
                    arr[j]=tem;
                }
            }
        }

    }
    void search(type a){
        int flag=0;
        int i;
        for(i=0;i<n;i++){
            if (a==arr[i]){
                cout<<i<<endl;
                flag=1;
            }
        }
        if (flag==0)cout<<-1<<endl;
        flag=0;
    }
    void print(){
        int i;
        for(i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        char c;
        int n;
        int s;
        cin>>c;
        cin>>n;
        switch (c){
        case 'I':{
            matrix<int> t1(n);
            t1.input();
            t1.transport();
            cin>>s;
            t1.print();
            t1.search(s);
            break;
        }
        case 'D':{
            matrix<double> t2(n);
            t2.input();
            t2.transport();
            cin>>s;
            t2.print();
            t2.search(s);
            break;
        }
        case 'C':{
            matrix<char> t3(n);
            t3.input();
            t3.transport();
            cin>>s;
            t3.print();
            t3.search(s);
            break;
        }

        }
    }
    return 0;
}
