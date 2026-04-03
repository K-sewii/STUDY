#include <bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin >> s;
    vector<int> v;
    for(int i = 0; i < s.size(); i++){
        //luu nhung phan tu '['
        if(s[i] == '[') v.push_back(i);
    }
    int cnt = 0, trace = 0, res = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '['){
            cnt++; trace++;
        }
        else if(s[i] == ']'){
            cnt--;
        }
        if(cnt < 0){
            // so thao tac, tai vi chi dc hoan doi nhung phan tu ke ben
            res += v[trace] - i;
            swap(s[i], s[v[trace]]);
            cnt = 1; // de sau khi swap thi tinh la hop le
            ++trace; // de tiep tuc tinh so thao tac tiep theo 
        }
    }
    cout << res << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}