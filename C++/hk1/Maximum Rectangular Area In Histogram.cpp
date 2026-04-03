#include <bits/stdc++.h>
using namespace std;
int MAX_AREA(int a[], int n){
    stack<int> st;
    int res = INT_MIN;
    int i = 0;
    while(i < n){
        if(st.empty() || a[i] >= a[st.top()]){
            st.push(i);
            ++i;
        }
        // duyet tiep i neu a[i] lon hon phan tu luu trong stack
        // neu gap phan tu nho hon phan tu top trong stack thi
        else {
            int idx = st.top();
            st.pop();
            if(st.empty()){
                //stack empty => dien tich hcn la tinh het toi phan i = 0 cho den i hien tai
                res = max(res, i * a[idx]);
            }
            // neu stack sau khi pop ma ko empty thi dien tich hcn bang a[inx] ( dien tich hinh dang tinh ) * (i - st.top() - 1 )
            else {
                res = max(res, a[idx] * (i - st.top() - 1));
            }
        }
    }
    // neu sau khi duyet nhung chi so i cuoi cung trong mang ma ko gap a[i] < a[st.top()] nua trong khi stack van con(chua tinh xong hcn cua nhung chi so i cuoi cung)
    // thi tinh lai y chang 
    while(!st.empty()){
        int idx = st.top();
        st.pop();
        if(st.empty()){
        //stack empty => dien tich hcn la tinh het toi phan i = 0 cho den i hien tai
            res = max(res, i * a[idx]);
        }
        // neu stack sau khi pop ma ko empty thi dien tich hcn bang a[inx] ( dien tich hinh dang tinh ) * (i - st.top() - 1 )
        else{
            res = max(res, a[idx] * (i - st.top() - 1));
        }
    }
    return res;
}
int main(){
    int n; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;
    cout << MAX_AREA(a, n);
    return 0;
}