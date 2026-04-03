#include <bits/stdc++.h>
using namespace std;

//dieu kien chi ap dung khi do thi co trong so duong (w+)
const int maxn = 100001;
int n, m;
vector<pair<int, int>> adj[maxn]; // pair do luu torng so w
int d[maxn];// chi phi di duong

void nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
    }
}

#define pii pair<int,int> 

void dijktra(int s){
    for(int i = 1; i <= n; i++){
        d[i] = 1e9; // gan d[i] cua moi dinh la vo cuc
        // tuc la gan cac dinh ko phai dinh goc co chi phi la vo cung
    }
    d[s] = 0;// dinh goc co chi phi di duong la 0
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while(!q.empty()){
        pii top = q.top(); q.pop();
        int u = top.second;
        int dw = top.first;
        if(dw > d[u]) continue; // do d[u] da la truong hop tot nhat 
        for(auto it : adj[u]){
            int v = it.first;
            int w = it.second;
            // if(d[v] > d[u] + w){
            //     d[v] = d[u] + w;
            //     q.push({d[v], v});
            // }
            d[v] = min(d[v], d[u] + w);
            q.push({d[v], v});
        }
    }
    for(int i = 1; i <= n; i++){
        cout << d[i] << " ";
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    nhap();
    dijktra(1);
    return 0;
}