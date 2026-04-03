#include <bits/stdc++.h>
using namespace std;

const int maxn = 1001;

struct canh{
    int x, y, w;
};

int n, m;
int parent[maxn], sz[maxn];
vector<int> ke[maxn];
vector<canh> dscanh;


int find(int u){
    if(u = parent[u]) return u;
    else return parent[u] = find(parent[u]);
}
bool Union(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return false; // thuoc cung 1 tap hop
    // if(sz[u] > sz[v]){
    //     parent[v] = u;
    //     sz[u] += sz[v];
    // }
    // else{
    //     parent[u] = v;
    //     sz[v] += sz[u];
    // }
    if(sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    parent[v] = u;
    return true;

}

void INPUT(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y, w; cin >> x >> y >> w;
        dscanh.push_back({x, y, w});
    }
    for(int i = 1; i<= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}
void kruskal(){

    sort(begin(dscanh), end(dscanh), [](canh a, canh b) -> bool{
        return a.w < b.w;
    });
    int ans = 0;
    vector<canh> tree;
    for(int i = 0; i < m ; i++){
        if(tree.size() == n - 1) break;
        // neu trong luc hop canh( Union ) tao thanh chu trinh thi no tra ve false thi minh ko nhan
        // tai vi cay khung la cay ko co chu trinh va lien thong
        if(Union(dscanh[i].x , dscanh[i].y)){
            tree.push_back(dscanh[i]);
            ans += dscanh[i].w;
        }
    }
    if(tree.size() < n-1){
        cout << "Do thi khong lien thong !\n";
    }
    else{
        cout << "Do dai cay khung cuc tieu :" << ans << endl;
        for(auto it : tree){
            cout << it.x << " " << it. y << " " << it.w << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    INPUT();
    kruskal();

    return 0;
}