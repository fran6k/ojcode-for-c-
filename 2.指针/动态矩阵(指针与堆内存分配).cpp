/*
题目描述

未知一个整数矩阵的大小，在程序运行时才会输入矩阵的行数m和列数n

要求使用指针，结合new方法，动态创建一个二维数组，并求出该矩阵的最小值和最大值，可以使用数组下标法。

不能先创建一个超大矩阵，然后只使用矩阵的一部分空间来进行数据访问、

创建的矩阵大小必须和输入的行数m和列数n一样

输入

第一行输入t表示t个测试实例

第二行输入两个数字m和n，表示第一个矩阵的行数和列数

第三行起，连续输入m行，每行n个数字，表示输入第一个矩阵的数值

依次输入t个实例

输出

每行输出一个实例的最小值和最大值

样例输入

2
2 3
33 22 11
66 88 55
3 4
19 38 45 14
22 65 87 31
91 35 52 74
样例输出

11 88
14 91

*/

// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

int main()
{  
    int T = 0;
    for (cin >> T; T > 0; T--) {
        int row, col;
        cin >> row >> col;
        //为行指针分配空间 
        int** arr = new int* [row];
        for (int i = 0; i < row; i++)
            arr[i] = new int[col];//为每行分配空间（每行中有col个元素） 
       //输入二维数组的数 
        int max = 0;
        int min = 100000000;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> arr[i][j];
                if (arr[i][j] > max)
                    max = arr[i][j];
                if (arr[i][j] < min)
                    min = arr[i][j];
                
            }

        }
        
        cout << min << " " << max << endl;
        //释放二维数组（反过来） 
        for (int i = 0; i < row; i++)
            delete[] arr[i];
        delete[] arr;
    }

    return 0;
}
