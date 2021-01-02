/*
题目描述

如下所示为类对象构造和析构过程中产生的输出,试完成类的定义和主函数的编写.

输入

测试数据的组数t

第一组对象个数n1

第二组对象个数n2

.......

输出

Constructing object 1
Constructing object 2

......
Constructing object n1
Destructing object n1

......
Destructing object 2
Destructing object 1

Constructing object 1
Constructing object 2

......
Constructing object n2
Destructing object n2

......
Destructing object 2
Destructing object 1

......

样例输入

2
3
4
样例输出

Constructing object 1
Constructing object 2
Constructing object 3
Destructing object 3
Destructing object 2
Destructing object 1
Constructing object 1
Constructing object 2
Constructing object 3
Constructing object 4
Destructing object 4
Destructing object 3
Destructing object 2
Destructing object 1

*/
#include <iostream>

using namespace std;


class fc{
private:
	static int shu;
public:
	fc(){
		shu++;
		cout << "Constructing object "<<shu<<endl;
	};
	~fc(){
		
	   	cout <<"Destructing object " <<shu<<endl;
	   	shu--;
   };
};

int fc::shu =0;

int main(){
	
	int i,m,n;
	fc *pc;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>m;
		pc=new fc[m];
		delete[] pc;
	}
	return 0;
}