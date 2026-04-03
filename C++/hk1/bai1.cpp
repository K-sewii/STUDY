/*
Ho ten: Pham Nguyen Minh Ky
MSSV: 3124411148
Lop: DCT124C5
*/
#include <bits/stdc++.h>
using namespace std;
int n, cnt[1000];
void MAX_MIN(int a[]){
    int lonnhat = INT_MIN;
    int nhonhat = INT_MAX;
    for(int i = 0; i < n; i++){
        lonnhat = max(lonnhat, a[i]);
        nhonhat = min(nhonhat, a[i]);
        // cap nhat 2 bien lonnhat va nho nhat de tim gia tri lan luot la lon nhat trong mang va nho nhat trong mang
    }
    cout << "Gia tri lon nhat va nho nhat la : " << lonnhat << " va " << nhonhat << endl;
    return;
}
int nt(int m){
    for(int i = 2; i <= sqrt(m); i++){
        if( m % i == 0) return 0;
    }
    return m > 1;
    // ham tim so nt
}
void sum_nt(int a[]){
    int sum = 0;
    for(int i = 2; i < n; i++){
        if(nt(a[i])){
            sum += a[i];
            // neu a[i] dang duyet la so nt thi cong don vao bien sum
        }
    }
    cout << "Tong cac so nguyen to can tim la : " << sum << endl;
    return;
}
void dem(int a[]){
    for(int i = 0; i < n; i++){
        if(cnt[a[i]] != 0)
            cout << " Gia tri " << a[i] << " co so lan lap lai la : " << cnt[a[i]] << " lan " << endl; // in lan luot cac gia tri dang duoc duyet va in ra so lan no lap lai
        cnt[a[i]] = 0; // tranh truong hop bi in lap
    }
    cout << endl;
    return;
}
void sapxep(int a[]){
    for(int i = 0; i < n - 1; i++){
        for(int j = i+1; j < n ; j++){ 
            if(a[i] <= a[j]){
                // neu phan tu a[i] ma nho hon phan tu a[j] thi hoan doi vi tri cho mang sap xep theo chieu giam dan
                swap(a[i], a[j]);
            }
        }
    }
    cout << " Day theo chieu giam dan la: ";
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return;
}
void xoapttrongmang(int a[]){
    int new_n = n; // tao bien n moi de luu size cua mang sau khi tru nhung phan tu trung nhau
    for(int i = 0; i < new_n; i++){
        for(int j = i + 1; j < new_n; j++){
            if(a[j] == a[i]){
                //neu co pt trung nhau thi chen nhung phan tu dang sau len pt bi trung`
                while(j < new_n - 1){
                    a[j] = a[j + 1];
                    ++j; //tang len 1 don vi de vong lap while khong bi vo han va no se in chen nhung phan tu dang sau
                }
                --new_n;// tru new_n 1 don vi sau moi lan phat hien a[i] == a[j] de khi in ra khong bi in nham nhung phan tu chen len o cuoi
                --j; //check lai
            }
        }
    }
    cout << "Day sau khi da duoc xoa nhung phan tu trung nhau la: ";
    for(int i = 0; i < new_n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return;
}
int main(){
    cout << " So phan tu can duoc tinh la: ";
    cin >> n; 
    int a[n];
    cout << " Nhap nhung phan tu tren: ";
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++; // danh dau nhung phan tu nay xuat hien 1 lan 
    }
    MAX_MIN(a);
    sum_nt(a);
    dem(a);
    sapxep(a);
    xoapttrongmang(a);
    return 0;
}