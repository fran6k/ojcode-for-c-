/*
题目描述

编写一个复数类，能实现加、减运算，能输出复数的信息。 要求至少包含以下方法：

1、缺省（无参）构造函数，设置实部与虚部为1；

2、有参构造函数，给实部与虚部赋值；

3、加法运算，计算两个复数的和；

4、减法运算，计算两个复数的差；

5、输出方法，输出当前复数的值

输入

测试数据的组数t 第一组的两个复数的实部 虚部 实部 虚部 第二组的两个复数的实部 虚部 实部 虚部 ......

输出

第一组两个复数的和 第一组两个复数的差

样例输入

4
2 1 2 1
2 1 2 -1
3 1 2 -6
3 3 2 2
样例输出

sum:4+2i
remainder:0
sum:4
remainder:2i
sum:5-5i
remainder:1+7i
sum:5+5i
remainder:1+i

*/
#include <iostream>

using namespace std;


class Complex{
private:
	int a1,a2,b1,b2;
public:
	Complex(int a,int b,int c,int d){
		a1=a;a2=b;b1=c;b2=d;
	}
	void plus();
	void remainder();
};

void Complex::plus(){
	int m = a1+b1;
	int n = a2+b2;
	if (n==1){
		if (m>0&&n>0)
			cout<<"sum:"<<m<<"+"<<"i"<<endl;
		if (m>0&&n<0)
			cout<<"sum:"<<m<<"i"<<endl;
		if (m<0&&n>0)
			cout<<"sum:"<<m<<"+"<<"i"<<endl;
		if (m<0&&n<0)
			cout<<"sum:"<<m<<"i"<<endl;
		if (m==0&&n!=0)
			cout<<"sum:"<<"i"<<endl;
		if (m!=0&&n==0)
			cout<<"sum:"<<m<<endl;
		if (m==0&&n==0)
			cout<<"sum:"<<"0"<<endl;		
	}
	else{
		if (m>0&&n>0)
			cout<<"sum:"<<m<<"+"<<n<<"i"<<endl;
		if (m>0&&n<0)
			cout<<"sum:"<<m<<n<<"i"<<endl;
		if (m<0&&n>0)
			cout<<"sum:"<<m<<"+"<<n<<"i"<<endl;
		if (m<0&&n<0)
			cout<<"sum:"<<m<<n<<"i"<<endl;
		if (m==0&&n!=0)
			cout<<"sum:"<<n<<"i"<<endl;
		if (m!=0&&n==0)
			cout<<"sum:"<<m<<endl;
		if (m==0&&n==0)
			cout<<"sum:"<<"0"<<endl;
	}
}
void Complex::remainder(){
	int m = a1-b1;
	int n = a2-b2;
	if (n==1){
		if (m>0&&n>0)
			cout<<"remainder:"<<m<<"+"<<"i"<<endl;
		if (m>0&&n<0)
			cout<<"remainder:"<<m<<"i"<<endl;
		if (m<0&&n>0)
			cout<<"remainder:"<<m<<"+"<<"i"<<endl;
		if (m<0&&n<0)
			cout<<"remainder:"<<m<<"i"<<endl;
		if (m==0&&n!=0)
			cout<<"remainder:"<<"i"<<endl;
		if (m!=0&&n==0)
			cout<<"remainder:"<<m<<endl;
		if (m==0&&n==0)
			cout<<"remainder:"<<"0"<<endl;		
	}
	else{
		if (m>0&&n>0)
			cout<<"remainder:"<<m<<"+"<<n<<"i"<<endl;
		if (m>0&&n<0)
			cout<<"remainder:"<<m<<n<<"i"<<endl;
		if (m<0&&n>0)
			cout<<"remainder:"<<m<<"+"<<n<<"i"<<endl;
		if (m<0&&n<0)
			cout<<"remainder:"<<m<<n<<"i"<<endl;
		if (m==0&&n!=0)
			cout<<"remainder:"<<n<<"i"<<endl;
		if (m!=0&&n==0)
			cout<<"remainder:"<<m<<endl;
		if (m==0&&n==0)
			cout<<"remainder:"<<"0"<<endl;
	}


}

int main(){
	
	int i,m,n;
	cin>>n;
	int a,b,c,d=0;
	for(i=1;i<=n;i++){
		cin>>a>>b>>c>>d;
		Complex c1(a,b,c,d);
		c1.plus();
		c1.remainder(); 
	}
	return 0;
}