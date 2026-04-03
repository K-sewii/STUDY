#include <bits/stdc++.h>
using namespace std;
int cnt[5];// de cap nhat count cua cac truong hop dac biet
int first_pos(int a[], int l, int r, int x){
    int res = -1;
    while( l <= r ){
        int m = (l+r)/2;
        if(a[m] > x){
            res = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    return res;
}
int count(int y[], int m, int x){
    if(x == 0) return 0;
    if(x == 1) return cnt[0];//neu x = 1 thi truong hop thoa man la nhung phan tu 0 xuat hien trong mang y
    // neu x != 0,1 thi tat ca nhung phan tu 0,1 trong y deu thoa man
    long long ans = cnt[0] + cnt[1];
    // auto it = upper_bound(y, y+m, x);//tim phan tu > x trong mang y
    // ans += (y+m)-it;
    int l = first_pos(y, 0, m-1, x);
    if(l != -1 ){
        ans += m - l;
    }
    if( x == 2){
        ans -= cnt[3] + cnt[4];
    }
    if ( x == 3){
        ans += cnt[2];
    }
    return ans;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int a[n], b[m];
        for(int &x:a)cin >> x;
        for(int i = 0; i < m; i++){
            cin >> b[i];
            if(b[i] <= 4){
                cnt[b[i]]++;
            }
        } 
        sort(b, b+m);
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += count(b, m, a[i]);
        }
        cout << ans << endl;
        memset(cnt, 0, sizeof(cnt));
    }
    return 0;
}