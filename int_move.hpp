#ifndef INT_MOVE_H
#define INT_MOVE_H
#include <iostream>
#include "cube.hpp"
using namespace std;
extern int cp[8];
extern int ep[12];
extern int co[8];
extern int eo[12];
class int_cube{
public:
    int int_cube_output();
    int set_int_cube();
    int int_cube[20][2];
    int int_cube_move(int move,int count);
    int int_cube2Combination(const int *A,int num);
    int Combination2int_cube(int hash_ans,int num);
    int E_postion2Combination(const int *A);

};

#endif
