#include <bits/stdc++.h>
using namespace std;

int X[101], n, res;
int a[101][101];
int vis[101], nhonhat = 1e9;
void inp(){
    memset(vis, 0, sizeof(vis));
    cin >> n;
    for(int i = 1 ; i <= n; i++){
        for(int j = 1; j <= n ; j++){
            cin >> a[i][j];
            if(a[i][j]){
                nhonhat = min(nhonhat, a[i][j]);
            }
        }
    }
}
int ans = 1e9;
void Try(int i){
    for(int j = 2; j <= n; j++){
        if(!vis[j]){
            X[i] = j; // thanh pho thu i la j
            vis[j] = 1;
            res += a[X[i]][X[i-1]];
            if(i == n){
                ans = min(ans, res + a[X[n]][1]);
            }
            else if(res + nhonhat * (n - i + 1) < ans){
                Try(i+1);
            }
            vis[j] = 0;
            res -= a[X[i]][X[i-1]];
        }
    }
}
int main(){
    X[1] = 1;
    inp();
    Try(2);
    cout << ans << endl;
    return 0;
}