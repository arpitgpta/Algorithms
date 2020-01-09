// g++ fractional_knapsac.cpp -o fractional_knapsac && ./fractional_knapsac

/*
    this is a greedy based problem, we are being greedy on the paremeter "profit per unit weight"
    algo:
        take input in vector of pair
        sort the vector in the decreasing order of ratio
        loop:
            if(remining weight is less than wt. of object) profit += profit of object
            else profit += rem*(profit per unit weight)
        print profit

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

bool fun(pair<float, float> a, pair<float, float> b){
    return a.second/a.first > b.second/b.first;
}

int main(){

    // fastio;    
    
    int n;
    cout << "Enter number of elements" << endl;
    cin >> n;
    
    float rem;
    cout << "Enter maximum allowed weight" << endl;
    cin >> rem;

    vector<pair<float, float>> arr(n);
    cout << "Enter object weight and its profit" << endl;
    loop(n) cin >> arr[i].first >> arr[i].second;

    sort(arr.begin(), arr.end(), fun);

    float profit = 0;

    loop(n){
        if(arr[i].first < rem){
            profit += arr[i].second;
            rem -= arr[i].first;
        }
        else{
            float temp = (arr[i].second/(float)arr[i].first);
            profit += (rem*temp);
            break;
        }
    }

    cout << "Max possible profit is " << profit << endl;

}