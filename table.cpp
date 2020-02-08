#include "table.hpp"
#include <fstream>

/*
int cp[8];
int ep[12];
int co[8];
int eo[12];
*/

int CornerOrientation_MoveTable[6561][12];
int EdgeOrientation_MoveTable[4096][12];
int E_postion_MoveTable[495][12];
void table::make_CornerOrientation_MoveTable(){
    int_cube int_cube;
    for (int i=0;i<6561;i++){
        for (int j=1;j<=6;j++){
            int_cube.Combination2int_cube(i,8,co);
            int_cube.int_cube_move(j,0);
            CornerOrientation_MoveTable[i][(j-1)*2]=int_cube.int_cube2Combination(co,8);
            int_cube.int_cube_move(j,2);
            CornerOrientation_MoveTable[i][(j-1)*2+1]=int_cube.int_cube2Combination(co,8);
        }
    }
    ofstream f("CornerOrientation_MoveTable",ios::binary);
    if(!f)
    {
        cout << "创建文件失败" <<endl;
        return;
    }
    f.write((char*)CornerOrientation_MoveTable, sizeof(CornerOrientation_MoveTable));
    cout << "创建文件成功" <<endl;
    f.close();
}

void table::make_EdgeOrientation_MoveTable(){
    int_cube int_cube;
    for (int i=0;i<4096;i++){
        for (int j=1;j<=6;j++){
            int_cube.Combination2int_cube(i,12,eo);
            int_cube.int_cube_move(j,0);
            EdgeOrientation_MoveTable[i][(j-1)*2]=int_cube.int_cube2Combination(eo,12);
            int_cube.int_cube_move(j,2);
            EdgeOrientation_MoveTable[i][(j-1)*2+1]=int_cube.int_cube2Combination(eo,12);
        }
    }
    ofstream f("EdgeOrientation_MoveTable",ios::binary);
    if(!f)
    {
        cout << "创建文件失败" <<endl;
        return;
    }
    f.write((char*)EdgeOrientation_MoveTable, sizeof(EdgeOrientation_MoveTable));
    cout << "创建文件成功" <<endl;
    f.close();
}

void table::make_E_postion_MoveTable(){
    int_cube int_cube; 
    for (int i=0;i<495;i++){
        for (int j=1;j<=6;j++){
            int_cube.ChoicePermutation(i,eo);
            int_cube.int_cube_move(j,0);
            E_postion_MoveTable[i][(j-1)*2]=int_cube.E_postion2Combination(eo);
            int_cube.int_cube_move(j,2);
            E_postion_MoveTable[i][(j-1)*2+1]=int_cube.E_postion2Combination(eo);
        }
    }
    ofstream f("E_postion_MoveTable",ios::binary);
    if(!f)
    {
        cout << "创建文件失败" <<endl;
        return;
    }
    f.write((char*)E_postion_MoveTable, sizeof(E_postion_MoveTable));
    cout << "创建文件成功" <<endl;
    f.close();
}

void table::read_Table(){
   { ifstream f("E_postion_MoveTable", ios::in | ios::binary);
    f.read((char *)&E_postion_MoveTable, sizeof(E_postion_MoveTable));
    f.close();}
    {ifstream f("CornerOrientation_MoveTable", ios::in | ios::binary);
    f.read((char *)&CornerOrientation_MoveTable, sizeof(CornerOrientation_MoveTable));
    f.close();}
    {ifstream f("EdgeOrientation_MoveTable", ios::in | ios::binary);
    f.read((char *)&EdgeOrientation_MoveTable, sizeof(EdgeOrientation_MoveTable));
    f.close();}
}

void table::initialize_MoveTable() {
    
}

coordinates::coordinates(int *arr){
    coordinates::co=arr[0];
    coordinates::ed=arr[1];
    coordinates::ep=arr[2];
}       

int* coordinates::return_arr(int *arr){
    arr[0]=coordinates::co;
    arr[1]=coordinates::ed;
    arr[2]=coordinates::ep;
    return arr;
}

void coordinates::print_coor(){      
    cout<<"co is "<<coordinates::co<<"ed is "<<coordinates::ed<<"ep is "<<coordinates::ep<<endl;
}

void coordinates::coor_move(int move){
        co=CornerOrientation_MoveTable[co][move];
        ed=EdgeOrientation_MoveTable[ed][move];
        ep=E_postion_MoveTable[ep][move];
}

int bfs(int *arr){
    cout<<"bfs is begin!!!!"<<endl;
    queue<coordinates> move;
    
    for(int i=0;i<12;i++){
        coordinates temp(arr);
        temp.coor_move(i);
        temp.ans.push_back(i);
        move.push(temp);
        for (int i=0;i<temp.ans.size();i++){
                    cout<<"do is "<<temp.ans[i]<<" ";
                }
                cout<<endl;
    }
    int num=0;
    while (true){
        //cout<<num++<<endl
        int arr1[3] = {0};
		for(int i=0;i<12;i++){
            coordinates yyx(move.front().return_arr(arr1));
            yyx.coor_move(i);
            yyx.ans=move.front().ans;
            yyx.ans.push_back(i);
            if (yyx.co==0){
                cout<<yyx.co<<" "<<yyx.ed<<endl;
                cout<<"fuckkkkkk"<<endl;
                for (int i=0;i<yyx.ans.size();i++){
                    cout<<"ans is "<<yyx.ans[i]<<" ";
                }
                cout<<endl;
                return 0;
            }
            move.push(yyx);
        }
        move.pop();
	}

}
