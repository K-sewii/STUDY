#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    int a[n+1][m+1];
    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];//nhap gia tri matran
        }
    }
    int prefix[n+1][m+1] = {0}; // tao 1 mang ma tat ca phan tu n.m = 0
    //memset(prefix, 0, sizeof(prefix));
    for (int i = 1; i <= n; i++){
        for ( int j = 1; j <= m; j++){
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + a[i][j]; // y chang sum += a[i][j], tinh tong tung gia tri trong mang prefix theo 1 hcn
        }
    }
    int tc; cin >> tc;
    while(tc--){
        int h1, h2, c1, c2; cin >> h1 >> h2 >> c1 >> c2; // tao cac bien cot va hang de tim tong cac gia tri hcn can tim
        cout <<  prefix[h2][c2] - prefix[h1-1][c2] - prefix[h2][c1-1] + prefix[h1-1][c1-1]; // sau khi da tinh tong ( bien sum cong don) thi tru tung hang va cot ko can tim de ra ket qua sum can tinh
    }
    return 0;
}