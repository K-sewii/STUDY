#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> v[n];
    for ( int i = 0; i < n; i++){
        int m; cin >> m;
        for (int j = 0; j < m; j++){
            int x; cin >> x;
            v[i].push_back(x);
        }
    }
    for ( int i = 0; i < n; i++){
        for ( int j = 0; j < v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}