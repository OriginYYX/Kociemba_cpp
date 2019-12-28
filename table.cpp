#include "table.hpp"
int cp[8];
int ep[12];
int co[8];
int eo[12];
int CornerOrientation_MoveTable[6151][12];
void table::make_CornerOrientation_MoveTable(){
    int_cube int_cube;
    for (int i=0;i<6561;i++){
        for (int j=1;j<=6;j++){
            int_cube.Combination2int_cube(i,3,co);
            int_cube.int_cube_move(j,0);
            CornerOrientation_MoveTable[i][(j-1)*2]=int_cube.int_cube2Combination(co,3);
            int_cube.int_cube_move(j,1);
            CornerOrientation_MoveTable[i][(j-1)*2]=int_cube.int_cube2Combination(co,3);
    }
}

void table::make_EdgeOrientation_MoveTable(){
    int_cube int_cube;
    for (int i=0;i<4096;i++){
        for (int j=1;j<=6;j++){
            int_cube.Combination2int_cube(i,2,eo);
            int_cube.int_cube_move(j,0);
            EdgeOrientation_MoveTable[i][(j-1)*2]=int_cube.int_cube2Combination(eo,2);
            int_cube.int_cube_move(j,1);
            EdgeOrientation_MoveTable[i][(j-1)*2]=int_cube.int_cube2Combination(eo,2);
    }
}
