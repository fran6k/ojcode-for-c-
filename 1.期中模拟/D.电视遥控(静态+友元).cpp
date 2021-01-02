/*
题目描述

电视机包含音量、模式、频道号等属性，其中模式分为TV和DVD两种。电视机在TV模式下，将播放相应频道的内容；在DVD模式下，电视机使用统一的频道号播放DVD的内容，频道号统一为99。另外，电视机采用静态成员的方法共享两个数据：播放电视的电视机数量和播放DVD的电视机数量，初始都为0。

电视机操作包括打印、相关静态函数、属性的获取和设置等，根据需要自行编写。

现编写一个遥控器函数，通过友元方法对电视机进行控制，它的参数包括电视机对象、模式、变化音量、频道号，无返回值。函数操作包括：
1、对电视机对象进行模式设置，如果设置为DVD模式，则频道号参数一定是99；如果设置TV模式，则要把频道号设置相应的值。
2、根据变化音量进行调整，例如原有音量为50，现输入变化音量为-30，则50-30=20，音量最终为20。音量值最低为0，最高为100，超过范围则音量不再变化。
3、更新当前播放电视和播放DVD的电视机数量
4、调用电视机对象的打印方法输出电视相关信息
提示：如果电视机原来模式和参数传递的模式是相同的，那么实际操作就是调整音量、切换频道和输出信息。
注意：函数第一个参数必须是一个电视机对象，不可以是整数类型，可以是对象、或对象指针、或对象引用，根据需要自行编写。
用动态数组方法创建n台电视机，从1开始编号，频道号为编号，音量初始为50，模式为TV，然后通过遥控器函数对电视机进行控制。

所有类的数据成员都是私有属性。请使用C++语言和面向对象思想来实现上述要求

输入

第一行输入n，表示有n台电视台

第二行输入t，表示将执行t次遥控操作

接着输入t行，每行依次输入电视机编号i、模式k、频道号x和变化音量，其中i表示第i台电视机，k为1表示TV模式，k为2表示DVD模式。

输出

每行输出执行遥控操作后的电视机信息

最后一行输出当前播放电视和播放DVD的电视机数量。

具体格式看样例

样例输入

10
5
3 1 11 20
4 2 99 -20
5 2 99 80
5 1 55 -60
6 2 99 -70
样例输出

第3号电视机--TV模式--频道11--音量70
第4号电视机--DVD模式--频道99--音量30
第5号电视机--DVD模式--频道99--音量100
第5号电视机--TV模式--频道55--音量40
第6号电视机--DVD模式--频道99--音量0
播放电视的电视机数量为8
播放DVD的电视机数量为2

*/
#include <iostream>

#include <string>
using namespace std;
static int bfs =0;
static int bfd =0;
class tv{
private:
	int k,x,vol;
public:
	tv(){
		k=1;
		x=0;
		vol=50;
	}
	tv(int _k,int _x,int _vol){
		k=_k;
		x=_x;
		vol=_vol;
	}
	friend void ykq(tv t1,int _j,int _k,int _x,int _vol);
	void print(int _j);
	void setk(int xk){k=xk;}
	void setx(int xx){x=xx;}
	void setvol(int xv){vol=vol+xv;}
	void resetvol(int xvv){vol=xvv;}
	int getk(){return k;}
	int getx(){return x;}
	int getvol(){return vol;}	
};

void tv::print(int _j){
	if (k==1)
		cout<<"第"<<_j<<"号电视机--TV模式--频道"<<x<<"--音量"<<vol<<endl;
	else if (k==2)
		cout<<"第"<<_j<<"号电视机--DVD模式--频道99"<<"--音量"<<vol<<endl;
}


void ykq(tv *t1,int _j,int _k,int _x,int _vol){
	t1->setk(_k);
	t1->setx(_x);
	t1->setvol(_vol);
	if ((t1->getvol())>100)
		t1->resetvol(100);
	else if((t1->getvol())<0)
		t1->resetvol(0);
	
	t1->print(_j);
}
	

		
		

int main(){
	int i,n,t,j=0;
	int k,x,vol=0;
	cin>>n;
	tv *p = new tv[n];
	cin>>t;
	for(i=0;i<t;i++){
		cin>>j>>k>>x>>vol;
		ykq(&p[j],j,k,x,vol);
	}
	for(i=0;i<n;i++){
		if(p[i].getk()==2)
			bfd++;
	}
	cout<<"播放电视的电视机数量为"<<n-bfd<<endl;
	cout<<"播放DVD的电视机数量为"<<bfd<<endl;
	delete []p;
	return 0;
}