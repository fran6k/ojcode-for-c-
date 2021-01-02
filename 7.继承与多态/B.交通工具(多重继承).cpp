/*
题目描述

1、建立如下的类继承结构：

1)一个车类CVehicle作为基类，具有max_speed、speed、weight等数据成员，display()等成员函数

2)从CVehicle类派生出自行车类CBicycle，添加属性：高度height

3)从CVehicle类派生出汽车类CMotocar，添加属性：座位数seat_num

4)从CBicycle和CMotocar派生出摩托车类CMotocycle

2、分别定义以上类的构造函数、输出函数display及其他函数（如需要）。

3、在主函数中定义各种类的对象，并测试之，通过对象调用display函数产生输出。

输入

第一行：最高速度 速度 重量 第二行：高度 第三行：座位数

输出

第一行：Vehicle: 第二行及以后各行：格式见Sample

样例输入

100 60 20
28
2
样例输出

Vehicle:
max_speed:100
speed:60
weight:20

Bicycle:
max_speed:100
speed:60
weight:20
height:28

Motocar:
max_speed:100
speed:60
weight:20
seat_num:2

Motocycle:
max_speed:100
speed:60
weight:20
height:28
seat_num:2

*/
#include <iostream>
using namespace std;
class CVehicle{
protected:
	int max_speed,speed,weight;
public:
	CVehicle(){
	}
	void set1(int x,int y,int z){
		max_speed = x;
		speed = y;
		weight = z;
	}
	void display(){
		cout<<"max_speed:"<<max_speed<<endl;
		cout<<"speed:"<<speed<<endl;
		cout<<"weight:"<<weight<<endl;
	}
};

class CBicycle:public CVehicle{
protected:
	int height;
public:
	void set2(int j){
		height = j;
	}
	void displayheight(){
		cout<<"height:"<<height<<endl;
	}
};

class CMotocar:public CVehicle{
protected:
	int seat_num;
public:
	void set3(int k){
		seat_num=k;
	}
	void displayseat(){
		cout<<"seat_num:"<<seat_num<<endl;
	}
};

class CMotocyle:public CBicycle,public CMotocar{

};



int main(){
	int x,y,z,j,k;
	CVehicle c1;
	cin>>x>>y>>z;
	cin>>j;
	cin>>k;
	c1.set1(x,y,z);
	cout<<"Vehicle:"<<endl;
	c1.display();
	CBicycle c2;
	cout<<endl; 
	c2.set2(j);
	cout<<"Bicycle:"<<endl;
	c1.display();
	c2.displayheight();
	cout<<endl; 
	CMotocar c3;
	c3.set3(k);
	cout<<"Motocar:"<<endl;
	c1.display();
	c3.displayseat();
	cout<<endl; 	
	CMotocyle c4;
	cout<<"Motocycle:"<<endl;
	c1.display();
	c2.displayheight();
	c3.displayseat();
	return 0;
}