#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void Try(int tu, int mau){
    if(mau % tu == 0){
        cout << "1/" << mau/tu << endl;
        return;
    }
    
    ll x = mau/tu + 1;
    cout << "1/" << x << " + ";
    ll tumoi = tu*x - mau;
    ll maumoi = mau*x;
    Try(tumoi, maumoi); 
}
int main(){
    Try(2, 3);
    return 0;
}