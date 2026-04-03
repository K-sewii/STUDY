#include <bits/stdc++.h>
using namespace std;
int n, a[100], cnt, ok;
//tao cau hinh dau tien
void khoitao(){
    cnt = 1;//so phan tu trong mang
    a[1] = n;
}
void sinh(){
    int i = cnt;//tao bien i de tim phan tu ma a[i] khac 1
    while( i >= 1 && a[i] == 1){
        --i;
    }
    if(i == 0){
        ok = 0;
    }
    else{
        a[i]--;//tru 1 don vi
        int phancancong = cnt - i + 1;// cnt - i la phan co gia tri = 1, + 1 de + them gia tri da tru di
        int q = phancancong/a[i];//coi a[i] sau khi tru gap bao nhieu lan so can cong
        int r = phancancong%a[i];//tim phan du lai sau khi duyet q
        cnt = i; // cap nhat bien cnt tai vi tri a[i] != 1 de duyet va thuc hien nhung con so dang sau
        if(q){ // neu ton tai so gap bay nhieu lan a[i] thi moi thuc hien
            for(int j = 1; j <= q; j++){
                cnt++;
                a[cnt] = a[i];
            }
        }
        // coi so can cong gap bao nhieu lan a[i] thi in ra so do bay nhieu lan
        //sau khi in xong thi in phan du con lai
        if(r){
            cnt++; a[cnt] = r;
        }
    }
}
int main()
{
    cin >> n;//nhap vao so n can phan hoach
    ok = 1;
    khoitao();
    while(ok)
    {
        for(int i = 1; i <= cnt; i++){//bien cnt coi nhu so phan tu thu k
            cout << a[i] << " ";
        }
        cout << endl;
        sinh();
    }
    return 0;
}