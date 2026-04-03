#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc; cin >> tc;
    while (tc--){
        int n, x; cin >> n >> x;
        int a[n];
        for ( int &x : a) cin >> x;
        int l = 0, res = 1e9; int sum = 0;
        for ( int r = 0; r < n; r++){
            sum += a[r];
            while ( sum > x){
                res = min(res, r - l + 1);
                sum -= a[l]; l++;
            }
        }
        if ( res == 1e9) cout << "-1\n";
        else cout << res << endl;
    }   
    return 0;
}