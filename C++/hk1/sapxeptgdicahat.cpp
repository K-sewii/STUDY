#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b){
    return (a.second) < (b.second);
}
//sap xep theo thoi gian ket thuc tang dan
int main(){
    int n; cin >> n;
    vector<pair<int, int>> v(n);//khai bao 1 vector voi kieu du lieu pair luu tru thoi gian bat dau va ket thuc
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), cmp);
    cout << "\n";
    int tmp = v[0].second; //luu tru 1 bien thoi gian ket thuc cua buoi luu dien dau tien
    int cnt = 1;//luu cnt bang 1 tai vi show dien dau tien luon luon thuc hien dc
    for(int i = 1; i < n; i++){
        if(v[i].first > tmp){//neu tg bat dau cua show dien thu 2 lon hon tg ket thuc cua show dien dau thi ++cnt va cap nhat tmp( de vong lap tiep tuc )
            ++cnt;
            cout << v[i].first << " " << v[i].second;
            cout << endl;
            tmp = v[i].second;
        }
    }
    cout << cnt << endl;

    return 0;
}