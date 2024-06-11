/**
Write a function find_max_sum_subarray that finds the maximum sum subarray
of an array A of N integers using divide and conquer.
Write a main that takes the array A as input from the user and
prints the maximum sum subarray and its sum using the function find_max_sum_subarray.
 */

#include <iostream>
using namespace std;

#define INF 999999

struct Result
{
    int l, h, sum;
};

Result find_max_crossarray(int A[], int low, int mid, int high)
{
    int left_sum = -INF, max_left;
    int sum = 0;
    for (int i = mid; i >= low; i--)
    {
        sum += A[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = -INF, max_right;
    sum = 0;
    for (int j = mid + 1; j <= high; j++)
    {
        sum += A[j];
        if (sum > right_sum)
        {
            right_sum = sum;
            max_right = j;
        }
    }
   /* Result s;
    s.l = max_left;
    s.r = max_right;
    s.sum = left_sum + right_sum;
    return s; */
    return {max_left, max_right, left_sum + right_sum};
}

Result find_max_sum_subarray(int A[], int low, int high)
{
    if (high == low)
        return {low, high, A[low]};

    int mid = (low + high) / 2;
    Result left = find_max_sum_subarray(A, low, mid);
    Result right = find_max_sum_subarray(A, mid + 1, high);
    Result cross = find_max_crossarray(A, low, mid, high);

    if (left.sum >= right.sum && left.sum >= cross.sum)
        return left;
    else if (right.sum >= left.sum && right.sum >= cross.sum)
        return right;
    else
        return cross;
}

int main()
{
    /*
    int A[] = {-10, 11, -2, 20, -6, -5};
    int n = sizeof(A)/sizeof(A[0]);

    Result r = find_max_sum_subarray(A, 0, n-1);
    cout << "[" << r.l <<","<< r.h<<"]: " << endl;
    for (int i=r.l;i<=r.h;i++)
        cout << A[i] << "+";
    cout << "=" << r.sum << endl;
    */

    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    Result r = find_max_sum_subarray(A, 0, N - 1);
    for (int i=r.l;i<=r.h;i++)
        cout << A[i] << " ";
    cout << endl;
    cout << "sum " << r.sum << endl;
}
