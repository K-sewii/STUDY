#include <bits/stdc++.h>
using namespace std;
class SinhVien{
    private:
        string ma, ten, ns, lop;
        double gpa;
        static int dem;
    public:
        void INPUT(){
            // ++dem; ma = to_string(dem);
            // while(ma.size() < 3) ma = "0" + ma;
            // ma = "SV" + ma;
            ++dem;
            this->ma = "SV" + string(3-to_string(dem).size(), '0') + to_string(dem);
            cin.ignore();
            getline(cin, ten);
            cin >> lop >> ns >> gpa;
        }
        void OUTPUT(){
            cout << ma << " " << ten << " " << lop << " " << ns << " " << fixed << setprecision(2) << gpa << endl;
        }
        void chuanhoa(){
            string s = ten;
            string res, tmp;
            stringstream ss(s);
            while( ss >> tmp ){
                res += toupper(tmp[0]);
                for(int i = 1; i < tmp.size(); i++){
                    res += tolower(tmp[i]);
                }
                res += " ";
            }
            res.pop_back();
            this->ten = res;
            if(ns[1] == '/') ns = "0" + ns;
            if(ns[4] == '/') ns.insert(3, "0");
        }
        double getGPA(){
            return gpa;
        }
        string getMa(){
            return ma;
        }

};
int SinhVien::dem = 0;
bool cmp(SinhVien a, SinhVien b){
    if(a.getGPA() != b.getGPA()){
        return a.getGPA() > b.getGPA();
    }
    return a.getMa() < b.getMa();
}
int main(){
    int n; cin >> n;
    SinhVien a[n];
    for(int i = 0; i < n;i++){
        a[i].INPUT();
        a[i].chuanhoa();
    }
    sort(a, a+n, cmp);
    for(int i = 0; i < n; i++){
        a[i].OUTPUT();
    }
    return 0;
}