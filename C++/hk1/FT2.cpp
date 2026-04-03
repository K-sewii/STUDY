#include <bits/stdc++.h>
int dem[100];
using ll = long long;
using namespace std;
    int main(){
        int n; cin >> n;
        int a[n];
        for(int &x : a){
            cin >> x;
            dem[x % 28]++;
        }
        ll ans = 0;
        //truong hop dac biet la n chia 28 du 0
        //so du 14 thi no cong vao so du chinh no la 14 nen dem 2 lan 
        //to hop chap 2 cua n
        // cong 2 so trong tat ca so trong mang a
        ans += 1ll * dem[0] * (dem[0]-1)/2 + 1ll *dem[14] * (dem[14]-1)/2;
        for(int i = 1; i <=13; i++){
            //truong hop con lai la nhung so du tu 1 -> 13 
            // thi cong 2 so du sao cho = 28
            // vd du 1 thi cong so du (28-1) = 27
            //du 3 thi + (28-3) = 25
            ans += 1ll * dem[i] * dem[28-i];
        }
        cout << ans;
    return 0;
}