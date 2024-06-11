#include <iostream>
using namespace std;

struct Res
{
    int mx, mn;
};


Res findMaxMin(int A[], int i, int j)
{
    if (i == j)
    {
        return {A[i], A[i]};
    }

    else
    {
        int mid = (i + j) / 2;
        Res res1 = findMaxMin(A, i, mid);
        Res res2 = findMaxMin(A, mid + 1, j);

        int mx = max(res1.mx, res2.mx);
        int mn = min(res1.mn, res2.mn);
        return {mx, mn};
    }
}

int main()
{
    //cout<<"efefef"<<endl;
    int A[100];
    int N;
    cin >> N;

    for(int i=0; i<N; i++)
    {
        cin >> A[i];
    }
    Res res = findMaxMin(A, 0, N - 1);
    printf("max: %d\n", res.mx);
    printf("min: %d\n", res.mn);
}
