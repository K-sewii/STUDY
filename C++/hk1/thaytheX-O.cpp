#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[500][500];
pair<int, int> p[4] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0}};//cung co the dung mang x, y de dequy
void dq(int i, int j){
    a[i][j] = '*';
    for(int k = 0; k < 4; k++){
        int i1 = i + p[k].first, j1 = j + p[k].second;
        if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 'O'){
            dq(i1, j1);
        }
    }
}
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }// khai bao i = j = 0 de khi dequy no ko nhay ra ngoai ma tran
    }
    for(int i = 1; i <= n; i++){
        if(a[i][1] == 'O') dq(i, 1);
        if(a[i][m]=='O') dq(i, m);//de quy '*' nhung phan tu nam ngoai bien
    }
    for(int j = 1; j <= m; j++){
        if(a[1][j]=='O') dq(1, j);
        if(a[n][j]=='O') dq(n, j);//nhu tren
    }
    cout << endl;
    for(int i = 1; i <= n; i++){
        for( int j = 1; j <= m; j++){
            if(a[i][j] != '*'){
                cout << "X" << " ";//neu != * thi nó nằm trong biên nên chắc chắn 100% dc bao phủ bởi các ký tự X nên chuyển * thành X( lúc đầu nó là O)
            }
            else cout << "O" << " ";// nếu nó là * thì nó là những phần tử O nhưng nằm ngoài biên vì thế ko dc bao phủ bởi các phân tử X xung quanh nên vẫn giữ nguyên O
        }
        cout << endl;
    }
}
int main(){
    solve();
    return 0;
}