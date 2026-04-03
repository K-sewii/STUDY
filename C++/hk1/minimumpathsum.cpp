#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc; cin >> tc;
    while(tc--){
        int n ,m; cin >> n >> m;
        int a[n][m];
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }   
        //tao 1 mang de luu cac bien da cong don xong
        int s[n][m];
        for(int i = 0;i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j ==0) s[i][j] = a[i][j];
                else if(i == 0) s[i][j] = s[i][j-1] + a[i][j];
                else if(j == 0) s[i][j] = s[i-1][j] + a[i][j];
                else s[i][j] = min(s[i-1][j], s[i][j-1]) + a[i][j];
            }
        }
        cout << s[n - 1][m - 1] << endl;
    }
    return 0;
}