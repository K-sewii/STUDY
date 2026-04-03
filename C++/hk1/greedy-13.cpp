#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int d;
    string s;
    cin >> d >> s;
    int n = s.size();
    map<char, int> cnt;
    for(char x : s){
        cnt[x]++;
    }
    string res = string(n, ' ');
    vector<pair<char,int>> v;
    for(auto x : cnt){
        v.push_back(x);
    }   
    sort(begin(v), end(v), [](pair<char, int> a, pair<char, int> b) ->bool{
        return a.second > b.second;
    });
    bool ok = true;
    // bieu thuc lambda dinh nghia ham sort
    for(int i = 0; i < v.size(); i++){
        int pos = i;
        while(res[pos] != ' ') pos++;
        for(int k = 0; k < v[i].second; k++){
            //neu ko check dieu kien thi no se cong qua' n
            if( pos + k*d > n ){
                ok = false; break;
            }
            res[pos + k*d] = v[i].first;
        }
    }
    if(!ok){
        cout << "-1" << endl;
    }
    else cout << "1" << endl << res << endl;
    return;
}


int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}