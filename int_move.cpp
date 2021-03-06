#include "int_move.hpp"
using namespace std;
int cp[8];
int ep[12];
int co[8];
int eo[12];
int int_cube::int_cube_output(){
    cout<<"this is int_cube class:"<<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<20;j++){
            if(i<1){
                if(j<8){
                    cout<<cp[j]<<" ";
                }
                else{
                    cout<<ep[j-8]<<" ";
                }
            }
            else{
                if(j<8){
                    cout<<co[j]<<" ";
                }
                else{
                    cout<<eo[j-8]<<" ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}

int int_cube::set_int_cube(){
    for(int i=0;i<2;i++){
    for(int j=0;j<20;j++){
        if(i==0){
        if(j<8){
            cp[j]=mid_pm[j][i];
        }
        else{
            ep[j-8]=mid_pm[j][i];
        }
        }
        else{
        if(j<8){
            co[j]=mid_pm[j][i];
        }
        else{
            eo[j-8]=mid_pm[j][i];
        }
        } 
        }
    }
    return 0;
}
    


int int_cube::int_cube_move(int move,int count){
    //count=1 clock count=2 r clock=3 anti-clock
    move-=1;
    static const int co_rotate_map[6][4] = {
        {0,1,3,2},
        {6,7,5,4},
        {4,5,1,0},
        {7,6,2,3},
        {6,4,0,2},
        {5,7,3,1}
    };
    static const int ed_rotate_map[6][4] = {
        {0,1,2,3},
        {10,9,8,11},
        {8,5,0,4},
        {10,7,2,6},
        {11,4,3,7},
        {9,6,1,5}
    };

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

    static const auto swap2 = [](int &a, int &b) {
		int t = a;
		a = b;
		b = t;
	};

    if (count==2){
        const int *C = co_rotate_map[move];
        swap2(cp[C[0]],cp[C[2]]);
        swap2(cp[C[1]],cp[C[3]]);
        swap2(co[C[0]],co[C[2]]);
        swap2(co[C[1]],co[C[3]]);

        const int *E = ed_rotate_map[move];
        swap2(ep[E[0]],ep[E[2]]);
        swap2(ep[E[1]],ep[E[3]]);
        swap2(eo[E[0]],eo[E[2]]);
        swap2(eo[E[1]],eo[E[3]]);
        return 0;
    }
    else{
        const int *C = co_rotate_map[move];
        const int *E = ed_rotate_map[move];
        if(count==0){
            swap(cp,C);swap(co,C);
            swap(ep,E);swap(eo,E);
            if (move>=2){
                if (--co[C[2]]==-1) co[C[2]]=2;
                if (--co[C[0]]==-1) co[C[0]]=2;
                if (++co[C[1]]== 3) co[C[1]]=0;
                if (++co[C[3]]== 3) co[C[3]]=0;
            }
            if (move>=4){
                eo[E[0]] ^= 1;
			    eo[E[1]] ^= 1;
			    eo[E[2]] ^= 1;
			    eo[E[3]] ^= 1;
            }
            return 0;
        }
        else{
            swap_reverse(cp,C);swap_reverse(co,C);
            swap_reverse(ep,E);swap_reverse(eo,E);
            if (move>=2){
                if (--co[C[2]]==-1) co[C[2]]=2;
                if (--co[C[0]]==-1) co[C[0]]=2;
                if (++co[C[1]]== 3) co[C[1]]=0;
                if (++co[C[3]]== 3) co[C[3]]=0;
            }
            if (move>=4){
                eo[E[0]] ^= 1;
			    eo[E[1]] ^= 1;
			    eo[E[2]] ^= 1;
			    eo[E[3]] ^= 1;
            }
            return 0;
        }
    }
}
