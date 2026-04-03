#include <bits/stdc++.h>
using namespace std;
int x[8] = {-1, -1, -1, 0, 0, 1, 1, 1}; // tao 2 mang de chua nhung buoc nhay 
int y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};// nhu tren
int main(){
    int tc; cin >> tc;
    while (tc--){
        int n, m; cin >> n >> m;
        int a[500][500];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }
        int res[500][500];// tao 1 mang de luu tru nhung ket qua cua tung [i][j] sau khi cong don xong 
        for(int i = 0; i < n; i++){
            for( int j = 0; j < m; j++){
                int sum = 0; // hoac khai bao int sum = a[i][j];
                for(int k = 0; k < 8; k++){ // tao 1 vong for voi bien k de cong don va len tren 1 bien moi
                    int imoi = i + x[k];// cong theo 1 hinh vuong, voi tung buoc nhay nhu da khai bao mang
                    int jmoi = j + y[k];// nhu tren
                    if (imoi >= 0 && imoi < n && jmoi >= 0 && jmoi < m){ // kiem tra de khi cong no se ko cong nhung [i][j] nam ngoai ma tran
                        sum += a[imoi][jmoi];// cong don 
                    }
                }
                sum += a[i][j]; // co the xoa
                res[i][j] = sum;// cap nhat ket qua da cong cho mang res luu tru
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << res[i][j] << " ";// cout ra mang res 
            }
            cout << endl;
        }
    }
    return 0;
}