#include "int_move.hpp"
int int_cube2Combination(const int *A,int num){
    int pop=1;
    int a=0;
    int hash_ans=0;
    num==8?a=3:a=2;
    for (int i=0;i<num;i++){
        hash_ans+=(A[i]*pop);
        pop*=2;
    }
    return hash_ans;
}
int Combination2int_cube(int hash_ans,int num){
    renturn 0;
}



