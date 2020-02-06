// g++ fibnn_dp_table.cpp -o fibnn_dp_table && ./fibnn_dp_table

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
#define pb push_back

int main(){
    
    vin dp_table;
    dp_table.pb(0);
    dp_table.pb(1);
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++)    dp_table.pb(dp_table[i-1] + dp_table[i-2]);
    loop(n) cout << dp_table[i] << " "; cout << endl;

}