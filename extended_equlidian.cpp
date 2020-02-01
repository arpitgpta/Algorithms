// g++ extended_equlidian.cpp -o extended_equlidian && ./extended_equlidian

/*
    here if we are given A and B then we have to find
    1. GCD (A, B)
    2. x
    3. y
        where Ax + By = GCD(A, B) -------1

    Approch:
    we have, 
        1.
            if GCD(A, B) == A OR B = 0
            then x = 1 and y = 0

        2. 
            A%B = A - B*floor(A/B)

        3. 
            GCD(A, B) = GCD(B, A%B)

    now, putting values from 3 to 1
        Bx1 + (A%B)y1 = GCD(A, B)
    putting values from 2
        Bx1 + (A - B*floor(A/B))y1 = GCD(A,B)
        B(x1 - floor(A/B)y1) + Ay1 = GCD(A,B)

    on compairing with 1
        x = y1
        y = x1 - floor(A/B)y1
*/

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL)
#define endl '\n'
#define ll long long int
using namespace std;
#define pii pair <ll , ll >
#define vin vector<int>
#define vll vector<long long>
#define deb(x) cout << #x << " " << x << endl
#define deb2(x, y) cout << #x << " " << x << " " << #y << " " << y << endl
#define loop(n) for(int i = 0; i < n; i++)


int extended_equlidian(int A, int B, int& x, int &y){
    if (B == 0){
        x = 1;
        y = 0;
        return A;
    }
    else {
        int gcd = extended_equlidian(B, A%B, x, y);
        int temp = x;
        x = y;
        y = temp - (A/B)*y; 
        return gcd;
    }
}

int main(){

    int A, B;
    while (cin >> A >> B){
        int x, y;
        int gcd = extended_equlidian(A, B, x, y);
        cout << x << " " << y << " ";
        cout << gcd << endl; 
    }

}