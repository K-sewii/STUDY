#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

struct edge{
    int x, y, w;
};

int n, m;
vector<edge> dscanh;
int d[101][101];

void nhap(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i==j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    for(int i = 0; i < m; i++){
        int x, y , w; cin >> x >> y >> w;
        d[x][y] = w;
        d[y][x] = w; //neu do thi vo huong
    }

}


void Floyd(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n ;i++){
            for(int j = 1; j <= n; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
void solve(){
    int q; cin >> q;
    while(q--){
        int x, y; cin >> x >> y;
        cout << d[x][y] << endl;
    }
}
int main(){
    nhap();
    Floyd();
    solve();
    return 0;
}