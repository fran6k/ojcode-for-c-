/*
题目描述

编写一个程序，定义抽象基类Shape，在Shape类中定义虚函数Area()；由它派生出3个派生类：Circle(圆形)、Square(正方形)、Rectangle(矩形)。用虚函数分别计算几种图形面积。
1、要求输出结果保留两位小数。
2、要求用基类指针数组，使它每一个元素指向每一个派生类对象。
输入

测试数据的组数 t

第一组测试数据中圆的半径

第一组测测试数据中正方形的边长

第一组测试数据中矩形的长、宽

.......

第 t 组测试数据中圆的半径

第 t 组测测试数据中正方形的边长

第 t 组测试数据中矩形的长、宽

输出

第一组数据中圆的面积

第一组数据中正方形的面积

第一组数据中矩形的面积

......

第 t 组数据中圆的面积

第 t 组数据中正方形的面积

第 t 组数据中矩形的面积

样例输入

2
1.2
2.3
1.2 2.3
2.1
3.2
1.23 2.12
样例输出

4.52
5.29
2.76
13.85
10.24
2.61

*/
#include <iostream>

#include <iomanip>
using namespace std;

class Shape{
public:

	virtual double Area(){
        return 0;
	}
};
class Circle: public Shape{
private:
	double r;
public:
	Circle();
	Circle(double _r): r(_r) {}
	virtual double Area(){
		return r*r*3.14;
	}
};
class Square: public Shape{
private:
	double a;
public:
	Square(double _a):a(_a){}
	virtual double Area(){
		return a*a;
	}
	
};
class Rectangle: public Shape{
private:
	double a,b;
public:
	Rectangle(double _a, double _b):a(_a),b(_b){}
	virtual double Area(){
		return a*b;
	}
	
};	






int main(){
	int T=0;
	cin>>T;
	double ca,sa,ra,rb;
	while(T--){
		cin>>ca>>sa>>ra>>rb;
		Circle c(ca);
		Square s(sa);
		Rectangle r(ra,rb);
		Shape *p = &c;
		cout<< fixed << setprecision(2)<<p->Area()<<endl;
		p=&s;
		cout<< fixed << setprecision(2)<<p->Area()<<endl;
		p=&r;
		cout<< fixed << setprecision(2)<<p->Area()<<endl;
		
	}
	return 0;
} 