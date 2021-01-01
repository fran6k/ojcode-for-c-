
#include <iostream>
#include <cstring>
using namespace std;
class CVector{
private:
    int *v;
    int c; //测试git用
    int m;
    friend class CMatrix;
public:
    CVector(int _m):m(_m){}
    void input(){
        int i;
        v = new int[m];
        for(i=0;i<m;i++){
            cin>>v[i];
        }
    }

};
class CMatrix{
private:
    int n;
    int **arr;
public:
    CMatrix(int _n):n(_n){}

    void input(){
        int i,j;
        arr=new int*[n];
        for(i=0;i<n;i++)
            arr[i] = new int[n];
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }
    }
    int judge(const CVector &V1){
        if (n==V1.m)return 0;
        else return 1;
    }
    void CVector_Multi(const CVector &V1){
        int i,j;
        int *x = new int[n];
        memset(x,0,n);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                x[i]=x[i]+arr[i][j]*V1.v[j];
            }
        }
        for(i=0;i<n;i++)
            cout<<x[i]<<" ";
        cout<<endl;
    }
};

int main(){
    int m,n,a;
    cin>>a;
    while(a--){
        cin>>n;
        CMatrix m1(n);
        m1.input();
        cin>>m;
        CVector v1(m);
        v1.input();

        if(m1.judge(v1)==0){
            m1.CVector_Multi(v1);
        }
        else cout<<"error"<<endl;
            
    }

    return 0; 
}