/** Write a program that takes X and Y as input and calculates the value of X^Y using divide and conquer and prints it. */

#include <iostream>
using namespace std;


/** calculates x^y using divide and conquer */
long long power(int x, int y){
    if (y==0) {
        return 1;
    } else {
        int mid = y/2;
        long long p = power(x, mid);
        if (y%2==0) { // power even
            return p*p;
        } else {
            return p*p*x;
        }
    }
}

int main(){
    int X, Y;
    cin >> X >> Y;
    cout << power(X,Y);
}
