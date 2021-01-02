/*
题目描述

已知一个矩阵包含行数m、列数n、数值data三个属性，包含初始化、输出、相加等操作，要求

1、在类定义中，矩阵的data属性是一个整数指针型指针。只有创建对象时，根据外来输入的行数和列数，才把指针变成一个二维数组

2、用运算符重载的方法实现两个矩阵对象的相加，矩阵相加是指两个矩阵的每个位置上的两个元素相加

3、用构造函数实现对象的初始化，用输出函数实现矩阵的输出。提示：在构造函数内做输入可以减少很多麻烦

4、在析构函数里面释放所分配的资源

整数指针变成二位数组的参考代码

//m和n是行数和列数
int m, n;
int **data;
int i, j;
cin>>m>>n;
data=new int*[m];  //先创建m行
for(i=0;i<m;i++) 
  { data[i]=new int[n]; }  //再创建n列

for (i=0; i<m; i++)
  for (j=0; j<n; j++)
    cin>>data[i][j];

输入

第一行输入t表示t个实例

第二行输入第一个示例的矩阵的行数和列数，两个矩阵的行数和列数都是相同的

第三行起，输入第一个矩阵的具体数据

依次类推，输入第二个矩阵的具体数据

依次类推，输入下一个示例的数据

输出

输出每两个矩阵相加的结果

样例输入

2
2 3
1 2 3 
4 5 6
-1 -2 -3
6 5 4
2 2
11 22
33 44
55 66
77 88
样例输出

0 0 0 
10 10 10 
66 88 
110 132 

*/
#include <iostream>
using namespace std;
class matrix{
	int m,n;
	int **data;
	
public:
	matrix(int _m,int _n):m(_m),n(_n){}
	void setdate(){
		int i,j;
		data=new int*[m];  //先创建m行
		for(i=0;i<m;i++) 
		{ data[i]=new int[n]; }  //再创建n列
		for (i=0; i<m; i++){
			for (j=0; j<n; j++)
				cin>>data[i][j];		
		}
	}
	friend matrix operator + (matrix &m1,matrix &m2);
	void print(){
		int i,j;
		for (i=0; i<m; i++){
			for (j=0; j<n; j++)
				cout<<data[i][j]<<" ";	
			cout<<endl;	
		}		
	}
};

matrix operator + (matrix &m1,matrix &m2){
	matrix m3(m1.m,m1.n);
	int i,j;
	int m=m1.m;
	int n=m1.n;
	m3.data=new int*[m];  //先创建m行
	for(i=0;i<m;i++){ 
	m3.data[i]=new int[n]; 
	}  //再创建n列
	for (i=0; i<m; i++){
		for (j=0; j<n; j++)
			m3.data[i][j]=m1.data[i][j]+m2.data[i][j];			
	}
	return m3;
}

int main(){
	int m, n;
	int i, j;
	int T=0;
	cin>>T;
	while(T--){
		cin>>m>>n;
		matrix m1(m,n);
		m1.setdate();
		matrix m2(m,n);
		m2.setdate();
		matrix rlt(m,n);
		rlt=m1+m2;
		rlt.print();
	}
	return 0;	
}