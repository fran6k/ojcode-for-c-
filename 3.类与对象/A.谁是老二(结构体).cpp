/*
题目描述

定义一个结构体，包含年月日，表示一个学生的出生日期。然后在一群学生的出生日期中找出谁的出生日期排行第二

要求：出生日期的存储必须使用结构体，不能使用其他类型的数据结构。

要求程序全过程对出生日期的输入、访问、输出都必须使用结构。

输入

第一行输入t表示有t个出生日期

每行输入三个整数，分别表示年、月、日

依次输入t个实例

输出

输出排行第二老的出生日期，按照年-月-日的格式输出

样例输入

6
1980 5 6
1981 8 3
1980 3 19
1980 5 3
1983 9 12
1981 11 23
样例输出

1980-5-3

*/
#include<iostream>
using namespace std;

struct student {
    int year, month, day, days;
};
student students[6];
int main() {
    int n, i;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> students[i].year >> students[i].month >> students[i].day;
        students[i].days = students[i].year * 365 + students[i].month * 30 + students[i].day;
    }
    for (i = 1; i < n; i++)
        for (int j = 0; j <= n - i-i; j++)
            if (students[j].days > students[j + 1].days) {
                student tmp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = tmp;
            }
    cout << students[1].year << "-" << students[1].month << "-" << students[1].day << endl;
    return 0;
}