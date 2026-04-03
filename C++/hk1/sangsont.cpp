#include <iostream>
#include <math.h>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;
int prime[1000001];
void sieve(){
    //Cho mang deu laf so nguyento
    for (int i = 0; i <= 1000000; i++) 
        prime[i] = 1;
        //Sau do loai thu cong 0 va 1 
        prime[0] = prime[1] =0;
        //sang vong lap for xet can bac 2 cua mang
        for (int i = 2; i <= 1000; i++){
            if (prime[i]){
                for (int j = i*i; j <= 1000000; j+=i){
                    prime[j] = 0;//ko phai la so ngto nua
                }
            }
        }
}
int main(){
    sieve();
    int n; cin >> n;
    vector<int> v;
    for(int i = 2; i <= n; i++){
        if(prime[i]) v.push_back(i);
    }
    for(int i = 1; i < v.size() - 1; i++){
        int agv = (v[i-1] + v[i+1])/2;
        if(agv <= n && agv == v[i] && prime[agv] && (v[i-1] + v[i+1]) % 2 == 0){
            cout << agv << endl;
        }
    }
    return 0;
}