/*
题目描述

完成下列分数类的实现:

class CFraction
{
private:
     int fz, fm;
public:
     CFraction(int fz_val, int fm_val) ;
     CFraction add(const CFraction &r);
     CFraction sub(const CFraction &r);
     CFraction mul(const CFraction &r);
     CFraction div(const CFraction &r);
     int getGCD();   // 求对象的分子和分母的最大公约数
     void print();
};

求两数a、b的最大公约数可采用辗转相除法，又称欧几里得算法，其步骤为:

1. 交换a, b使a > b;
2. 用a除b得到余数r,若r=0,则b为最大公约数,退出.
3. 若r不为0,则用b代替a, r代替b,此时a,b都比上一次的小,问题规模缩小了;
4. 继续第2步。

输入

测试数据的组数 t

第一组第一个分数

第一组第二个分数

第二组第一个分数

第二组第二个分数

......

输出

第一组两个分数的和

第一组两个分数的差

第一组两个分数的积

第一组两个分数的商

第二组两个分数的和

第二组两个分数的差

第二组两个分数的积

第二组两个分数的商

......

样例输入

3
1/2
2/3
3/4
5/8
21/23
8/13
样例输出

7/6
-1/6
1/3
3/4

11/8
1/8
15/32
6/5

457/299
89/299
168/299
273/184

*/
#include <iostream>

using namespace std;

class CFraction {
private:
 int fz, fm;
public:
 CFraction() {
 };
 CFraction(int fz_val, int fm_val) {
  fz = fz_val;
  fm = fm_val;
 }
 CFraction add(const CFraction& r) {
  CFraction a;
  int i;
  a.fz = fz * r.fm + r.fz * fm;
  a.fm = fm * r.fm;
  i = a.getGCD();
  a.fz = a.fz / i;
  a.fm = a.fm / i;
  return a;
 }
 CFraction sub(const CFraction& r) {
  CFraction a;
  int i;
  a.fz = fz * r.fm - r.fz * fm;
  a.fm = fm * r.fm;
  i = a.getGCD();
  a.fz = a.fz / i;
  a.fm = a.fm / i;
  return a;
 }
 CFraction mul(const CFraction& r) {
  CFraction a;
  int i;
  a.fz = fz * r.fz;
  a.fm = fm * r.fm;
  i = a.getGCD();
  a.fz = a.fz / i;
  a.fm = a.fm / i;
  return a;
 }
 CFraction div(const CFraction& r) {
  CFraction a;
  int i;
  a.fz = fz * r.fm;
  a.fm = fm * r.fz;
  i = a.getGCD();
  a.fz = a.fz / i;
  a.fm = a.fm / i;
  return a;
 }
 int getGCD() {
  int temp;
  int r = 0,a, b;
  a = fz; b = fm;
  if (a < 0)
   a = -a;
  if (b < 0)
   b = -b;
  if (b > a) {
   temp = a; a = b; b = temp;
  }
  for (;;) {
   r = a % b;
   if (r == 0)return b;
   a = b;
   b = r;
   }
 }
 void print() {
  cout << fz << "/" << fm << endl;
 }
};

int main()
{
 int fz, fm, t;
 cin >> t;
 CFraction ccc;
 while (t--)
 {
  cin >> fz;
  cin.get();
  cin >> fm;
  CFraction aaa(fz, fm);
  cin >> fz;
  cin.get();
  cin >> fm;
  CFraction bbb(fz, fm);
  ccc = aaa.add(bbb);
  ccc.print();
  ccc = aaa.sub(bbb);
  ccc.print();
  ccc = aaa.mul(bbb);
  ccc.print();
  ccc = aaa.div(bbb);
  ccc.print();
  cout << endl;
 }
 return 0;
}