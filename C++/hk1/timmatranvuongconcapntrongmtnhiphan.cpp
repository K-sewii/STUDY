#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc; cin >> tc;
    while(tc--){
        int n, m; cin >> n >> m;
        int a[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }
        int mt[n][m];
        for(int i = 0; i < n ; i++){
            mt[i][0] = a[i][0];
        }
        for(int j = 0; j < m; j++){
            mt[0][j] = a[0][j];
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                mt[i][j] = min(mt[i-1][j-1], min(mt[i+1][j], mt[i+1][j-1])) + 1;
                //tim phan tu nho nhat trong ma tran 2x2 de tang phan tu cuoi hang va cuoi cot len 1 don vi neu no tao thanh 1 ma tran
                // vd ta co 0 1
                //          1 1            thi phan tu nho nhat la 0 nen ko tao dc ma tran vuong 2x2 nen ko tang 1 don vi
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                res = max(res, a[i][j]);
            }
        }
        cout << res << endl;
    }
}