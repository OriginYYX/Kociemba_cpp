
#include "cube.hpp"
#include "int_move.hpp"
int a;
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
    while (true){
        int a,b;
        cout<<"ÇëÊäÈëÄ§·½²Ù×÷£º";
        cin>>a>>b;
        int_cube.int_cube_move(a,b);
        int_cube.int_cube_output();
        cout<<endl;
    }

    return 0;
}

// cd "g:\Work\many_tests\Kociemba_cpp\" ; if ($?) { g++ main.cpp int_move.cpp cube.cpp -o main } ; if ($?) { .\main }
