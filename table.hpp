#ifndef TABLE_HPP_INCLUDED
#define TABLE_HPP_INCLUDED
#include "int_move.hpp"
#include <fstream>
#include <string>
#include <queue>
#include <vector>

extern int CornerOrientation_MoveTable[6561][12];
extern int EdgeOrientation_MoveTable[4096][12];
extern int E_postion_MoveTable[495][12];
extern int Co_Ed_PurnTable[6151][4096];
extern int Co_Ep_PurnTable[6151][495];
extern int Ed_Ep_PurnTable[4096][495];
class table{
    public:
    void initialize_MoveTable();
    void make_CornerOrientation_MoveTable();
    void make_EdgeOrientation_MoveTable();
    void make_E_postion_MoveTable();
    void save_MoveTable();
    void read_Table();
    void make_Co_Ed_PurnTable();
    void make_Co_Ep_PurnTable();
    void make_Ed_Ep_PurnTable();
};

class coordinates{
    public:
    coordinates(int *arr);
    void print_coor();
    void coor_move(int move);
    int* return_arr(int *arr);
    friend int bfs(int *arr);
    vector<int> ans;
    private:
    int co;
    int ed;
    int ep;
};

#endif // TABLE_HPP_INCLUDED
