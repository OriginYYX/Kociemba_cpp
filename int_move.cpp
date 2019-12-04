#include "int_move.hpp"
using namespace std;
int char2int(char num){
    if(num<='9'){
        return num-48;
    }
    else{
        return (int)num - 87;
    }
}
int int_swap(char now_pos1,char now_pos2,char now_pos3,char now_pos4,char tar_pos1,char tar_pos2,char tar_pos3,char tar_pos4){
    int temp=0;
    for (int i=0;i<4;i++){

    }
}
int int_cube::int_cube_output(){
    for(int i=0;i<2;i++){
    for(int j=0;j<20;j++){
        cout<<int_cube[j][i]<<" ";
    }
    cout<<endl;
}
    return 0;
}
int int_cube::set_int_cube(){
    cout<<"this is int_cube class:"<<endl;
    for(int i=0;i<2;i++){
    for(int j=0;j<20;j++){
        int_cube[j][i]=mid_pm[j][i];
    }
}
return 0;
}

int int_cube::int_cube_move(int move,int count){
    static const int co_rotate_map[6][4] = {
        
        {0,1,3,2},// TOP [clock] [anti-clock] 2 3 1 0
        {7,8,6,5},// DOWN
        {7,5,1,3},// LEFT
        {6,8,4,2},// RIGHT
        {5,6,2,1},// FRONT
        {8,7,3,4},// BACK
    };
    
    static const int ed_rotate_map[6][4] = {
        {}
    };

    static const int co_toward_map
    static const auto swap = [](int *A, const int *C) {
		int temp = A[C[0]];
		A[C[0]]=A[C[1]];
		A[C[1]]=A[C[2]];
		A[C[2]]=A[C[3]];
		A[C[3]]=temp;
	};
    static const auto swap_reverse = [](int *A, const int *C){
        int temp = A[C[3]];
        A[C[3]]=A[C[2]];
        A[C[2]]=A[C[1]];
        A[C[1]]=A[C[0]];
        A[C[0]] = temp;
    };

}
