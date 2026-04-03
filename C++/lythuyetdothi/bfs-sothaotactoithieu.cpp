#include <bits/stdc++.h>
using namespace std;

int bfs(int s, int t){
    set<int> se; // danh dau da tham
    queue<pair<int, int>> q;
    q.push({s, 0}); // second la so thao tac
    // so s voi 0 thao tac
    se.insert(s);
    while(!q.empty()){
        pair<int, int> top = q.front(); q.pop();
        if(top.first - 1 == t || top.first * 2 == t) return top.second + 1;
        if(top.first == t) return top.second;
        int x = top.first;
        if(x > 1 && !se.count(x-1)){
            q.push({x-1, top.second + 1});
            se.insert(x-1);// da tham || da xet dinh x-1
        }
        if(x < t && !se.count(x*2)){
            q.push({x*2, top.second + 1});
            se.insert(2*x);
        }
    }
}

int main(){
    int q; cin >> q;
    while(q--){
        int s, t; cin >> s >> t;
        cout << bfs(s, t) << endl;
    }
    return 0;
}