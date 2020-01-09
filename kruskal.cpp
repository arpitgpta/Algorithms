// g++ kruskal.cpp -o kruskal && ./kruskal

/*
    making graph: we will make adjecency matrix of cost

*/

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL)
#define endl '\n'
#define ll long long int
using namespace std;
#define pii pair <int , int >
#define pll pair <ll , ll >
#define vin vector<int>
#define vll vector<long long>
#define deb(x) cout << #x << " " << x << endl
#define deb2(x, y) cout << #x << " " << x << " " << #y << " " << y << endl
#define loop(n) for(int i = 0; i < n; i++)
#define pb push_back

bool fun(vin a, vin b){
    return a[2] < b[2];
}

vin dis_set(9, -1);
vector<vin>  ad_mat(9, vin(9, INT_MAX));
vector<vin> edge_weight;

int get_parent(int a){
    if (dis_set[a] > 0) return get_parent(dis_set[a]);
    else return dis_set[a]*(-1);
}

void set_parent(int a, int b){
    dis_set[get_parent(b)] = get_parent(a);
}

int main(){

    fastio;    

    // putting weights of edges
    ad_mat[1][2] = 2;
    ad_mat[2][3] = 4;
    ad_mat[3][8] = 1;
    ad_mat[3][4] = 3;
    ad_mat[1][4] = 3;
    ad_mat[4][5] = 3;
    ad_mat[4][7] = 2;
    ad_mat[5][6] =4 ;
    ad_mat[6][7] = 5;
    ad_mat[7][8] = 2;


    // now making list of edges and virteces
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            if (ad_mat[i][j] < INT_MAX) {
                vin temp(3);
                temp[0] = i;
                temp[1] = j;
                temp[2] = ad_mat[i][j];
                edge_weight.pb(temp);
            }
        }
    }
    sort(edge_weight.begin(), edge_weight.end(), fun);

    for (auto i : edge_weight){
        cout << i[0] << " " << i[1] << " " << i[2] << endl;
    }
    cout << endl;

    int n = 1;

    for(int i = 1; i < 9; i++) dis_set[i] = i*(-1);

    vector<vin> ans;
    loop(edge_weight.end()-edge_weight.begin()){
        cout << "called for i " << i << endl;
        if (n > 7) break;
        int a = get_parent(edge_weight[i][0]);
        int b = get_parent(edge_weight[i][1]);
        deb2(a, b);
        if (a != b) {
            ans.pb(edge_weight[i]);
            n++;
            set_parent(edge_weight[i][0], edge_weight[i][1]);

        }
        a = get_parent(edge_weight[i][0]);
        b = get_parent(edge_weight[i][1]);
        deb2(a, b);
        cout << endl;
    }
    cout << "edge start      edge end        weight" << endl;
    loop(ans.end()-ans.begin()){
        cout << ans[i][0] << "\t\t" << ans[i][1] << "\t\t" << ans[i][2] << endl;
    }
}