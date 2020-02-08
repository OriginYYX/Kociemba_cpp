#include<iostream>
#include<queue>
#include<stack>
#include<utility>

    //#define for(i,a,b) for(int i=a;i<=b;i++)
    using namespace std;
    int ans[20];

/*

void printArr(int *arr){
    int i;
    for(i,0,19){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bfs(){
    string move_list("FRBLUD");
    int i=0;
    queue<pair<string,string>> move;
    int num=0;
    string ans_list("");
    pair<string,string> y;
    for(i,0,5){
        ans_list="";
        y.first=ans_list;
        y.second=move_list[i];
        move.push(y);
        cout<<y.second<<endl;
    }
    pair<string,string> temp;
    while (num++<700){
        int size = move.size();
		for(i,0,5){
            
            temp=move.front();
            y.first=temp.second;
            y.second=(y.first)+move_list[i];
            move.push(y);
            cout<<y.second<<endl;
        }
        move.pop();
	}

}
*/
int int_cube2Combination(const int *A,int num){
    int pop=1;
    int a=0;
    int hash_ans=0;
    num==8?a=3:a=2;
    for (int i=0;i<num;i++){
        hash_ans+=(A[i]*pop);
        pop*=a;
    }
    return hash_ans;
}
int arr[8]={0,1,0,1,0,1,0,0};
int main(){
    cout<<int_cube2Combination(arr,8);
    return 0;
}


