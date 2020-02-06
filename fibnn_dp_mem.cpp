// g++ fibnn_dp_mem.cpp -o fibnn_dp_mem && ./fibnn_dp_mem

/*


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

vll dp(1000, -1);

ll fibnn(int n){
    if(dp[n] != -1) return dp[n];
    dp[n] = fibnn(n-1) + fibnn(n-2);
    return dp[n];
}

int main(){

    dp[0] = 0;
    dp[1] = 1;
    int n;
    cin >> n;
    fibnn(n);
    loop(n) cout << dp[i] << " "; cout << endl; 
}