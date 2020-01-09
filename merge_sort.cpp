#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
void Sort(int i, int j){
    
    if(i == i) return;
    Sort(i, (i+j)/2);
    Sort((i+j)/2+1, j);

    vector<int> temp(j-i);
    int i_, j_, t = 0;
    int mid = (i+j)/2;
    while(i_ < mid && )

}