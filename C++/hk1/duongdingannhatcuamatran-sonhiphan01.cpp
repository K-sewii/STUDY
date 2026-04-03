#include <bits/stdc++.h>
using namespace std;
int a[1000][1000];
int d[1000][1000];// luu chi so cac buoc di toi thieu o start den end
pair<int, int> s, e; // luu chi so bat dau va ket thuc cua de yeu cau
int n, m;
int x[4] = {-1, 0, 0, 1};
int y[4] = {0, -1, 1, 0};
void input(){
    cin >> n >> m >> s.first >> s.second >> e.first >> e.second;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    memset(d, 0, sizeof(d)); // de reset mang d sau tung testcase
}
int solve(){
    queue<pair<int, int>> q;
    q.push({s.first, s.second});
    d[s.first][s.second] = 0;
    while(!q.empty()){
        pair<int , int> idx = q.front();
        q.pop();    
        for(int k = 0; k < 4; k++){
            int i1 = idx.first + x[k];
            int j1 = idx.second + y[k];
            if(i1 >= 0 && a[i1][j1] && j1 >= 0 && i1 < n && j1 < m){//check dieu kien roi loang ra 
                a[i1][j1] = 0; // de no ko bi loang nua ( ko bi lap vo han )
                d[i1][j1] = d[idx.first][idx.second] + 1; // cap nhat so buoc cua i1, j1 bang idx cu~ + 1
                if( i1 == e.first && j1 == e.second){ // neu chi so i1, j1 bang voi chi so dang tim thi in ra 
                    return d[i1][j1]; // hoac cung the return d[idx.first][idx.second] + 1; voi dieu kien lenh {d[i1][j1] = d[idx.first][idx.second] + 1;} phai o sau lenh if
                }
                q.push({i1, j1}); // de tat ca vao queue de tiep tuc loang ra
            }
        }
    }
    return -1;// neu ko tim duoc duong toi chi so dang tim de return thi se in ra -1
}
int main(){
    int t; cin >> t;
    while(t--){
        input();
        if(a[s.first][s.second] && a[e.first][e.second]){
            cout << solve() << endl;
        }
        else cout << " -1 ";
    }
    return 0;
}