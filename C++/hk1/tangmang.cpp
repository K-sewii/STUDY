#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc; cin >> tc;
    while (tc--){
        int n; cin >> n;
        int a[n];
        for (int &x : a) cin >> x;
        int cnt = 0;
        for ( int i = 1; i < n; i++){
            if (a[i-1] > a[i]){
                cnt += a[i-1]-a[i];
                a[i]=a[i-1];
            }
        }
        cout << cnt << endl;
    }
    return 0;
}