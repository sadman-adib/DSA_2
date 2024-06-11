/**
 * find the Sum of even numbers in an array Arr of N integers
 **/


#include <iostream>
using namespace std;

int  countEven(  int Arr[],  int i,  int j  )  {
	if (i==j) {  // array size 1
        if ( Arr[i] % 2 == 0 ) return Arr[i];
        else return 0;
    } else {
        int mid = (i+j)/2;
        int c1 = countEven(Arr, i, mid); // solution to the first half
        int c2 = countEven(Arr, mid+1, j); // solution to the second half
        return c1+c2;
    }
}

int main(){
    int A[] = {6, 11, 4, 5, 8, 2};
    int N = sizeof(A)/sizeof(A[0]);
    cout << countEven(A, 0, N-1);
}
