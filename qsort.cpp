#include<iostream>
#include<conio.h>
using namespace std;

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

void sort(int arr[], int l, int h){
    
    int j;
    if(l < h){
        j = part(arr,l,h);
        sort(arr,l,j);
        sort(arr, j+1, h);
    }

}


int main(){

    cout << "enter size" << endl;
    int s;
    cin >> s;

    int arr[s];
    for(int i = 0; i < s; i++) cin >> arr[i];
    sort(arr, 0, s);
    for(int i = 0; i < s; i++) cout << arr[i] << " ";
}