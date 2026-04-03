#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        int a[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> a[i][j];
            }
        }
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[a[0][i]] = 1;//danh dau su xuat hien cua cac con so trong hang dau tien
    }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mp[a[i][j]] == i) //tang gia tri cua so lan xuat hien cua 1 phan tu trong 1 hang, tranh truong hop tang gia tri map trong khi 2 phan tu giong nhau xuat hien chung 1 hang
                    mp[a[i][j]]++;// vi du neu hang i = 1 va co 1 phantu 2 thi mp++ nen neu xet lai phan tu 2 trong hang do thi bi sai dieu kien 2 == 1(i) => false           
            }
        }
        int cnt = 0;
        for(auto it : mp){
            if(it.second == n){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}