#include <iostream>
using namespace std;
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
int NChooseM(int N, int M)
{
	int NoverMfact = N;	// Iterates from N down to M+1 to
				//   compute N! / (N-M)!
	int Mfact = 1;		// Iterates from 1 to M to divide
				//   out the M! term
	int Result = 1;		// Holds the result of N choose M
	if (N < M) return 0;	// M must be a subset of M
	if (M > N/2) M = N-M;	// Optimization
	while (NoverMfact > M)
	{
		Result *= NoverMfact--;	// Work on the N! / (N-M)! part
		Result /= Mfact++;	// Divide out the M! part
	}
	return Result;
}

int ChoiceOrdinal(int* choicePermutation)
{
	int edgeMarkVector[12];		// For radix sort of the edges
	int edgesRemaining = 4;		// Counts remaining edges
	int ordinal = 0;		// The choice permutation ordinal
	int edge;				// The current edge

	// Radix sort the edges
	for (edge = 0; edge < 12; edge++)
		edgeMarkVector[edge] = 0;
	for (edge = 0; edge < 4; edge++)
		edgeMarkVector[choicePermutation[edge]] = 1;

	// Scan the edges and compute the ordinal for this permutation
	edge = 0;
	while (edgesRemaining > 0)
	{
		if (edgeMarkVector[edge++])
			edgesRemaining--;	// One less edge to go
		else
			// Skip this many permutations
			ordinal += NChooseM(12-edge, edgesRemaining-1);
	}
	return ordinal;
}


int main(){
    int pop[12]={0,1,2,4};
    cout<<"hash="<<ChoiceOrdinal(pop)<<endl;
    return 0;
}

//b=98 98-11=87
