#include "int_move.hpp"
int int_cube::int_cube2Combination(const int *A,int num){
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

int* int_cube::returnArr(int *arr){
	arr[0]=int_cube2Combination(co,8);
	arr[1]=int_cube2Combination(eo,12);
	arr[2]=E_postion2Combination(ep);
	return arr;
}

int int_cube::Combination2int_cube(int hash_ans,int num,int *A){
	int pop=1;
	int a=0;
	num==8?a=3:a=2;
	for (int i=0;i<num;i++){
		A[i]=hash_ans%a;
		hash_ans/=a;
	}
    return 0;
}

int int_cube::E_postion2Combination(const int *edgeMarkVector){
    int edgesRemaining = 4;		 
	int ordinal = 0;		 
	int edge;
	edge = 0;
	while (edgesRemaining > 0)
	{
		if (edgeMarkVector[edge++])
			edgesRemaining--;	 
		else
			ordinal += NChooseM(12-edge, edgesRemaining-1);
	}
	return ordinal;
}


int ChoiceOrdinal(int* choicePermutation)
{
	int edgesRemaining = 4;		// Counts remaining edges
	int ordinal = 0;		// The choice permutation ordinal
	int edge;				// The current edge

	edge = 0;
	while (edgesRemaining > 0)
	{
		if (choicePermutation[edge++])
			edgesRemaining--;	// One less edge to go
		else
			// Skip this many permutations
			ordinal += NChooseM(12-edge, edgesRemaining-1);
	}
	return ordinal;
}


void int_cube::ChoicePermutation(int choiceOrdinal, int* choicePermutation)
{
	int edge;		// The current edge
	int digit = 0;		// The currend edge permutation "digit"
	int combinations;	// Number of combinations prefixed with this "digit"

	// All other edges are unknown, so begin by initializing them to "invalid"
	for (edge = 0; edge < 12; edge++)
		choicePermutation[edge] = 0;

	// Advance four "digits"
	for (edge = 0; edge < 4; edge++)
	{
		// This is something like division where we divide by subtracting
		// off the number of combinations possible for the current "digit".
		for (;;)
		{
			// Initially starting at 0###, so this begins at 11 Choose 3
			//   (0 is eliminated leaving 11 possibilites, and there are
			//    3 unassigned "digits")
			// N decreases each time we advance the "digit"
			// M decreases each time we move one "digit" to the right
			combinations=NChooseM(12-1-digit++, 4-1-edge);
			if (choiceOrdinal >= combinations)
				choiceOrdinal -= combinations;
			else
				break;
		}
		// Since digit is always bumped, must back up by one
		// Assign middle slice edges in ascending order
		choicePermutation[digit-1] = 1;
	}
}