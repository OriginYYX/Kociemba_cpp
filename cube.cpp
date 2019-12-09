#include<iostream>
#include"cube.hpp"
#define face2corner(a,b,c) 36*a+6*b+c
#define face2edge(a,b) a*6+b
int pop[258][2];
int mid_pm[20][2];
int F =1,R=2,B=3,L=4,U=5,D=6;

const int let2int [20][3]={{46,0,32},{48,10,2},{40,30,22},{42,20,12},{50,38,6},{52,8,16},{56,28,36},{58,18,26},
                           {47,1,0},{45,11,0},{41,21,0},{43,31,0},
                           {35,3,0},{13,5,0},{33,25,0},{15,23,0},
                           {51,07,0},{55,17,0},{57,27,0},{53,37,0}};
using namespace std;



int cube::input(){
    cout<<"ÊäÈëÄ§·½×´Ì¬£º"<<endl;
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
    /*   0    1    2	(Twist)
	    URF, RFU, FUR,
	    UFL, FLU, LUF,
	    ULB, LBU, BUL,
	    UBR, BRU, RUB,
	    DFR, FRD, RDF,
	    DLF, LFD, FDL,
	    DBL, BLD, LDB,
	    DRB, RBD, BDR };

 Edge facelet locations */
pop[face2corner(U,F,L)][1]=0; pop[face2corner(U,F,L)][0]=1; pop[face2edge(U,F)][1]=0; pop[face2edge(U,F)][0]=1;
pop[face2corner(F,L,U)][1]=1; pop[face2corner(F,L,U)][0]=1; pop[face2edge(F,U)][1]=1; pop[face2edge(F,U)][0]=1;
pop[face2corner(L,U,F)][1]=2; pop[face2corner(L,U,F)][0]=1; pop[face2edge(U,R)][1]=0; pop[face2edge(U,R)][0]=2;

pop[face2corner(U,R,F)][1]=0; pop[face2corner(U,R,F)][0]=2; pop[face2edge(R,U)][1]=1; pop[face2edge(R,U)][0]=2;
pop[face2corner(R,F,U)][1]=1; pop[face2corner(R,F,U)][0]=2; pop[face2edge(U,B)][1]=0; pop[face2edge(U,B)][0]=3;
pop[face2corner(F,U,R)][1]=2; pop[face2corner(F,U,R)][0]=2; pop[face2edge(B,U)][1]=1; pop[face2edge(B,U)][0]=3;

pop[face2corner(U,L,B)][1]=0; pop[face2corner(U,L,B)][0]=3; pop[face2edge(U,L)][1]=0; pop[face2edge(U,L)][0]=4;
pop[face2corner(L,B,U)][1]=1; pop[face2corner(B,U,L)][0]=3; pop[face2edge(L,U)][1]=1; pop[face2edge(L,U)][0]=4;
pop[face2corner(B,U,L)][1]=2; pop[face2corner(L,B,U)][0]=3; pop[face2edge(L,F)][1]=0; pop[face2edge(L,F)][0]=5;

pop[face2corner(U,B,R)][1]=0; pop[face2corner(U,B,R)][0]=4; pop[face2edge(F,L)][1]=1; pop[face2edge(F,L)][0]=5;
pop[face2corner(B,R,U)][1]=1; pop[face2corner(B,R,U)][0]=4; pop[face2edge(R,F)][1]=0; pop[face2edge(R,F)][0]=6;
pop[face2corner(R,U,B)][1]=2; pop[face2corner(R,U,B)][0]=4; pop[face2edge(F,R)][1]=1; pop[face2edge(F,R)][0]=6;

pop[face2corner(D,L,F)][1]=0; pop[face2corner(D,L,F)][0]=5; pop[face2edge(L,B)][1]=0; pop[face2edge(L,B)][0]=7;
pop[face2corner(L,F,D)][1]=1; pop[face2corner(F,D,L)][0]=5; pop[face2edge(B,L)][1]=1; pop[face2edge(B,L)][0]=7;
pop[face2corner(F,D,L)][1]=2; pop[face2corner(L,F,D)][0]=5; pop[face2edge(R,B)][1]=0; pop[face2edge(R,B)][0]=8;

pop[face2corner(D,F,R)][1]=0; pop[face2corner(D,F,R)][0]=6; pop[face2edge(B,R)][1]=1; pop[face2edge(B,R)][0]=8;
pop[face2corner(F,R,D)][1]=1; pop[face2corner(F,R,D)][0]=6; pop[face2edge(D,F)][1]=0; pop[face2edge(D,F)][0]=9;
pop[face2corner(R,D,F)][1]=2; pop[face2corner(R,D,F)][0]=6; pop[face2edge(F,D)][1]=1; pop[face2edge(F,D)][0]=9;

pop[face2corner(D,B,L)][1]=0; pop[face2corner(D,B,L)][0]=7; pop[face2edge(D,R)][1]=0; pop[face2edge(D,R)][0]=10;
pop[face2corner(B,L,D)][1]=1; pop[face2corner(B,L,D)][0]=7; pop[face2edge(R,D)][1]=1; pop[face2edge(R,D)][0]=10;
pop[face2corner(L,D,B)][1]=2; pop[face2corner(L,D,B)][0]=7; pop[face2edge(D,B)][1]=0; pop[face2edge(D,B)][0]=11;

pop[face2corner(D,R,B)][1]=0; pop[face2corner(D,R,B)][0]=8; pop[face2edge(B,D)][1]=1; pop[face2edge(B,D)][0]=11;
pop[face2corner(R,B,D)][1]=1; pop[face2corner(B,D,R)][0]=8; pop[face2edge(D,L)][1]=0; pop[face2edge(D,L)][0]=12;
pop[face2corner(B,D,R)][1]=2; pop[face2corner(R,B,D)][0]=8; pop[face2edge(L,D)][1]=1; pop[face2edge(L,D)][0]=12;
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
    cout<<"this is cube class:"<<endl;
    for(int i=0;i<2;i++){
    for(int j=0;j<20;j++){
        cout<<" "<<int_cube[j][i];
        mid_pm[j][i]=int_cube[j][i];
    }
    cout<<endl;
    }
    return 0;
}
