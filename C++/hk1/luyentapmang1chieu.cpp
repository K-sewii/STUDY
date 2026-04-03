#include <bits/stdc++.h>
using namespace std;
int f[1001];
void test(){
    int fibo[20];
    fibo[0]=0; fibo[1]=1;
    for ( int i = 2; i <= 19; i++){
        fibo[i]=fibo[i-1]+fibo[i-2];
    } 
    for ( int i = 0; fibo[i]<=1000; i++){
            f[fibo[i]] = 1;
    }
}
#define MOD 1000000007
int main(){
    test();
    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        int a[n];
        for (int &x : a) cin >> x;
        int sum = 0;
        for ( int i = 0; i < k; i++){
            sum += a[i];
        }
        int res = sum, thutu = 0;
        for (int i = k; i < n; i++){
            sum = sum - a[i-k] + a[i];
            if (res < sum){
                res = sum;
                thutu = i - k + 1;
            }
        }    
        for ( int i = 0; i < k; i++){
            cout << a[thutu + i] << "\n";
        }
    }
    return 0;
}