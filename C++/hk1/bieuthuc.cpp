#include <bits/stdc++.h>
using namespace std;
int a[1001], x[1001], ok;

vector<vector<int>> chinhhop, hoanvi;
//chinh hop lap
// 1 : +, 2 : -, 3 : *
void CHL(int i){
    for(int j = 1; j <= 3; j++){
        x[i] = j;
        if( i == 4 ){
            vector<int> tmp(x+1, x + 5);
            chinhhop.push_back(tmp);
        }
        else{
            CHL(i+1);
        }
    }
}

// hoan vi
void init(){
    int a[] = {1, 2, 3, 4, 5}; //bien A B C D E
    do{
        vector<int> tmp(a, a + 5);
        hoanvi.push_back(tmp);
    }while(next_permutation(a, a + 5));
    CHL(1);
}

int main(){
    init();
    int t; cin >> t;
    while(t--){
        ok = false;
        for(int i = 1; i <= 5; i++){
            cin >> a[i];
        }
        for(auto it1 : hoanvi){
            for(auto it2 : chinhhop){
                int res = a[it1[0]]; //so A
                for(int k = 0; k < 4; k++){//duyet 4 o trong' trong A B C D E de no bang 23
                    if(it2[k] == 1){
                        res += a[it1[k+1]];
                    }
                    else if(it2[k] == 2){
                        res -= a[it1[k+1]];
                    }
                    else{
                        res *= a[it1[k+1]];
                    }
                }
                if(res == 23){
                    ok = true; break;
                }
            }
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}