#include <bits/stdc++.h>
using namespace std;
int n, m, a[102][102];
int x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
//luu cac buoc nhay(step)
void dequy(int i, int j){
    a[i][j] = 0; // cho cac phan tu = 0
    for(int k = 0; k < 8; k ++){
        int i1 = i + x[k];//tao i1, j1 xung quanh cac i, j
        int j1 = j + y[k];
            if(i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && a[i1][j1]){// kiem tra i1, j1 thuoc ma tran va a[i1][j1] gia tri = 1 de cho cac gia tri do = 0 va se ko duyet lai nua
                dequy(i1, j1);// cho cac phan tu i1, j1 = 0 
            }
    }//neu i = j = 1 thì dong if sẽ thay doi thành if( i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1])
}
int main(){
    int tc; cin >> tc;
    while(tc--){
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];// tot nhat la khai bao i = j =1 de nhung buoc nhay ko bi nam ngoai ma tran
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j]){
                    ++cnt;
                    dequy(i, j);
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
