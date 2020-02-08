#include <iostream>
#include <string>
using namespace std;

class arr{
public:
    arr(int a,int b,int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
    void xianshi(){
        cout<<a<<" "<<b<<" "<<c<<endl;
    }
    int a;
    int b;
    int c;
};

arr ini(arr fuck){
    return fuck;
}

int main(){
    arr fuck(3,6,9);
    fuck.xianshi();
    arr fuck1 = ini(fuck);
    fuck1.xianshi();
    string y = " 1A2B3C";
    cout<<y.size()<<endl;
    char a = 'a';
    cout<< <<endl;
    getchar();
    return 0;
}