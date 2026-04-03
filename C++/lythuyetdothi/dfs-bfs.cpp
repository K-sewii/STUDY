#include <bits/stdc++.h>
using namespace std;
int n, m, s, t;
vector<int> ke[1001];
bool visited[1001];
int parent[1001];
vector<int> topo;
int indegree[1001];
int color[1001];
int height[1001];

void input(){
    cin >> n >> m;// danh sach canh
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
        // cho do thi vo huong
    }
    for(int i = 1; i <= n; i++){
        sort(ke[i].begin(), ke[i].end());
    }// de chac chan rang dfs se di tu dinh nho den lon
    memset(visited, false, sizeof(visited));
    memset(color, 0, sizeof(color));
}
void dfs(int u){
    // cout << u << " ";
    visited[u] = true;
    for(int v : ke[u]){
        if(!visited[v]){
            parent[v] = u;
            dfs(v);
        }
    }
    // o day la nhung phan tu dc duyet cuoi cung 
    // giong nhu ap dung backtrack
    topo.push_back(u);
}
void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        cout << v << " ";
        for(int x : ke[v]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        }
    }
}
void checklienthongthanhphan(){
    int dem = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
            dem++;
        }
    }
    cout << dem << endl;
}
void timduongdingannhat_dfs(){
    input();
    dfs(s);
    if(!visited[t]){
        cout << "NO\n";
    }
    else{
        vector<int> path;
        while(t != s){
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(s);
        reverse(begin(path), end(path));
        for(int x : path){
            cout << x << " ";
        }
    }
}
//topo = dfs co 1 bat loi la khi do thi co chu trinh thi dong nghia khong co sap xep topo 
void topo_sort_dfs(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        // do thi co huong
        ke[x].push_back(y);
    }
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= n; i++){
        // duyet cac dinh
        if(!visited[i]){
            dfs(i);
        }
    }
    reverse(begin(topo), end(topo));
    for(int x : topo){
        cout << x << " ";
    }
}
// topo bang bfs duyet dc ca chu trinh(deadlock)
void topo_sort_bfs(){
    cin >> n >> m;
    memset(indegree, 0, sizeof(indegree));
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        indegree[y]++;
    }
    memset(visited, false, sizeof(visited));
    // duyet bfs(kahn)
    queue<int> q;
    for(int i = 1; i <= n ;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(int v : ke[u]){
            //giam 1 cac bam bac vao de khi duyet tiep tuc cac dinh co bam bac vao la 0 
            indegree[v]--;
            if(indegree[v] == 0) q.push(v);
        }
    }
}
// cho do thi vo huong
bool kiemtrachutrinh_dfs(int u, int par){
    visited[u] = true;
    for(int v : ke[u]){
        if(!visited[v]){
            if(kiemtrachutrinh_dfs(v, u)) return true;
            // can than ko dc dung return chutrinh_dfs(v, u) vi no se xet het vong for roi ket luan la false ma ko xet cac v khac
        }
        // dinh v dc tham, nhung v khong la cha truc tiep cua u 
        else if(v != par){
            return true;// canh nguoc u, v
        }
    }
    return false;
}
// cho do thi vo huong
void chutrinh(){
    input();
    bool ok = false;
    for(int i = 1; i <= n; i++){
        if(!visited[i] && kiemtrachutrinh_dfs(i, 0)){
            // tai vi no co the co nhung dinh roi rac
            ok = true; break;
        }
    }
    cout << ok << endl;
}
// cho do thi vo huong
bool chutrinh_bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int x : ke[v]){
            if(!visited[v]){
                q.push(x);
                visited[x] = true;
                parent[x] = v;
            }
            // v da dc tham roi 
            else if(x != parent[v]){
                return true;
            }
        }
    }
    return false;
}

// kiem tra chu trinh doi voi do thi co huong bang dfs
// trang : 0, xam: 1, den : 2
bool chutrinh_dtcohuong_dfs(int u, int par){
    // bo bien par cung khong sao
    color[u] = 1;
    // dang tham
    for(int v : ke[u]){
        if(color[v] == 0){
            if(chutrinh_dtcohuong_dfs(v, u)) return true;
        }
        // neu dinh da tham va no check v co color == 1  
        else if(color[v] == 1){
            return true;
        }
    }
    color[u] = 2; // giong nhu backtrack, ngu y danh dau diem nay da xet xong (color den)
    return false;
}

bool chutrinh_dtcohuong_bfs(){
    cin >> n >> m;
    memset(indegree, 0, sizeof(indegree));
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        indegree[y]++;
    }
    memset(visited, false, sizeof(visited));
    // duyet bfs(kahn)
    queue<int> q;
    for(int i = 1; i <= n ;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    int cnt = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cnt++;
        for(int v : ke[u]){
            //giam 1 cac bam bac vao de khi duyet tiep tuc cac dinh co bam bac vao la 0 
            indegree[v]--;
            if(indegree[v] == 0) q.push(v);
        }
    }
    if( cnt == n ) return false;
    else return true;
}

//kiem tra do thi co 2 phia ko
// gan 2 mau bat ky, tai vi khi no la do thi 2 phia thi mau cua tung canh phai xen ke~
// mau 1: Do
// mau 2 : Xanh
bool dothi2phia(int u, int par){
    color[u] = 3 - color[par];
    for(int v : ke[u]){
        if(color[v] == 0){
            // de co mau xen ke~ 
            if(!dothi2phia(v, u)) return false;
        }
        else if(color[v] = color[u]){
            return false;
        }
    }
    return true;
}
void checkdothi2phia(){
    input();
    bool ok = false;
    color[0] = 2; // vay 3-2 = 1 no co mau do 
    for(int i = 1; i <= n ; i++){
        if(color[i] == 0){
            if(dothi2phia(i, 0));
                ok = true;
        }
    }
    cout << ok << endl;
}

void heightdothi(int u, int h){
    visited[u] = true;
    height[u] = h;
    for(int v : ke[u]){
        if(!visited[v]){
            heightdothi(v, h+1);
        }
    }

}
// check co phai la cay ko
void check_cay(){
    // cay ko co chu trinh va phai lien thong
    input();
    if(kiemtrachutrinh_dfs(1, 0)){
        cout << 0 << endl;
    }
    else{
        for(int i = 1; i <= n ;i++){
            if(!visited[i]){
                cout << 0 << endl; return;
            }
        }
        cout << 1 << endl;
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    return 0;
}