// g++ kth_smallest.cpp -o kth_smallest && ./kth_smallest

/*
    we have to find k_th smallest number using divide and conqure technique
    logic:
        we will modify quick sort 
        here we will do partition same as quick sort 
        then if k is less than pivot index then we will discard right part and try to find in left part
        and vise versa
        base case: if pivot index is equal to k then we will return value at kth index, that will be kth min
*/

#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << " " << x << endl
#define deb2(x, y) cout << #x << " " << x << " " << #y << " " << y << endl

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int part(int arr[], int l, int h){
    int pvt  = arr[l];
    int i = l;
    int j = h;

    do{
        do{i++;}while(arr[i] <= pvt);
        do{j--;}while(arr[j] > pvt);
        if(i < j)swap(&arr[i], &arr[j]);
    }while(i < j);
    swap(&arr[l], &arr[j]);
    return j;
}

int kth_min(int arr[], int l, int h, int k){

    cout << endl << endl << "function called, low=> " << l << " high=> " << h << endl;
    int j;
    if(l < h){
        j = part(arr,l,h);
        deb(j);
        if(k == j) {
            return j;
        }
        if(k < j){
            kth_min(arr, l, j, k);
        }
        else{
            kth_min(arr, j+1, h, k);
        }
    }
    return 0;
}


int main(){

    cout << "enter size" << endl;
    int s, k;
    cin >> s;

    int arr[s];
    for(int i = 0; i < s; i++) cin >> arr[i];
    cout << "Enter k to find kth min" << endl;
    cin >> k;
    int ans = kth_min(arr, 0, s, k-1);
    cout << arr[ans] << endl;

}