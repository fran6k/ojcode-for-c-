/*
题目描述

某小镇要票选镇长，得票最高者当选。但由于投票机制不健全，导致每届投票时，候选人在投票系统的识别码类型不一致。请编写函数模板，能针对多种类型的数据，查找出得票最高的元素。其中，每届投票的选票有n张，识别码类型为T

注意：必须使用模板函数

输入

第一行输入t表示有t个测试实例

第二行先输入一个大写字母表示识别码类型，I表示整数类型，C表示字符型，S表示字符串型；然后输入n表示数组长度。

第三行输入n个数据

依次输入t个实例

输出

每行输出一个结果，分别输出当选者的识别码和得票数，以空格分开。

样例输入

3
I 10
5 3 5 2 9 7 3 7 2 3
*/

#include<iostream>
#include <cstring>
using namespace std;
template<class T>
void toupiao(T a[],int n) {
	int i,j;
	T zh;

	for(i=0; i<n-1; i++)
		for(j=i+1; j<n; j++)
			if(a[i]>a[j]) {
				zh=a[i];
				a[i]=a[j];
				a[j]=zh;
			}
	T most=a[0]; 	
	T cur=a[0];		
	int max_num=0;		
	int num=1;			
	for(i=0; i<n; i++) {
		if(cur!=a[i+1]) { 
			if(num>max_num) {
			max_num=num;
			most=cur;
		}	
		num=1;
		cur=a[i+1];
		}else
			num++;
	}
	cout<<most<<" "<<max_num<<endl;
}
int main() {
	int t,i,j,n;
	char a;
	cin>>t;
	while(t--) {
		cin>>a>>n;
		switch(a) {
			case 'I': {
				int b[n+1];
				for(i=0; i<n; i++)
					cin>>b[i];
				toupiao(b,n);
				break;
			}
			case 'C': {
				char b[n+1];
				for(i=0; i<n; i++)
					cin>>b[i];
				toupiao(b,n);
				break;
			}
			case 'S': {
				string b[n+1];
				for(i=0; i<n; i++)
					cin>>b[i];
				toupiao(b,n);
				break;
			}
			case 'D': {
				double b[n+1];
				for(i=0; i<n; i++)
					cin>>b[i];
				toupiao(b,n);
				break;
			}
		}
	}
}
