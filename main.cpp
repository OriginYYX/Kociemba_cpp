#include "cube.hpp"
#include "int_move.hpp"
#include "table.hpp"
int a;
int bfs(int *arr);
int main()
{
    cube cube;
    cube.input();
    std::cout<<"okkkkkkkkkkkk"<<std::endl;
    cube.output();
    cube.int_cube_input();
    cube.int_cube_output();
    int_cube int_cube;
    int_cube.set_int_cube();
    int_cube.int_cube_output();
    table t1;
    /*
    t1.make_CornerOrientation_MoveTable();
    t1.make_E_postion_MoveTable();
    t1.make_EdgeOrientation_MoveTable();
    */
   t1.read_Table();
   int arr[3];
   
   for (int i=0;i<8;i++){
       
       cout<<co[i]<<" ";
   }
   int_cube.returnArr(arr);
   cout<<"ed is"<<endl;
   for (int i=0;i<3;i++){
       
       cout<<arr[i]<<" ";
   }
   bfs(int_cube.returnArr(arr));
    /*
    while (true){
        int a,b;
        cout<<"������ħ��������";
        cin>>a>>b;
        int_cube.int_cube_move(a,b);
        int_cube.int_cube_output();
        cout<<endl;
    }
    */
   getchar();
   getchar();
    return 0;
}

// cd "g:\Work\many_tests\Kociemba_cpp\" ; if ($?) { g++ main.cpp int_move.cpp cube.cpp -o main } ; if ($?) { .\main }
// cd "c:\Users\Oringin\Documents\Program\Kociemba_cpp\" ; if ($?) { g++ main.cpp int_move.cpp cube.cpp permutation.cpp table.cpp  -o main } ; if ($?) { .\main }
// 绿1 橙2 蓝3 红4 黄5 白6
/*
1 1 6 1 1 5 1 1 1
2 2 5 3 2 2 5 2 2
3 2 2 3 3 3 3 3 3
3 4 4 4 4 4 4 4 4 
5 5 4 5 5 1 5 5 1
6 6 2 6 6 6 6 6 6
*/