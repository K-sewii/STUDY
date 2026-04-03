#include <bits/stdc++.h>
using namespace std;

// chuyen tu tien to sang hau to
void solve3(string s){
    stack<string> st;
    for(int i = s.size() - 1; i >= 0; i--){
        if(isalpha(s[i])) st.push(string(1,(s[i])));
        else{
            string x1 = st.top(); st.pop();
            string x2 = st.top(); st.pop();
            string ex = x1 + x2 + s[i];
            st.push(ex);
        }
    }
    cout << st.top() << endl;

}
int main(){
    string s; cin >> s;
    solve3(s);
    return 0;
}