#include <bits/stdc++.h>
using namespace std;

const int maxn = 1001;
struct canh{
    int x, y, w;
};

int n, m; // n: so luong dinh, m : so luong canh
vector<pair<int, int>> ke[maxn]; // dung pair de luu trong so tung canh
bool used[maxn]; //used[i] = true : i thuoc tap MST, used[i] = false : i thuoc tap v
int parent[maxn], d[maxn];

void nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        ke[x].push_back({y, w});
        ke[y].push_back({x, w});
        // do thi vo huong
    }
    memset(used, false, sizeof(used));
    for(int i = 1; i <= n ;i++) d[i] = INT_MAX;
}

void prim(int u){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // luu trong so nho nhat
    vector<canh> MST;
    int res = 0;
    q.push({0, u});
    while(!q.empty()){
        pair<int, int> top = q.top(); q.pop();
        int dinh = top.second, trongso = top.first;

        if(used[dinh]) continue;// neu dinh trong tap MST thi bo qua
        res += trongso;
        used[dinh] = true;// dua dinh vao tap MST
        if(u != dinh){
            MST.push_back({parent[dinh], dinh, trongso});
        }
        // duyet tat ca cac dinhke
        for(auto it: ke[dinh]){
            int y = it.first, w = it.second;
            if(!used[y] && w < d[y]){
                q.push({w, y});
                d[y] = w; // luu canh ngan nhat(trong so)
                parent[y] = dinh;
            }
        }
    }
    cout << "Do dai cay khung cuc tieu :" << res << endl;
    for(auto it : MST){
        cout << it.x << " " << it.y << " " << it.w << endl;
    }

}
int main(){
    nhap();
    prim(1);
    return 0;
}