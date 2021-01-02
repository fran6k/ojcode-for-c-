/*
题目描述

输入三个整数，然后按照从大到小的顺序输出数值。

要求：用三个指针分别指向这三个整数，排序过程必须通过这三个指针来操作，不能直接访问这三个整数

输出时，必须使用这三个指针，不能使用存储三个整数的变量

输入

第一行输入t表示有t个测试实例

第二行起，每行输入三个整数

输入t行

输出

每行按照从大到小的顺序输出每个实例

在每行中，每个数据输出后都带有一个空格，即使该行最后一个数据输出后也要再输出一个空格

样例输入

3
2 4 6
88 99 77
111 333 222
样例输出

6 4 2 
99 88 77 
333 222 111 
*/
#include <iostream>
#include <algorithm>

using namespace std;

void swap(int * p1, int *p2, int *p3)
{
	int a[]={*p1,*p2,*p3};
    int min_data = *min_element(a,a+3);
    int max_data = *max_element(a,a+3);
    int i = 0;
    int mid = 0;
    for(i=0;i<3;i++){
    	if (a[i]!= min_data && a[i] != max_data){
    		mid = a[i];
		}
	}
    cout << max_data << " " << mid << " " << min_data <<"\n";
}

int main() {
	int T = 0;
	int a,b,c;
	for(cin>>T;T>0;T--){
		cin>>a;
		cin>>b;
		cin>>c;
		swap(&a,&b,&c);
	}


	return 0;
}
