#include <bits/stdc++.h>
using namespace std;
#define ll long long
int solve(int s, int t){
    queue<pair<int, int>> q;
    // 1: luu gia tri
    // 2: luu so thao tac
    set<int> se;
    se.insert(s);//tao set de ko tinh vao queue nhung phan tu trung nhau
    q.push({s, 0});
    while(!q.empty()){
        pair<int, int> idx = q.front();
        q.pop();
        if( idx.first == t ) return idx.second;
        // neu gia tri bien idx = t( gia tri can tim ) thi in ra so thao tac dang co
        if( idx.first * 2 == t || idx.first - 1 == t) return idx.second + 1;
        // neu gia tri bien idx * 2 va idx -1 == t thi thao tac cong 1
        if( se.find(idx.first * 2) == se.end() && idx.first < t){
            // check dieu kien de bien ko lap lai va cho add them vao queue
            q.push({idx.first * 2, idx.second + 1});
            se.insert(idx.first * 2);
        }   
        if( se.find(idx.first - 1) == se.end() && idx.first > 1){
            q.push({idx.first - 1, idx.second + 1});
            se.insert(idx.first - 1);
        }
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        int s, t; cin >> s >> t;
        cout << solve(s, t) << endl;
    }
    return 0;
}