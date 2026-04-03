#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc; cin >> tc;
    while (tc--){
        int n,m; cin >> n >> m;
        int a[n];
        for (int &x : a) cin >> x;
        int mang[101] = {0};
        for (int i = 0; i < m; i++){
            int x; cin >> x;
            mang[x-1] = 1; // danh dau su xuat hien cua phan tu co the hoan vi trong mang qua x
        }
        for (int i = 0; i < n; i++){
            if (mang[i] == 0) continue;
            int res = i;
            while( res < n && mang[res]){
                res++;
            }
            sort(a + i, a + res + 1);// sap xep theo thu tu tang dan 
            i = res; // phai cap nhat i de giam do phuc tap bai toan
        }
        bool ok = true;
        for (int i = 0; i < n-1; i++){
            if (a[i] > a[i+1]){
                ok = false;
                break;
            }
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}