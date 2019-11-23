#include<iostream>
#include"cube.hpp"
#define face2corner(a,b,c) 36*a+6*b+c
#define face2edge(a,b) a*6+b
int pop[258][2];
int F =1,R=2,B=3,L=4,U=5,D=6;

const int let2int [20][3]={{46,32,0},{48,10,2},{40,30,22},{42,12,20},{50,38,6},{52,16,8},{56,30,28},{58,18,26},
                           {47,1,0},{45,11,0},{41,21,0},{43,31,0},
                           {35,3,0},{13,5,0},{33,25,0},{15,23,0},
                           {51,07,0},{55,17,0},{57,27,0},{53,37,0}};
using namespace std;



int cube::input(){
    cout<<"������ħ��״̬:"<<endl;
    for(int i=0;i<6;i++){
        for(int j=0;j<9;j++){
            cin>>cubelet[i][j];
        }
    }
    return 0;
}

int cube::output(){
    for(int i=0;i<6;i++){
        for(int j=0;j<9;j++){
            cout<<cubelet[i][j];
        }
        cout<<endl;
    }
    return 0;
}

int cube::int_cube_input(){
pop[face2corner(U,L,F)][1]=0; pop[face2corner(U,L,F)][0]=1; pop[face2edge(U,F)][1]=0; pop[face2edge(U,F)][0]=1;
pop[face2corner(F,U,L)][1]=1; pop[face2corner(F,U,L)][0]=1; pop[face2edge(F,U)][1]=1; pop[face2edge(F,U)][0]=1;
pop[face2corner(L,F,U)][1]=2; pop[face2corner(L,F,U)][0]=1; pop[face2edge(U,R)][1]=0; pop[face2edge(U,R)][0]=2;

pop[face2corner(U,R,F)][1]=0; pop[face2corner(U,R,F)][0]=2; pop[face2edge(R,U)][1]=1; pop[face2edge(R,U)][0]=2;
pop[face2corner(F,U,R)][1]=1; pop[face2corner(F,U,R)][0]=2; pop[face2edge(U,B)][1]=0; pop[face2edge(U,B)][0]=3;
pop[face2corner(R,F,U)][1]=2; pop[face2corner(R,F,U)][0]=2; pop[face2edge(B,U)][1]=1; pop[face2edge(B,U)][0]=3;

pop[face2corner(U,L,B)][1]=0; pop[face2corner(U,L,B)][0]=3; pop[face2edge(U,L)][1]=0; pop[face2edge(U,L)][0]=4;
pop[face2corner(B,U,L)][1]=1; pop[face2corner(B,U,L)][0]=3; pop[face2edge(L,U)][1]=1; pop[face2edge(L,U)][0]=4;
pop[face2corner(L,B,U)][1]=2; pop[face2corner(L,B,U)][0]=3; pop[face2edge(L,F)][1]=0; pop[face2edge(L,F)][0]=5;

pop[face2corner(U,R,B)][1]=0; pop[face2corner(U,R,B)][0]=4; pop[face2edge(F,L)][1]=1; pop[face2edge(F,L)][0]=5;
pop[face2corner(B,U,R)][1]=1; pop[face2corner(B,U,R)][0]=4; pop[face2edge(R,F)][1]=0; pop[face2edge(R,F)][0]=6;
pop[face2corner(R,B,U)][1]=2; pop[face2corner(R,B,U)][0]=4; pop[face2edge(F,R)][1]=1; pop[face2edge(F,R)][0]=6;

pop[face2corner(D,L,F)][1]=0; pop[face2corner(D,L,F)][0]=5; pop[face2edge(L,B)][1]=0; pop[face2edge(L,B)][0]=7;
pop[face2corner(F,D,L)][1]=1; pop[face2corner(F,D,L)][0]=5; pop[face2edge(B,L)][1]=1; pop[face2edge(B,L)][0]=7;
pop[face2corner(L,F,D)][1]=2; pop[face2corner(L,F,D)][0]=5; pop[face2edge(R,B)][1]=0; pop[face2edge(R,B)][0]=8;

pop[face2corner(D,R,F)][1]=0; pop[face2corner(D,R,F)][0]=6; pop[face2edge(B,R)][1]=1; pop[face2edge(B,R)][0]=8;
pop[face2corner(F,D,R)][1]=1; pop[face2corner(F,D,R)][0]=6; pop[face2edge(D,F)][1]=0; pop[face2edge(D,F)][0]=9;
pop[face2corner(R,F,D)][1]=2; pop[face2corner(R,F,D)][0]=6; pop[face2edge(F,D)][1]=1; pop[face2edge(F,D)][0]=9;

pop[face2corner(D,L,B)][1]=0; pop[face2corner(D,L,B)][0]=7; pop[face2edge(D,R)][1]=0; pop[face2edge(D,R)][0]=10;
pop[face2corner(B,D,L)][1]=1; pop[face2corner(B,D,L)][0]=7; pop[face2edge(R,D)][1]=1; pop[face2edge(R,D)][0]=10;
pop[face2corner(L,B,D)][1]=2; pop[face2corner(L,B,D)][0]=7; pop[face2edge(D,B)][1]=0; pop[face2edge(D,B)][0]=11;

pop[face2corner(D,R,B)][1]=0; pop[face2corner(D,R,B)][0]=8; pop[face2edge(B,D)][1]=1; pop[face2edge(B,D)][0]=11;
pop[face2corner(B,D,R)][1]=1; pop[face2corner(B,D,R)][0]=8; pop[face2edge(D,L)][1]=0; pop[face2edge(D,L)][0]=12;
pop[face2corner(R,B,D)][1]=2; pop[face2corner(R,B,D)][0]=8; pop[face2edge(L,D)][1]=1; pop[face2edge(L,D)][0]=12;
    for(int i=0;i<20;i++){
        if (i<8){
            int_cube[i][0]=pop[face2corner(cubelet[let2int[i][0]/10][let2int[i][0]%10],
                                               cubelet[let2int[i][1]/10][let2int[i][1]%10],
                                               cubelet[let2int[i][2]/10][let2int[i][2]%10])
                                  ][0];
            int_cube[i][1]=pop[face2corner(cubelet[let2int[i][0]/10][let2int[i][0]%10],
                                               cubelet[let2int[i][1]/10][let2int[i][1]%10],
                                               cubelet[let2int[i][2]/10][let2int[i][2]%10])
                                  ][1];
        }
        else{
            int_cube[i][0]=pop[face2edge(cubelet[let2int[i][0]/10][let2int[i][0]%10],
                                             cubelet[let2int[i][1]/10][let2int[i][1]%10])
                                  ][0];
            int_cube[i][1]=pop[face2edge(cubelet[let2int[i][0]/10][let2int[i][0]%10],
                                             cubelet[let2int[i][1]/10][let2int[i][1]%10])
                                  ][1];
        }
    }
    return 0;
}

int cube::int_cube_output(){
    cout<<"ħ���������£�"<<endl;
    for(int i=0;i<2;i++){
    for(int j=0;j<20;j++){
        cout<<"cube::"<<" "<<int_cube[j][i];
    }
    cout<<endl;
    }
    return 0;
}
