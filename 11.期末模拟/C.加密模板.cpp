#include <iostream>
using namespace std;

template <class T>
class change{
    T ptxt[100];
    T ctxt[100];
    T key;
    int len;
public:
    change(T tk,T tt[],int tl):key(tk),len(tl){
        for(int i=0;i<tl;i++){
            ptxt[i]=tt[i];
        }
    }
    void print(){
        for(int i=0;i<len;i++){
            cout<<ctxt[i]<<" ";
        }
        cout<<endl;
    }
    void encrypt(){
        T max = 0;
        int i;
        for(i=0;i<len;i++){
            if(ptxt[i]>max)max=ptxt[i];
        }
        for(i=0;i<len;i++){
            ctxt[i]=max-ptxt[i]+key;
        }
    }
};
int main(){
    int i;
    int length;
    int ik,itxt[100];
    double dk,dtxt[100];
    char ck,ctxt[100];
    cin>>ik>>length;
    for(i=0;i<length;i++){
        cin>>itxt[i];
    }
    change<int> ic(ik,itxt,length);
    ic.encrypt();
    ic.print();

    cin>>dk>>length;
    for(i=0;i<length;i++){
        cin>>dtxt[i];
    }  
    change<double> dc(dk,dtxt,length);
    dc.encrypt();
    dc.print();
    
    cin>>ck>>length;
    for(i=0;i<length;i++){
        cin>>ctxt[i];
    }  
    change<char> cc(ck,ctxt,length);
    cc.encrypt();
    cc.print();
    return 0;
}