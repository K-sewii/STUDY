#include <bits/stdc++.h>
using namespace std;
int n, m, x, k;
vector<int> ke[1001];
bool visited[1001];
vector<int> kq;
 
void input(){
    cin >> n >> x;
    for(int i = 0; ; i++){
        int x, y, z; cin >> x; if (x == -1) break;
        cin >> y >> z;
        ke[x].push_back(y);
        ke[y].push_back(x);
        ke[x].push_back(z);
        ke[z].push_back(x);
        
    }
    for(int i = 1; i <= n; i++){
        sort(ke[i].begin(), ke[i].end());
    }
}
void dfs(int u){
    visited[u] = true;
    for(int v : ke[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}
int main(){
    input();
    dfs(x);
    visited[x] = false;
    for(int i = 1; i <= n ; i++){
        if(visited[i]){
            kq.push_back(i);
        }
    }
    cout << kq.size() << endl;
    for(int x : kq){
        cout << x << " ";
    }
}