/*
题目描述

编写一个在数组中进行查找的函数模板，其中数组为具有n个元素，类型为T，要查找的元素为key。

注意：必须使用模板函数

输入

第一行输入t表示有t个测试实例

第二行先输入一个大写字母表示数组类型，I表示整数类型，D表示双精度数类型，C表示字符型，S表示字符串型；然后输入n表示数组长度。

第三行输入n个数据

第四行输入key

依次输入t个实例

输出

每行输出一个结果，找到输出key是数组中的第几个元素（从1开始），找不到输出0

样例输入

4
I 5
5 3 51 27 9
27
D 3
-11.3 25.42 13.2
2.7
C 6
a b g e u q
a
S 4
sandy david eason cindy
cindy
样例输出

4
0
1
4

*/
#include<iostream>
using namespace std;
template<class T>
void search(T a[],int n,T key) {
	int i,flag=0;
	int cnt=1;
	for(i=0; i<n; i++){
		if(a[i]==key){
			cout<<cnt<<endl;
			flag=1;
		}
		cnt++;
	}
	if(flag!=1)
		cout<<"0"<<endl;
	flag=0;
	
}
int main(){
	int t,i,j,n;
	char a;
	cin>>t;
	while(t--){
		cin>>a>>n;
		switch(a){
			case 'I':{
				int b[n];
				for(i=0;i<n;i++)
					cin>>b[i];
				int key;
				cin>>key;
				search(b,n,key);
				break;
			}
			case 'C':{
				char b[n];
				for(i=0;i<n;i++)
					cin>>b[i];
				char key;
				cin>>key;
				search(b,n,key);
				break;
			}
			case 'S':{
				string b[n];
				for(i=0;i<n;i++)
					cin>>b[i];
				string key;
				cin>>key;
				search(b,n,key);
				break;
			}
			case 'D':{
				double b[n];
				for(i=0;i<n;i++)
					cin>>b[i];
				double key;
				cin>>key;
				search(b,n,key);
				break;
			}
		}
	}
}
