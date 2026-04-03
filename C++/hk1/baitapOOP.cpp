#include <bits/stdc++.h>
using namespace std;
class KhachHang{
    private:
        string hoTen, diaChi, maKH, soDienThoai;
    public:
        void nhapthongtinKH(){
            getline(cin, hoTen);
            getline(cin, diaChi);
            cin >> maKH >> soDienThoai;
        }
        void inthongtinKH(){
            cout << hoTen << diaChi << maKH << soDienThoai;
        }

};
class CongToDien : public KhachHang{
    private:
        int dongDien, dienAp, tanSo, chiSoDau, chiSoCuoi;
    public:
        CongToDien(){
            dongDien = dienAp = tanSo = chiSoDau = chiSoCuoi = 0;
        }
        void nhapttCongTo(){
            KhachHang::nhapthongtinKH();
            cin >> dongDien >> dienAp >> tanSo >> chiSoDau >> chiSoCuoi;
        }
        void inttCongTo(){
            KhachHang::inthongtinKH();
            cout << dongDien << dienAp << tanSo << chiSoCuoi << chiSoCuoi;
            cout << endl;
        }
        friend int TienDien(CongToDien a){
            if(a.dongDien >0 && a.dongDien <= 100){
                return a.dongDien * 1500;
            }
            else if(a.dongDien > 100 && a.dongDien < 151){
                return (a.dongDien-100)*2000 + 100*1500;
            }
            else if(a.dongDien > 150 && a.dongDien < 251){
                return (a.dongDien - 150) * 2700 + 100*1500 + 50*2000;  
            }
            else if(a.dongDien > 250){
                return (a.dongDien -250) * 3000 + 50*2700 + 50*2000 + 100*1500;
            }
            else{
                return -1;
            }
        }
        friend void KHcosotientraMax(CongToDien a[], int n){
            int lonnhat = 0;
            for(int i = 0; i < n; i++){
                int tiendien = TienDien(a[i]); 
                lonnhat = max(lonnhat, tiendien);
            }
            cout << lonnhat << endl;
            return;
        }
};
int main(){
    int n; cin >> n;
    CongToDien a[n];
    for(int i = 0; i < n;i++){
        a[i].nhapttCongTo();
    }
    for(int i = 0; i < n;i++){
        a[i].inttCongTo();
        cout << TienDien(a[i]);
        cout << endl;
    }
    KHcosotientraMax(a, n);
    return 0;
}