#include <iostream>
using namespace std;


int main(){
    int num;
    for (num=0;num<10000;num++)
        if (num%2==1&&num%3==0&&num%4==1&&num%5==1&&num%6==3&&num%7==0&&num%8==1&&num%9==0){
            cout<<num<<endl;
        }
    getchar();
    return 0;
}