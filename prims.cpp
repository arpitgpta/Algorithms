// g++ prims.cpp -o prims && ./prims

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
int dustbin;


vector<vin> heap(100, vin(3, INT_MAX));
int heap_size = 1;

void insert(vin edge){
    
    heap[heap_size] = edge;

    int last = heap_size;
    while (last > 1){
        int temp = heap[last/2][2];
        if (temp > edge[2]){
            heap[last] = heap[last/2];
            last /= 2;
        }    
        else break;
    }
    heap[last] = edge;
    heap_size++;
}

vin _delete(){

    vin ans = heap[1];
    heap[1] = heap[heap_size];
    int temp = 1;
    while(1){
        if (heap[temp][2] > heap[2*temp][2]){
            swap(heap[temp], heap[2*temp]);
            temp = 2*temp;
        }
        else if (heap[temp][2] > heap[2*temp+1][2]){
            swap(heap[temp], heap[2*temp+1]);
            temp = 2*temp+1;
        }
        else break;
    }
    heap_size--;
    return ans;
}

int main(){

    int n = 9;
    
    vector<vin> matrix(n+1, vin(n+1, INT_MAX));
    vector<vin> selected_edges;
    map<int, bool> selected;

    matrix[1][2] = 2;
    matrix[2][3] = 4;
    matrix[3][8] = 1;
    matrix[3][4] = 3;
    matrix[1][4] = 3;
    matrix[4][5] = 3;
    matrix[4][7] = 2;
    matrix[5][6] = 4;
    matrix[6][7] = 5;
    matrix[7][8] = 2;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (matrix[j][i] != INT_MAX) matrix[i][j] = matrix[j][i];
        }
    }

    int start;
    cout << "Enter starting virtex" << endl;
    cin >> start;
 
    selected[start] = true;
 
    for (int i = 1; i <= n; i++){
        if (matrix[start][i] != INT_MAX){
            vin temp = {start, i, matrix[start][i]};
            insert(temp);
        }
    }
    
    int taken = 0;
    vector<vin> answer;
    while (taken < 7){
        vin temp(3);
        temp = _delete();

        if (!( selected[temp[0]] == true && selected[temp[1]] == true )){
            answer.pb(temp);
            taken++;
            int new_vtx = !selected[temp[0]] ? temp[0] : temp[1];
            selected[new_vtx] = true;
            for (int i = 1; i <= n; i++){
                if (matrix[new_vtx][i] != INT_MAX){
                    vin temp = {new_vtx, i, matrix[new_vtx][i]};
                    insert(temp);
                }       
            }
        }
    }

    for(auto k : answer) cout << k[0] << " " << k[1] << " " << k[2] << endl;
}