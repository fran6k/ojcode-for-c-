/*
题目描述

已知一群学生的考试试卷，要求对试卷内容进行对比，查找是否有抄袭。

每张试卷包含：学号（整数类型）、题目1答案（字符串类型）、题目2答案（字符串类型）、题目3答案（字符串类型）

要求：使用结构体来存储试卷的信息。定义一个函数，返回值为一个整数，参数是两个结构体指针，函数操作是比较两张试卷的每道题目的答案，如果相同题号的答案相似度超过90%，那么就认为有抄袭，函数返回抄袭题号，否则返回0。相似度是指在同一题目中，两个答案的逐个位置上的字符两两比较，相同的数量大于等于任一个答案的长度的90%，就认为抄袭。

输入

第一行输入t表示有t张试卷

第二行输入第1张试卷的学生学号

第三行输入第1张试卷的题目1答案

第四行输入第1张试卷的题目2答案

第五行输入第1张试卷的题目3答案

每张试卷对应4行输入

依次输入t张试卷的数据

输出

在一行中，把发现抄袭的两个学号和题目号，数据之间用单个空格隔开

如果发现是题目1抄袭，题目号为1，以此类推

输出顺序按照输入的学号顺序进行输出

样例输入

5
2088150555
aabcdef11
ZZ887766dd
cc33447799ZZ
2088150333
abcdef00
AABBCCDDEE
ZZ668899cc
2088150111
AABBCCDDEE
ZZ668899cc
abcdef00
2088150222
AABBCFDDeE
ZZ889966dd
abcdef000
2088150444
aabcdef00
AABBCDDDEE
cc668899ZZ
样例输出

2088150333 2088150444 2
2088150111 2088150222 3

*/
#include <iostream>
#include <string.h>
using namespace std;

struct Student{
    int no;
    char *ans[3];
};
int pos_ceil(double x){
    if(x-int(x)<0.1)
        return int(x);
    else
        return int(x+1);
}
int strcmp(char *x,char *y){
    int lenX=strlen(x);
    int lenY=strlen(y);
    int len=lenX<lenY?lenX:lenY;
    int counter=0;
    for(int i=0;i<len;i++){
        if(*(x+i)==*(y+i))
            counter++;
    }
    if(counter>=pos_ceil(len*0.9))
        return 1;
    else
        return 0;
}
int main(){
	int t=0;
	cin>>t;
	int i,j,k=0;
	Student stu[t];
	for(int i=0;i<t;i++){
    	//记得delete
    	for(int j=0;j<3;j++)
        	stu[i].ans[j] = new char[20];
    cin>>stu[i].no>>stu[i].ans[0]>>stu[i].ans[1]>>stu[i].ans[2];
	}
	for(int i=0;i<t-1;i++){
    	for(int j=i+1;j<t;j++){
        	for(int k=0;k<3;k++){
            	if(strcmp(stu[i].ans[k],stu[j].ans[k]))
                	cout<<stu[i].no<<' '<<stu[j].no<<' '<<k+1<<endl;
	        }
    	}
	}
	for(int i=0;i<t;i++){
    	for(int j=0;j<3;j++)
        	delete stu[i].ans[j];
	}
} 
 