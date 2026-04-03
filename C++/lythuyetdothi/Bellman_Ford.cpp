#include <bits/stdc++.h>
using namespace std;
//O(V*E)

struct edge{
    int x, y, w;
};

int n, m;
vector<edge> dscanh;
int d[1000001];

void nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        dscanh.push_back({x, y, w});
    }
}

void Bellman_Ford(int s){
    for(int i = 1; i <= n; i++){
        d[i] = 1e9;
    }
    d[s] = 0;

    // Bellman_Ford chi can n-1 vong lap
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m; j++){
            edge tmp = dscanh[j];
            int x = tmp.x, y = tmp.y, w = tmp.w;
            if(d[x] < 1e9){
                d[y] = min(d[y], d[x] + w);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << d[i] << " ";
    }
    // check chu trinh am
    /*
        for(int i = 0; i < m; i++){
            edge tmp = dscanh[i];
            int x = tmp.x, y = tmp.y, w = tmp.w;
            if( d[x] < 1e9 && d[x] + w < d[y]){
                // tuc la co chu trinh am anh huong
                cout << 1;
            }
        }
        cout << 0;
    */
}

int main(){
    nhap();
    Bellman_Ford(1);
    return 0;
}