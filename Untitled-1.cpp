#include <iostream>
using namespace std;
int char2int(char num){
    if(num<='9'){
        return num-48;
    }
    else{
        return (int)num - 87;
    }
}
int main(){
    char pop[10];
    cin>>pop;
    cout<<pop<<endl;
    cout<<char2int(pop[1])<<endl;
    return 0;
}

//b=98 98-11=87