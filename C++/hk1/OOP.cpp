#include <bits/stdc++.h>
using namespace std;
class SinhVien{
    private:
        string ma, ten, lop, email;
    public:
    SinhVien(){
        ma = ten = lop = email = "";
    }
    SinhVien(string ma, string ten, string lop, string email){
        this->ma = ma;
        this->ten = ten;
        this->lop = lop;
        this->email = email;
    }
    friend istream& operator >> (istream &in, SinhVien& );
    friend ostream& operator << (ostream &out, SinhVien );
    bool operator < (SinhVien another){
        return this->ma < another.ma;
    }
    friend bool operator > (SinhVien a, SinhVien b){    
        return a.lop > b.lop;

    }
    string GetMa(){
        return this->ma;
    }
};
istream& operator >> (istream &in, SinhVien& a){
    cout << "Nhap ma :";
    in >> a.ma;
    in.ignore();
    cout << "Nhap ten :"; getline(in, a.ten);
    cout << "Nhap lop :"; in >> a.lop;
    cout << "Nhap email :"; in >> a.email;
    return in;
}
ostream& operator << (ostream &out, SinhVien a){
    out << a.ma << " " << a.ten << " " << a.lop << " " << a.email;
    return out;
}
class MinhKy : public SinhVien{
    private:
        string msvrieng;
    public:
        MinhKy(){
            msvrieng = "";
        }
        MinhKy(string ma, string ten, string lop, string email, string msvrieng) : SinhVien(ma, ten, lop, email){
            this->msvrieng = msvrieng;
        }

};
void viethoa(string &s){
    for(char &x : s) x = toupper(x);
}
string convert(string s){
    stringstream ss(s);
    vector<string> v;
    string tmp, res = "";
    while(ss >> tmp) v.push_back(tmp);
    for(int i = 0; i < 2; i++){
        res += toupper(v[i][0]);
    }
    return res;
}
typedef SinhVien SV;
void lktheonganh(){
    int n; cin >> n;
    map<string, vector<SV>> mp;
    for(int i = 0; i < n; i++){
        SV tmp; cin >> tmp;
        mp[tmp.GetMa().substr(5, 2)].push_back(tmp);
    }
    int q; cin >> q;
    cin.ignore();
    while(q--){
        string s; getline(cin, s);
        viethoa(s);
        cout << " DANH SACH SINH VIEN NGANH " << s << endl;
        string ng = convert(s);
        if(ng == "CN" || ng == "AT"){
            for(SV x : mp[ng]){
                if(x.GetMa().find("E") != string::npos){
                    cout << x;
                }
            }
        }
        else{
            for(SV x : mp[ng]){
                cout << x;
            }
        }
    }
}

int main(){
    lktheonganh();
    return 0;
}
