/*
题目描述

定义一个电话号码类CTelNumber,包含1个字符指针数据成员,以及构造、析构、打印及拷贝构造函数。

字符指针是用于动态创建一个字符数组，然后保存外来输入的电话号码

构造函数的功能是为对象设置键盘输入的7位电话号码，

拷贝构造函数的功能是用原来7位号码的对象升位为8位号码对象,也就是说拷贝构造的对象是源对象的升级.电话升位的规则是原2、3、4开头的电话号码前面加8，原5、6、7、8开头的前面加2。

注意:电话号码只能全部是数字字符，且与上述情况不符的输入均为非法)

输入

测试数据的组数 t

第一个7位号码

第二个7位号码

......

输出

第一个号码升位后的号码

第二个号码升位后的号码

......

如果号码升级不成功，则输出报错信息，具体看示例

样例输入

3
6545889
3335656
565655
样例输出

26545889
83335656
Illegal phone number

*/
#include<iostream>
#include <cstring>
using namespace std;
class CTelNumber{
 private:
  char *p;
 public:
  CTelNumber(){
   p=new char[8];
  }
  CTelNumber(char *q){
   p=new char[8];
   strcpy(p,q);
  }
  CTelNumber(CTelNumber &q){//拷贝构造函数同时满足了题目要求的升位运算
   p=new char[9];
   if(q.p[0]=='2'||q.p[0]=='3'||q.p[0]=='4'){
    p[0]='8';
   }else
    p[0]='2';
   for(int i=0;i<7;i++){
    p[i+1]=q.p[i];
   }
  }
  void print(){
   for(int i=0;i<8;i++)
   cout<<p[i];
   cout<<endl;
  }
  ~CTelNumber(){//析构函数
   delete p;
  }
};
int main(){
 int t,i,is;
 cin>>t;
 char *q;
 while(t--){
  is=1;
  q=new char[8];
  cin>>q;
  for(i=1;i<7;i++){
   if(q[i]>'9'||q[i]<'0'){
    is=0;//判断输入是否符合要求
    break;
   }
  }
  if(is){
   if(strlen(q)==7){
   if(q[0]>='2'&&q[0]<='8'){
    CTelNumber m(q);
    CTelNumber n(m);
    n.print();
   }
   else
   cout<<"Illegal phone number"<<endl;
   } 
  }
  else
   cout<<"Illegal phone number"<<endl; 
 } 
}