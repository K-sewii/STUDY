#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int a[n];
    for ( int i = 1; i <= n; i++) cin >> a[n];
    int prefix[n + 1] = {0}; // mang cong don de do phuc tap thanh O(1)
    for ( int i = 1; i <= n; i++){
        prefix[i]=prefix[i-1] + a[i];// cap nhat mang prefix y nhu sum += a[i] 
    }
    int tc; cin >> tc;
    while(tc--){
        int l, r; cin >> l >> r;
        cout << prefix[r] - prefix[l-1] << endl; // cung co the dung vong for de duyet mang roi cho sum += a[i] nhung do phuc tap la O(n)
    }
    return 0;
}