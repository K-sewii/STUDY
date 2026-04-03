#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int a[n];
        int d = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] <= k) ++d; // tinh tat cac phan tu thoa dieu kien <= k 
        }
        //tao cau hinh dau tien
        int cnt = 0;
        for(int i = 0; i < d; i++){
            // neu phan tu a[i] <= k cho truoc thi tinh cnt( bien de tinh so pt lien nhau lon nhat trong mang)
            if(a[i] <= k) cnt++;
        }
        int ans = cnt;
        for(int i = d; i < n; i++){
            // check dieu kien neu phan tu a[i-d] ( phan tu nam ngoai cua so sliding window ) ma dung dieu kien thi --cnt
            if(a[i-d] <= k) --cnt;
            //check dieu kien phan tu dc xet ( a[i] ) dung dieu kien <= k thi ++cnt
            if(a[i] <= k) ++cnt;
            // muc dich tim phan tu lon nhat trong cua so sliding
            ans = max(ans, cnt);
        }
        // d - ans la in ra so phan tu can hoan vi bang cach lay nhung phan tu nho nhat trong mang tru di nhung phan tu nho nhat tinh trong cua so sliding
        cout << d - ans << endl;
    }
    return 0;
}