#include <bits/stdc++.h>
using namespace std;
int a[101][101],b[101][101];
int n, m,cnt;
int x[4] = {-1, 0, 0 , 1};
int y[4] = {0, -1, 1, 0};
void dq(int i , int j){
    a[i][j] = 0; 
    int dem = 0;// reset bien dem
    // de dem co bao nhieu canh
    for(int k = 0; k < 4; k++){
        int i1 = i + x[k];
        int j1 = j + y[k];
        if( i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && b[i1][j1] == 1){
            ++dem;
        }
    }
    cnt += 4-dem;
    // dequy de di chuyen
    for(int k = 0; k < 4; k++){
        int i1 = i + x[k];
        int j1 = j + y[k];
        if( i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 1){
            dq(i1, j1);
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m ; j++){
            cin >> a[i][j];
            b[i][j] = a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1 ; j <= m; j++){
            if(a[i][j]){
                cnt = 0;
                dq(i, j);
                cout << cnt << " ";
            }
        }
    }
    
    return 0;
}