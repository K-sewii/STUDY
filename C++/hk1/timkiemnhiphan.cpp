#include <bits/stdc++.h>
using namespace std;
int binary_search(int a[], int l, int r, int x){
    int res;
    while(l <= r){
        int m = (l+r)/2;
        if(a[m]> x){
            r = m-1;
        }
        if(a[m] < x){
            l = m + 1;
        }
        if(a[m]== x){
            res = m;
        }
    }
    return res;
}
void merge(int a[], int l, int m, int r){   
    vector<int> x(a+l, a+m+1);
    vector<int> y(a+m+1, a+r+1);
    int i = 0, j = 0;
    while(i < x.size() && j < y.size()){
        if(a[i] >= a[j]){
            a[l] = a[j]; 
            l++;
            j++;
        }
        else {
            a[l] = a[i];
            l++;
            i++;
        }
        while(i < x.size()){
            a[l] = a[i]; i++; l++;
        }
        while(j < y.size()){
            a[l] = a[j]; j++; l++;
        }
    }

}