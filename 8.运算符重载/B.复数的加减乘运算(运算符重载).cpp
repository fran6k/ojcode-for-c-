/*
题目描述

定义一个复数类，通过重载运算符：+、-、*，实现两个复数之间的各种运算。



要求如下：
1.实现Complex类；
2.编写main函数，初始化两个Complex对象，计算它们之间的加减乘，并输出结果。
复数相乘的运算规则
设z1=a+bi，z2=c+di(a、b、c、d∈R)是任意两个复数，那么它们的积(a+bi)(c+di)=(ac-bd)+(bc+ad)i.
输入

第1行：输入两个数值，分别为第一个Complex对象的实部和虚部。
第2行：输入两个数值，分别为第二个Complex对象的实部和虚部。
输出

第1行：两个Complex对象相加后的输出结果。
第2行：两个Complex对象相减后的输出结果。
第3行：两个Complex对象相乘后的输出结果。
样例输入

10 20
50 40
样例输出

Real=60 Image=60
Real=-40 Image=-20
Real=-300 Image=1400

*/
#include <iostream>
using namespace std;
class Complex{
	float Real,Image;
public:
	Complex(float x=0,float y=0){
		Real=x;Image=y;
	}
	friend Complex operator + (Complex &c1,Complex &c2);
	friend Complex operator - (Complex &c1,Complex &c2); 
	friend Complex operator * (Complex &c1,Complex &c2); 
	void show(){
		cout<<"Real="<<Real<<" "<<"Image="<<Image<<endl;
	}
	void set(float a,float b){
		Real=a;
		Image=b;
	}
};

Complex operator + (Complex &c1,Complex &c2){
	Complex a;
	a.Real=c1.Real+c2.Real;
	a.Image=c1.Image+c2.Image;
	return a;
}

Complex operator - (Complex &c1,Complex &c2){
	Complex a;
	a.Real=c1.Real-c2.Real;
	a.Image=c1.Image-c2.Image;
	return a;
}
Complex operator * (Complex &c1,Complex &c2){
	Complex a;
	a.Real=c1.Real*c2.Real-c1.Image*c2.Image;
	a.Image=c1.Image*c2.Real+c1.Real*c2.Image;
	return a;
}


int main(){
	float a,b;
	Complex c1;
	cin>>a>>b;
	c1.set(a,b);
	Complex c2;
	cin>>a>>b;
	c2.set(a,b);
	Complex rlt;
	rlt=c1+c2;
	rlt.show();
	rlt=c1-c2;
	rlt.show();
	rlt=c1*c2;
	rlt.show();
	
	
	return 0;
}