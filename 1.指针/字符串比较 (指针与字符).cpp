/*
题目描述

编写一个函数比较两个字符串，参数是两个字符指针（要求显式定义，例如char *S, char *T)，比较字符串S和T的大小。如果S大于T，则返回1，如果S小于T则返回-1，如果S与T相等则返回0。

比较规则：

1.把两个字符串的相同位置上的字符进行比较，字符的大小比较以ASCII值为准

2.在比较中，如果字符串S的字符大于字符串T的字符的数量超过小于的数量，则认为S大于T，如果等于则S等于T，如果小于则S小于T

例如S为aaccdd，T为eebbbb，每个位置比较得到S前两个字母都小于T，但后4个字母都大于T，最终认为S大于T

3.如果两个字符串长度不同，则更长的字符串为大

在主函数中输入两个字符串，并调用该函数进行判断，在判断函数中必须使用函数参数的指针进行字符比较

输入

输入t表示有t个测试实例

接着每两行输入两个字符串

依次输入t个实例

输出

每行输出一个实例的比较结果

样例输入

3
aaccdd
eebbbb
AAbb++
aaEE*-
zznnkk
aaaaaaa
样例输出

1
0
-1
*/

#include <iostream>
#include <string>

using namespace std;

int f1(string s1, string s2) {
	int i = 0;
	int size1,size2 = 0;
	size1 = s1.size();
	size2 = s2.size();
	int j=0, k = 0;

	if (size1 > size2)
		return 1;
	else if (size1 < size2)
		return -1;
	else {
		for (i = 0; i < size1; i++) {
			if (s1[i] > s2[i]) {
				j++;
			}
			if (s1[i] < s2[i]) {
				k++;
			}
		}
		if (j > k)
			return 1;
		else if (j < k)
			return -1;
		else
			return 0;
	}


	return 0;
}





int main() {
	int T = 0;
	for (cin >> T; T > 0; T--) {
		string s1;
		string s2;
		cin >> s1;
		cin >> s2;
		
		cout << f1(s1, s2) <<endl;
	}
	return 0;
}