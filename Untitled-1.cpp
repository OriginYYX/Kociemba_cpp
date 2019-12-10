#include <iostream>
using namespace std;
int int_cube2Combination(const int *A,int num){
    int pop=1;
    int a=0;
    int hash_ans=0;
    num==8?a=3:a=2;
    for (int i=0;i<num;i++){
        hash_ans+=(A[i]*pop);
        pop*=a;
    }
    return hash_ans;
}
int main(){
    int pop[4]={1,1,1,1};
    cout<<"hash="<<int_cube2Combination(pop,4)<<endl;
    return 0;
}

//b=98 98-11=87
