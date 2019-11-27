#include "int_move.hpp"
using namespace std;
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

int int_cube::int_cube_move(int move){
    
}