#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc; cin >> tc;
    while(tc--){
        int n ,m; cin >> n >> m;
        int a[n][m];
        for(int i = 0; i < n; i++){
            for(int j =0; j < m; j++){
                cin >> a[i][j];
            }
        }
        for(int i = 1; i < n; i++){ // do dong i = 0 giu nguyen nen duy tu i = 1
            for(int j = 0; j < m; j++){
                if(j == 0){
                    a[i][j] += max(a[i-1][j], a[i-1][j+1]);//neu cot j = 0 thi tim gia tri lon nhat cua 2 so o tren roi cong don
                }
                else if(j == m - 1){
                    a[i][j] += max(a[i-1][j], a[i-1][j-1]);// neu cot j o cuoi cung thi cung cong don 2 so o tren
                }
                else a[i][j] += max(a[i-1][j-1], max(a[i-1][j], a[i-1][j+1]));// truong hop con lai la a[i][j] o giua thi tim gia tri lon nhat cua 3 phan tu tren no
            }
        }
        cout << *max_element(a[n-1], a[n-1] + m);// cout ra gia tri lon nhat cua hang cuoi cung
        // int res = INT_MIN;
        // for(int i = 0; i < m; i++){
        //     res = max(res, a[i][j];)       
        // }
        // 2 cach de cout ra gia tri lon nhat
    }
    return 0;
}