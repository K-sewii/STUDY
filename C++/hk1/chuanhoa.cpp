#include <bits/stdc++.h>
using namespace std;
void viethoa(string &a){
    vector<string> v;
    stringstream ss(a);
    string tmp;
    while(ss >> tmp){
        for(char &x : tmp){
            tmp[0] = toupper(tmp[0]);
        }
        v.push_back(tmp);
    }
    for(string x : v){
        cout << x << " ";
    }
}
string viethoa2(string a){
    stringstream ss(a);
    string res, token = "";
    while(ss >> token){
        res += toupper(token[0]);
        for(int i = 1; i < token.length(); i++) res += tolower(token[i]);
        res += " ";
    }
    res.erase(res.length() - 1);
    return res;
}
int main(){
    string s; getline(cin, s);
    viethoa(s);
    cout << endl;
    cout << viethoa2(s);
    return 0;
}