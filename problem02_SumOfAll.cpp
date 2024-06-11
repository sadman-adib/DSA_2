/**
 * find the sum of all numbers in an array Arr of N integers
 **/


#include <iostream>
using namespace std;

int  countSum(  int Arr[],  int i,  int j  )  {
	if (i==j) {  // array size 1
         return Arr[i];
    } else {
        int mid = (i+j)/2;
        int c1 = countSum(Arr, i, mid); // solution to the first half
        int c2 = countSum(Arr, mid+1, j); // solution to the second half
        return c1+c2;
    }
}

int main(){
    int A[] = {6, 11, 4, 5, 8, 2};
    int N = sizeof(A)/sizeof(A[0]);
    cout << countSum(A, 0, N-1);
}
