#ifndef TABLE_HPP_INCLUDED
#define TABLE_HPP_INCLUDED
#include "int_move.hpp"
#include <fstream>
#include <iostream>
extern int CornerOrientation_MoveTable[6560][12];
class table{
    void make_CornerOrientation_MoveTable();
    void show_CornerOrientation_MoveTable();
};

#endif // TABLE_HPP_INCLUDED
