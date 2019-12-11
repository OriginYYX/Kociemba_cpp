#include "int_move.hpp"
int int_cube::int_cube2Combination(const int *A,int num){
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
int int_cube::Combination2int_cube(int hash_ans,int num){
    renturn 0;
}

int int_cube::E_postion2Combination(const int *A){
    int hash_ans=0;
    int pop=1;
    for (int i=0;i<12;i++){// 5 6 7 8
        if (pop<=1000&&A[i]>=5&&A[i]<=8){
            hash_ans+=(i*pop);
            pop*=10;
        }
        else{
            return hash_ans;
        }
    }
}





