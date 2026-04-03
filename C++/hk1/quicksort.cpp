#include <bits/stdc++.h>
using namespace std;
//lomuto
int partition(int a[], int l, int r){
    int i = l - 1;
    int x = a[r];
    for(int j = l; j < r; j++){
        if(a[j] <= x){
            ++i;
            swap(a[i], a[j]);
        }
    }
    swap(a[r], a[i+1]);
    return i+1;//tra be vi tri de de.quy
}
void quicksort(int a[], int l, int r){
    if(l >= r) return;
    int p = partition(a, l, r);
    quicksort(a, l , p-1);
    // them p - 1 de ko bi trung key 
    //phai co p-1 de tach key ra, vi luc dau no da chia thanh 2 mang > key va < key, nếu đổi thành sẽ bị lặp cái key => ko sắp xếp dc mảng
    quicksort(a, p+1, r);
}
//hoare
void qs(int a[], int l, int r){
    int x = a[r];
    int i = l; int j = r;
    while(i < j){
        while(a[i] < x){
            i++;
        }
        while(a[j] > x){
            j--;
        }
        if(i <= j){
            swap(a[i], a[j]);
            ++i; --j;
        }
    }
    if(l < j) qs(a, l , j);
    if(i < r) qs(a, i, r);
}
int main (){
    int a[1000], n;
    cin >> n;
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        a[i] = rand() % 1000;
    }
    qs(a, 0, n-1);
    for(int i = 0;i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}