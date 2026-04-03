#include <bits/stdc++.h>
using namespace std;

void heapify(int a[], int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if( left < n && a[largest] < a[left]){
        largest = left;
    }
    if( right < n && a[largest] < a[right]){
        largest = right;
    }
    //tim gia tri lon nhat trong 3 so trong nhanh cay
    if(largest != i){//neu so lon nhat ma khac gia tri ban dau dc gan thi swap no
        swap(a[largest], a[i]);//them tham chieu de thay doi gia tri ban dau
        heapify(a, n, largest);//goi dequy toi bien largest sau khi da swap
    }
}
void heapsort(int a[], int n){
    for( int i = n/2 - 1; i >= 0; i--){
        heapify(a, n, i);
    }
    for(int i = n-1; i >= 0; i--){
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}
void solve(){
    int n; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;
    heapsort(a, n);
    for(auto x : a) cout << x << " ";
}
int main(){
    solve();
}