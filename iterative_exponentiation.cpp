// g++ iterative_exponentiation.cpp -o iterative_exponentiation && ./iterative_exponentiation

/*
    here we are finding a^n in log(n) time
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


int main(){

    ll a, n;
    cin >> a >> n;
    ll ans = 1;
    ll x = a;
    while (n){
        if (n%2) ans *= x;
        n /= 2;
        x *= x;
    }
    cout << ans << endl;

}

