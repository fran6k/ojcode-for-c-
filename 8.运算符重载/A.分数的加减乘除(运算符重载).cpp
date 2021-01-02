/*
题目描述

Fraction类的基本形式如下：



要求如下：
1.实现Fraction类；common_divisor()和contracted()函数体可为空，不实现具体功能。
2.编写main函数，初始化两个Fraction对象的，计算它们之间的加减乘除。
输入

第1行：依次输入第1个和第2个Fraction对象的分子和分母值。

输出

每行依次分别输出加减乘除计算后的Fraction对象（直接输出分数值，不需要约简）。

样例输入

1 3 2 5
样例输出

fraction=11/15
fraction=-1/15
fraction=2/15
fraction=5/6
*/
#include <iostream>
using namespace std;

class Fraction{
int numerator,denominator;
int common_divisor();
void contracted();
public:
	Fraction(int a=1,int b=2):numerator(a),denominator(b){};
	Fraction(Fraction& f){
		numerator=f.numerator;
		denominator=f.denominator;
	}
	Fraction operator+(Fraction &f){
		Fraction a;
		a.numerator=numerator*f.denominator+f.numerator*denominator;
		a.denominator=denominator*f.denominator;
		return a;
	}
	Fraction operator-(Fraction &f){
		Fraction a; 
		a.numerator=numerator*f.denominator-f.numerator*denominator;
		a.denominator=denominator*f.denominator;
		return a;
		

	}
	Fraction operator*(Fraction &f){
		Fraction a; 
		a.numerator=numerator*f.numerator;
		a.denominator=denominator*f.denominator;
		return a;
		
	}
	Fraction operator/(Fraction &f){
		Fraction a; 
		a.numerator=numerator*f.denominator;
		a.denominator=denominator*f.numerator;
		return a;
	}
	void Set(int a,int b){
		numerator=a;
		denominator=b;
	}
	void disp(){
		cout<<"fraction="<<numerator<<"/"<<denominator<<endl;
	}
};



int main(){
	int a,b;
	cin>>a>>b;
	Fraction f1(a,b);
	cin>>a>>b;
	Fraction f2(a,b);
	Fraction f3;
	f3=f1+f2;
	f3.disp();
	f3=f1-f2;
	f3.disp();
	f3=f1*f2;
	f3.disp();
	f3=f1/f2;
	f3.disp();
}