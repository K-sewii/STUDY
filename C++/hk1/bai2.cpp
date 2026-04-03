/*
Ho va ten: Pham Nguyen Minh Ky
MSSV: 3124411148
Lop: DCT124C5
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m; int a[10000][10000];
bool check(ll k){
    int can = sqrt(k) + 0.5; 
    //neu no la so co thap phan tu ,0 -> ,4 thi du + 0,5 no van la so nguyen ko thay doi do lam tron kieu int, con neu no la so thap phan tren ,5 thi no cap nhat len 1 don vi
    //dung de so sanh voi so k cu
    if(1ll* can * can == k){ 
        // ep kieu long long cho can*can de tranh tran so int
        return true;
    }
    return false;
}
void maxscp(){
    int lonnhat = INT_MIN;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(check(a[i][j])){
                // neu la so chinh phuong thi cap nhat bien lonnhat
                lonnhat = max(lonnhat, a[i][j]);
            }
        }
    }
    // neu bien lonnhat ma van con gia tri cu thi co nghia la ko co so chinh phuong trong ma tran
    if(lonnhat != INT_MIN){
        cout << "So chinh phuong lon nhat la: "<< lonnhat << endl;
    }
    else cout << "-1" << endl;
    return;
}

void sum_cot(){
    for(int i= 1; i <= m; i++){
        int sum = 0;
        // tao bien sum=0 o day de tinh tong tung cot
        for(int j = 1; j <= n; j++){
            sum += a[j][i];
        }
        cout << "Cot " << i << " co tong la: "<< sum << endl;
    }
    return;
}
void sum_hangi(int i){
    int sum = 0;
    for(int j = 1; j <= m; j++){
        sum += a[i][j];// chi duyet tu chi so j de tinh tong sum cua hang thu i
    }
    cout << "Hang nay co tong la: " << sum << endl;
    return;
}
void max_in_min(){
    int lonnhat = INT_MIN;//tao bien lonnhat de tinh max cua nhung phan tu nho nhat trong hang
    for(int i = 1; i <= n; i++){
        int nhonhat = INT_MAX;// tao bien nhonhat de tinh nhung phan tu nho nhat cua cot thu j
        for(int j = 1; j <= m; j++){
            nhonhat = min(nhonhat, a[i][j]);
        }
        lonnhat = max(lonnhat, nhonhat);// tinh max cua nhung phan tu nho nhat trong hang
    }
    cout << "Phan tu lon nhat trong cac phan tu nho nhat cua moi hang la: " << lonnhat << endl;
    return;
}
int main(){
    cout << " Nhap m va n : ";
    cin >> m >> n;
    swap(m, n);
    cout << " Nhap ma tran can tinh toan : " << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1 ; j <= m; j++){
            cin >> a[i][j];
        }
    }
    cout << endl;
    maxscp();
    sum_cot();
    int x;
    cout << "Hay nhap hang ma ban can tinh tong: ";
    cin >> x ;
    sum_hangi(x);
    max_in_min();
    return 0;
}