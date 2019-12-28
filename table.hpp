#ifndef TABLE_HPP_INCLUDED
#define TABLE_HPP_INCLUDED
#include "int_move.hpp"

extern int CornerOrientation_MoveTable[6151][12];
extern int EdgeOrientation_MoveTable[4096][12];
class table{
    void make_CornerOrientation_MoveTable();
    void make_EdgeOrientation_MoveTable();
};

#endif // TABLE_HPP_INCLUDED
