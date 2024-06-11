/**
Write a function find_max_sum_subarray that finds the maximum sum subarray
of an array A of N integers using divide and conquer.
Write a main that takes the array A as input from the user and
prints the maximum sum subarray and its sum using the function find_max_sum_subarray.
 */

#include <iostream>
using namespace std;

#define INF 999999

int main()
{
    //cin >> N;
    int A[] = {-10, 11, -2, 20, -6, -5};
    int N = sizeof(A)/sizeof(A[0]);

    int sum, low=0, high=0;
    int mx = -INF;

    for(int i=0 ; i<N ; i++)
    {
        sum = 0 ;
        for(int j=i ; j<N ; j++)
        {
            sum = sum+A[j];
            if(sum > mx)
            {
                mx = sum;
                //low = i;
                //high = j;
            }
        }
    }
    //cout<<mx<<" "<<low<<" "<<high<<endl;
    cout<<mx<<endl;

}
