#include <bits/stdc++.h>
using namespace std;
void MIN_xaukitu(string s1, string s2){
    int dem1[256] = {0}, dem2[256] = {0};
    for(char x : s2){
        dem2[x]++;
    }
    int ans = INT_MAX, left = 0, cnt = 0, idx = -1;
    for(int i = 0 ; i < s1.size(); i++){
        dem1[s1[i]]++;
        if( dem1[s1[i]] <= dem2[s1[i]] ) ++cnt;
        if( cnt == s2.size() ){
            //thu gon lai
            while(dem1[s1[left]] > dem2[s1[left]] || dem2[s1[left]] == 0){
                if(dem1[s1[left]] > dem2[s1[left]]){
                    dem1[s1[left]]--;
                }
                ++left;
            }
            //left la vi tri bat dau cua xau nho nhat
            //i la vi tri ket thuc
            if(ans > i - left + 1){
                ans = i - left + 1;
                idx = left;
            }
        }
    }
    if(idx == -1){
        cout << "-1\n";
    }
    else{
        cout << s1.substr(idx, ans);
    }
}
int main(){
    
    return 0;
}