/*
复数类的声明如下：



要求如下：

1.     实现复数类和友元函数addCom和outCom。

2.   参考addCom函数为复数类增加一个友元函数minusCom，用于实现两个复数的减法

3.     在main函数中，通过友元函数，实现复数的加减法和复数的输出。

输入

第1行：第1个复数的实部和虚部

第2行：需进行运算的次数，注意：是连续运算。具体结果可参考样例

  第3行开始，每行输入运算类型，以及参与运算的复数的实部与虚部。“+”表示复数相加，“-”表示复数相减。

输出

 每行输出复数运算后的结果，复数输出格式为“(实部,虚部)”。

样例输入

10 10
3
+ 20 10
- 15 5
+ 5 25
样例输出

(30,20)
(15,15)
(20,40)

*/
#include <iostream>
using namespace std;
 
class complex{
private:
     double real;
     double imag;
public:
    complex();
    complex(double r, double i);
    friend complex addCom(complex c1, complex c2);
    friend complex minusCom(complex c1, complex c2);
    friend void outCom(complex c);
};
 
complex::complex() {}
 
complex::complex(double r, double i) {
    real = r;
    imag = i;
}
 
complex addCom(complex c1, complex c2) {
    c1.real = c1.real + c2.real;
    c1.imag = c1.imag + c2.imag;
    return c1;
}
 
complex minusCom(complex c1, complex c2) {
    c1.real = c1.real - c2.real;
    c1.imag = c1.imag - c2.imag;
    return c1;
}
 
void outCom(complex c) {
    cout << "(" << c.real << "," << c.imag << ")" << endl;
}
 
int main() {
    double real, imag;
    cin >> real >> imag;
    complex a(real, imag);
    int t;
    cin >> t;
    while(t--){
        char s;
        cin >> s;
        if(s == '-') {
            cin >> real >> imag;
            complex b(real, imag);
            a = minusCom(a, b);
            outCom(a);
        }
        else if(s == '+'){
            cin >> real >> imag;
            complex b(real, imag);
            a = addCom(a, b);
            outCom(a);
        }
    }
    return 0;
}