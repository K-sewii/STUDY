#include <bits/stdc++.h>
using namespace std;
int a[100], n, k;
int USED[1000];
int cot[100], dc1[100], dc2[100] = {0};
int NQ[100][100] = {0};
void inds(){
    for(int i = 1; i <= n; i++){
        cout << a[i];
    }
    cout << endl;
}
void indsck(){
    for(int i = 1; i <= k; i++){
        cout << a[i];
    }
    cout << endl;
}
void inNQ(){
    memset(NQ, 0, sizeof(NQ));
    for(int i = 1; i <= n;i++){
        NQ[i][a[i]] = 1;
    }
    for(int i = 1; i <= n;i++){
        for(int j = 1; j <= n;j++){
            cout << NQ[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
//sinh xau nhi phan
void Binary(int i){
    for(int j = 0; j <= 1; j++){
        a[i] = j;
        if( i == n ){
            inds();
        }
        else{
            Binary(i+1);
        }
    }
}
// sinh to lap chap k cua n
void CK(int i){
    for(int j = a[i-1] + 1; j <= n-k+i; j++){
        a[i] = j;
        if(i == k){
            indsck();
        }
        else{
            CK(i+1);
        }
    }
}

void CHL(int i){
    for(int j = 1; j <= n; j++){
        a[i] = j;
        if( i == k ){
            indsck();
        }
        else{
            CHL(i+1);
        }
    }  
}
// sinh hoan vi
void HV(int i){
    for(int j = 1; j <= n;j++){
        if(USED[j] == 0){
            a[i] = j;
            USED[j] = 1;
            if(i == n){
                inds();
            }
            else{
                HV(i+1);
            }
            //backtrack
            USED[j] = 0;
        }
    }
}

//phan hoach
void PH(int sum, int i, int value){
    if(sum == n){
        for(int k = 1; k < i; k++){
            cout << a[k] << " ";
        }
        cout << endl;
    }
    for(int j = value; j >= 1; j--){
        if(sum + j <= n){
            a[i] = j;
            PH(sum + j, i+1, j);
        }
    }
}
// tim so n quan hau
void N_Queen(int i){
    for(int j = 1; j <= n; j++){
        if(cot[j] == 0 && dc1[i - j + n] == 0 && dc2[i+j-1] == 0){
            a[i] = j;
            cot[j] = dc1[i-j+n] = dc2[i+j-1] = 1;
            if(i == n){
                inNQ();
            }
            else{
                N_Queen(i+1);
            }
            //backtrack
            cot[j] = dc1[i-j+n] = dc2[i+j-1] = 0;
        }
    }
}
int main(){
    
    return 0;
}