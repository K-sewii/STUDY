#include <bits/stdc++.h>
using namespace std;
int n, a[100], ok, k;
void khoitao(){
    for(int i = 1; i <= n; i++){
        a[i] = 0;
    }
}
void sinh(){
    int i = n;
    while(i >= 1 && a[i] == 1){
        a[i] = 0;
        --i;
    }
    if(i == 0){
        ok = 0;
    }
    else
    {
        a[i] = 1;
    }
}
bool check(){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        cnt += a[i];
    }
    return cnt == k;
}
void hv(){
    int i = n - 1;
    while(i >= 1 && a[i] > a[i + 1] ){
        --i;
    }
    if( i == 0){
        ok = 0;
    }
    else{
        int j = n;
        while( a[j] < a[i] ) --j; 
        swap(a[j], a[i]);
        reverse(a + i + 1, a + n + 1);
    }

}
void nCk(){
    int i = k;
    while(i >= 1 && a[i] == n - k + i){
        --i;
    }
    if(i == 0){
        ok = 0;
    }
    else{
        a[i]++;
        for(int j = i + 1; j <= k; j++){
            a[j] = a[j-1] + 1;
        }
    }
}
void lap_nAk(){
    int i = k; 
    while(i >= 1 && a[i] == n){
        --i;
    }
    if(i == 0){
        ok=0;
    }
    else{
        a[i]++;
        for(int j = i + 1; j <= k; j++){
            a[j] = 1;
        }
    }
}
int main(){
    cin >> n >> k;
    ok = 1;
    for(int i = 1; i <= k; i++){
        a[i] = 1;
    }
    while(ok){
        // // if(check())
        // //{
        //     for(int i = 1; i <= n; i++){
        //         cout << a[i];
        //     }
        //     cout << endl;
        // //}    
        // sinh();
        for(int i = 1; i <= k; i++){
            cout << a[i];
        }
        cout << endl;
        lap_nAk();
    }
    return 0;
}