#include <bits/stdc++.h>
using namespace std;

int n, ok; 
string s;
vector<string> v;
void khoitao(){
    s = string(n , '6');
}
void next(){
    int i = n - 1;
    while( i >= 0 && s[i] == '8'){
        s[i] = '6'; i--;
    }
    if( i == -1) ok = 0;
    else s[i] = '8';
}
void init(){
    for(int i = 1; i <= 13; i++){
        n = i;
        khoitao();
        ok = 1;
        while(ok){
            string tmp = s;
            reverse(tmp.begin(), tmp.end());
            v.push_back(s + tmp);
            next();
        }
    }
}
int main(){
    init();
    cout << v.size();
    return 0;
}