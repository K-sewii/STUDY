#include <bits/stdc++.h>
using namespace std;

void sliding(){
    int n, k; cin >> n >> k;
    int a[n];
    for(int &x : a) cin >> x;
    deque<int> dq; // tap 1 queue 2 hang doi tinh sliding window
    for(int i = 0; i < k; i++){
        // tao cau hinh dau tien
        while(!dq.empty() && a[i] > a[dq.back()]){ 
            // tao vong lap de luu gia tri lon nhat trong so k cua so
            // neu queue co phan tu va so a[i] dang duyet lon hon chi so cuoi cung ( ko so sanh front vi chi so back coi nhu gioi han cua k slingding window) trong queue thi pop thang back
            // khong thi( a[i] be hon chi so back ) van push back chi so vao queue
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << a[dq.front()] << " "; // sau khi tao dc k cua so dau tien thi in ra phan tu lon nhat
    for(int i = k; i < n ; i++){
        // tao nhung cua so tiep theo
        if(dq.front() <= i-k){
            // xet front cua queue tai vi no dang la so lon nhat cua chi so truoc coi no con thuoc so k cua sliding window ko
            dq.pop_front();
        }
        while(!dq.empty() && a[i] > a[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
        cout << a[dq.front()] << " "; // in lan luot phan tu lon nhat sau moi lan duyet cua so thu k
    }
    return;
}
int main(){
    int t; cin >> t;
    while(t--){
        sliding();
    }
    return 0;
}