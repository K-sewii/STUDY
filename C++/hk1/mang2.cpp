#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    for ( int j = 0; j < v.size() ; j++){
        cout << v[j] << " ";
    }
    return 0;
}