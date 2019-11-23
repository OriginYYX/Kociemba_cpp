#ifndef CUBE_H
#define CUBE_H
//ULF URF ULB URB DLF DRF DLB DRB      LFU FUL
//UF UR UB UL || LF RF RB LB || DF DR DB DL

/**
       0 1 2
       3 5 5
       6 7 8

0 1 2  0 1 2  0 1 2  0 1 2
3 4 5  3 1 5  3 2 5  3 3 5
6 7 8  6 7 8  6 7 8  6 7 8

       0 1 2
       3 6 5
       6 7 8

1 5 1 1 1 1 1 1 1
2 2 2 2 2 2 2 2 2
3 1 3 3 3 3 3 3 3
4 3 4 4 4 4 4 4 4
5 5 5 5 5 5 5 4 5
6 6 6 6 6 6 6 6 6

1 1 1 1 1 1 1 1 1
2 2 2 2 2 2 2 2 2
3 3 3 3 3 3 3 3 3
4 4 4 4 4 4 4 4 4  
5 5 5 5 5 5 5 5 5
6 6 6 6 6 6 6 6 6
**/
extern int mid_pm[20][2];
class cube{
public:
    int cubelet[6][9];
    int input();
    int output();
    int int_cube_input();
    int int_cube_output();
private:
    int int_cube[20][2];
};
#endif
