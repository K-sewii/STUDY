#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int a[n], b[n];
    for(int &x : a) cin >> x;
    stack<int> st;
    for(int i =0; i < n; i++){
        if(st.empty()){
            st.push(i);
        }// luu phan tu dau tien vao stack
        else{
            while(!st.empty() && a[st.top()] < a[i]){// 2 dieu kien: 1 dk de dung vong while, 1 dieu kien de check cac phan tu trong stck va a[i]
                b[st.top()] = a[i];
                st.pop();
            }
            st.push(i);
        }
    }
    while(!st.empty()){
        b[st.top()] = -1;
        st.pop();
    }
    // neu trong stack con luu nhung a[i] ko tim dc phan tu lon hon no thi in ra -1
    for(int x : b) cout << x << " ";
    return 0;
}