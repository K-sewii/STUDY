#include <bits/stdc++.h>
using namespace std;
int gcd( int a, int b){
    if ( b == 0 ) 
        return a;
        else return gcd(b, a%b);
}
int main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int a[n];
        for ( int &x : a) cin >> x;
        int res = 0;
        for ( int i = 0; i < n; i++){
            for ( int j = i + 1; j < n; j++){
                res = max(res, gcd(a[i], a[j]));
            }
        }
        cout << res;
    }
    return 0;
}