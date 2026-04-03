#include <bits/stdc++.h>
using namespace std;

int uutien(char c){
    if(c == '^') return 3;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    return 0;
}

void solve(string s){
    stack<char> st;
    string res = "";
    for(int i = 0; i < s.size(); i++){
        if(isalpha(s[i])) res += s[i];
        else if(s[i] == '(') st.push(s[i]);
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                res += st.top();
                st.pop();
            }
            st.pop(); // xoa not '('
        }
        // truong hop ko co dau ()
        // A+B*D+E
        else{
            while(!st.empty() && uutien(s[i]) <= uutien(st.top())){
                res += st.top();
                st.pop();
            }
            // neu uu tien s[i] > top trong stack thi cu push no vao nhu binh thuong
            st.push(s[i]);
        }
    }
    // check lai trong stack
    // tai vi for o tren chi cap nhat res khi gap dau ')'
    // o day cap nhat res khi chu cuoi cung ko phai la ')'
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    cout <<  res << endl;
}
int main(){
    string s; cin >> s;
    solve(s);
    return 0;
}