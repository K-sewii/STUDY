#include <bits/stdc++.h>
using namespace std;
void test1_2(){
    int n; cin >> n;
    multiset<int> ms;
    for(int i = 0 ; i< n;i++){
        int x; cin >> x;
        ms.insert(x);
    }
    int tc; cin >> tc;
    while(tc--){
        int x; cin >> x;
        int y; cin >> y;
        if(x == 1){
            ms.insert(x);
        }
        else if(x == 2){
            auto it = ms.find(y);
            if(it != ms.end()){
                ms.erase(it);
            }
        }
        else{
            if(ms.find(y) != ms.end()){
                cout << "NO";
            }
            else cout << "YES";
        }
    }
}
int Count = 0;
int matrix[51][51];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1 , 1, -1, 0, 1};
int n, m;
void loang(int i, int j, int x){
    Count++;
    matrix[i][j] = 1000;
    for(int k = 0; k < 8; k++){
        int new_i = i + dx[k];
        int new_j = j + dy[k];
        if(new_i >= 1 && new_i <= n && new_j >= 1 && new_j <= n && matrix[new_i][new_j] == x){
            loang(new_i, new_j, x);
        }
    } 
}
void test1_3(){
    cin >> n >> m;
    map<int, vector<int>> mp;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; j++){
            cin >> matrix[i][j];
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(matrix[i][j] != 1000){
                int tmp = matrix[i][j];
                Count = 0;
                loang(i, j , tmp);
                mp[tmp].push_back(Count);
            }
        }
    }

}
void test1_4(){
    int n; cin >> n;
    map<string, pair<string, bool>> mp;
    for(int i = 0; i < n;i++){
        string s; getline(cin, s);
        vector<string> v;
        string tmp;
        stringstream ss(s);
        while(ss >> tmp){
            v.push_back(tmp);
        }
        string msv = v[0], hoten= "";
        for(int i = 1; i < v.size(); i++){
            hoten += v[i] + " ";
        }
        hoten.pop_back();
        mp[msv].first = hoten;
        mp[msv].second = true;
    }
    int m; cin >> m;
    for(int i = 0; i < m;i++){
        string x,y,z,t; cin >> x >> y >> z >> t;
        if(t != "code.ptit.edu.vn")
            mp[z].second = false;
    }
    for(auto it : mp){
        cout << it.first << " " << it.second.first << " ";
        if(it.second.second == false){
            cout << "FAIL\n";
        }
        else cout << "OK\n";
    }
    return;
}
string First(string s){
    stringstream ss(s);
    string tmp;
    string res;
    while( ss >> tmp){
        res += toupper(tmp[0]);
    }
    return res;
}
map<string, int> mp_product;
class Product{
    private:
        string ten, hang, donvi, gia, ma;
    public:
        void INPUT(){
            ma = First(ten);
            mp_product[ma]++;
            string tmp = to_string(mp_product[ma]);
            while(tmp.size() < 4) tmp = "0" + tmp;
            this->ma = this->ma + tmp;
            getline(cin, ten);
            cin >> hang >> donvi;
            cin.ignore();
            getline(cin, gia);
        }
        void OUTPUT(){
            cout << ten << hang << donvi << gia;
        }
        string getName(){
            return ten;
        }
        string getGia(){
            return gia;
        }
        long long tinhtoan(){
            string tmp;
            stringstream ss(gia);
            vector<string> res;
            while(ss >> tmp){
                res.push_back(tmp);
            }
            long long loinhuan = 0;
                loinhuan = stoi(res[1]) - stoi(res[0]);
            return loinhuan;
        }
        string getMa(){
            return ma;
        }
};
bool check(Product a, Product b){
    if(a.tinhtoan() != b.tinhtoan()){
        return a.tinhtoan() > b.tinhtoan();
    }
    else{
        return a.getMa() < b.getMa();
    }
}
void test1_5(){
    int sl; cin >> sl;
    Product a[sl];
    int loinhuan[sl];
    for(int i = 0 ; i < n;i++){
        a[i].INPUT();
        loinhuan[sl] = a[i].tinhtoan(); 
    }
    sort(a, a+n, check);
    for(int i = 0; i < n; ++i){
        a[i].OUTPUT();
    }
    return;
}
string lower(string s){
    for(int i = 0; i < s.size(); i++){
        s[i] = tolower(s[i]);
    }
    return s;
}
void test2(){
    int n; cin >> n;
    map<string, int> mp;
    cin.ignore();
    for(int i = 0 ; i < n; i++){
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<string> v;
        string tmp;
        while( ss >> tmp){
            v.push_back(tmp);
        }
        string ns = v[v.size() - 1];
        string email = lower(v[v.size() - 2]);
        for(int i = 0 ; i < v.size() - 2; i++){
            email += v[i][0];
        }
        mp[email]++;
        if(mp[email] == 1) cout << email << "@xyz.edu.vn" << endl;
        else cout << email << mp[email] << "@xyz.edu.vn" << endl;
        stringstream ss2(ns);
        while(getline(ss2, tmp, '/')){
            cout << stoi(tmp);
        }
        cout << endl;
    }
}
class SinhVien{
    private:
        string Code, Name, Class, BirthDay;
        double GPA;
    public:
        void Enter(int stt){
            string tmp = to_string(stt);
            while(tmp.size() < 3) tmp = "0" + tmp;
            this->Code = "SV" + tmp;
            cin.ignore();
            getline(cin, Name);
            cin >> Class >> BirthDay >> GPA;
        }
        void Print(){
            cout << Code << " " << Name << " " << Class << " " << BirthDay << " " << fixed << setprecision(2) << GPA << endl;
        }
        void Fix(){
            stringstream ss(Name);
            string tmp;
            string res;
            while( ss >> tmp ){
                res += toupper(tmp[0]);
                for(int i = 1; i < tmp.size();i++){
                    res += tolower(tmp[i]);
                }
                res += " ";
            }
            res.pop_back();
            this->Name = res;
            if(this->BirthDay[1] == '/'){
                BirthDay += "0";
            }
            if(this->BirthDay[4] == '/') {
                BirthDay.insert(3, "0");
            }
        }
        double getGPA(){
            return this->GPA;
        }
        string getCode(){
            return this->Code;
        }
};
bool cmp(SinhVien a, SinhVien b){
    if( a.getGPA() != b.getGPA() ){
        return a.getGPA() > b.getGPA();
    }
    return a.getCode() < b.getCode();
}
void test2_5(){
    int n; cin >> n;
    SinhVien a[n];
    for(int i = 0 ; i < n;i++){
        a[i].Enter(i+1);
        a[i].Fix();
    }
    sort(a, a+n, cmp);
    for(int i = 0; i < n; i++){
        a[i].Print();
    }
}
void test3_1(){
    int n; cin >> n;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            int cnt = 0;
            while(n % i == 0){
                cnt++;
                n /= i;
            }
            if(cnt >= 3){
                 cout << "YES";
            }
            else{
                cout << "NO";
            }
        }
    }
}
void test3_2(){
    int n; cin >> n;
    int a[1000007], b[1000007];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a, a+n);
    for(int i = 0; i < n;i++){
        auto it = lower_bound(a, a+n, b[i]);
        if( it == a){
            cout << "# ";
        }
        else{
            --it;
            cout << *it;
        } 
    }
}
void test3_3(){
    int n, m; cin >> n >>m;
    int a[n][m];
    int sum1[n][m], sum2[n][m];
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> a[i][j];
            sum1[i][j] = sum1[i-1][j] + a[i][j];
            sum2[i][j] = sum2[i][j-1] + a[i][j];
        }
    }
    int tc; cin >> tc;
    while(tc--){
        int truyvan; cin >> truyvan;
        if(truyvan == 1){
            int x, y, z; cin >> x >> y >> z;
            cout << sum2[x][z] - sum2[x][y-1];
        }
        else if(truyvan == 2){
            int u, v, t; cin >> u >> v >> t;
            cout << sum1[t][u] - sum1[v-1][u];
        }
        else cout << "ERROR" << endl;
    }
    return;
}
using ll = long long;
 
struct DoiBong{
    int diem, hieuso;
};
 
bool comp(pair<string, DoiBong> a, pair<string, DoiBong> b){
    if(a.second.diem != b.second.diem){
        return a.second.diem > b.second.diem;
    }
    if(a.second.hieuso != b.second.hieuso)
        return a.second.hieuso > b.second.hieuso;
    return a.first < b.first;
}
 
void test3_4(){
    string s;
    map<string, DoiBong> mp;
    while(getline(cin, s)){
        string team1 = "", team2 = "";
        int i = 1;
        while(s[i] != ']'){
            team1 += s[i]; ++i;
        }
        i += 2;
        int x = 0, y = 0;
        while(s[i] != ' '){
            x = x * 10 + (s[i] - '0'); ++i;
        }
        i += 3;
        while(s[i] != ' '){
            y = y * 10 + (s[i] - '0'); ++i;
        }
        i += 2;
        while(i < s.size() - 1){
            team2 += s[i]; ++i;
        }
        if(mp.count(team1) == 0){
            mp[team1].diem = mp[team1].hieuso = 0;
        }
        if(mp.count(team2) == 0){
            mp[team2].diem = mp[team2].hieuso = 0;
        }
        if(x > y){
            mp[team1].diem += 3;
        }
        else if(x < y){
            mp[team2].diem += 3;
        }
        else{
            mp[team1].diem += 1; mp[team2].diem += 1;
        }
        mp[team1].hieuso += x - y;
        mp[team2].hieuso += y - x;
    }
    vector<pair<string, DoiBong>> v;
    for(auto it : mp){
        v.push_back(it);
    }
    sort(v.begin(), v.end(), comp);
    for(auto it : v){
        cout << it.first << ' ' << it.second.diem << ' ' << it.second.hieuso << endl;
    }
}
class Company{
    private:
        string maNV, tenNV, ns;
        int so_ngay_cong, luong_co_ban;
    public:
        friend istream& operator >>(istream& in, Company& );
        friend ostream& operator <<(ostream& out, Company );
        void chuanhoa(){
            if(ns[1] == '/') ns = "0" + ns;
            if(ns[4] == '/') ns.insert(3, "0");
        }
        string Chuc_vu(){
            string tmp = this->maNV.substr(0, 2);
            if(tmp == "GD") return "Giam doc";
            else if(tmp == "PGD") return "Pho giam doc";
            else if(tmp == "TP") return "Truong phong";
            else if(tmp == "NV") return "NhanVien";
            else return "Ma Nhan Vien ERROR";
        }
        int luongcung(){
            return so_ngay_cong * luong_co_ban;
        }
        int phu_cap(){
            string tmp = this->maNV.substr(0, 2);
            if(tmp == "GD") return 2000000;
            if(tmp == "TP") return 500000;
            if( tmp == "NV") return 200000;
            return 1000000;
        }
        int thuong(){
            if(so_ngay_cong >= 27) return this->luongcung() * 0.2;
            else if(so_ngay_cong >= 25)  return this->luongcung() * 0.1;
            else return 0;
        }
        long long thunhap(){
            return luongcung() + phu_cap() + thuong();
        }
        string getMaNV(){
            return maNV;
        }
        bool operator < (Company another){
            if(this->thunhap() != another.thunhap()){
                return thunhap() > another.thunhap();
            }
            return this->maNV < another.getMaNV();
        }
};
istream& operator >> (istream& in, Company &a){
    in >> a.maNV;
    in.ignore();
    getline(in, a.tenNV);
    in >> a.ns >> a.so_ngay_cong >> a.luong_co_ban;
    a.chuanhoa();
    return in;
}
ostream& operator << (ostream& out, Company a){
    out << a.maNV << " " << a.tenNV << " " << a.Chuc_vu() << " " << a.ns << " " << a.so_ngay_cong << " " << a.luong_co_ban << " " << a.thunhap() << endl;
    return out;
}
void test3_5(){
    cin >> n;
    Company a[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(a, a+n);
    for(int i = 0; i < n; i++){
        cout << a[i] << endl;
    }
    return;
}
const int maxn = 10000000;
int prime[maxn + 1];

void sangsont(){
    for(int i = 0 ; i <= 1000001;i++){
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    for(int i = 2; i <= sqrt(maxn);i++){
        if(prime[i]){
            for(int j = i*i; j <= maxn; j += i){
                prime[j] = 0;
            }
        }
    }
}
int F[maxn + 1];
void test4_1(){
    sangsont();
    F[0] = F[1] = 0;
    int dem = 0;
    for(int i = 2 ; i <= maxn; i++){
        if(prime[i]){
            ++dem;
        }
        F[i] = dem;
    }
    int tc; cin >> tc;
    while(tc--){
        int l, r; cin >> l >> r;
        if(l == 0) cout << F[r] << endl;
        else cout << F[r] - F[l-1] << endl;
    }
    return;
}
class QuanNet{
    private:
        string Username, Pass, Player, in , out;
    public:
        void Input(){
            cin >> Username >> Pass;
            cin.ignore();
            getline(cin, Player);
            cin >> in >> out;
        }
        int GetTime(){
            int h1 = stoi(in.substr(0, 2));
            int h2 = stoi(out.substr(0, 2));
            int m1 = stoi(in.substr(4, 2));
            int m2 = stoi(out.substr(4, 2));
            return h2 * 60 + m2 - (h1*60 + m1);
        }
        void Output(){
            int time = GetTime();
            cout << Player << endl;
            cout << time/60 << ":" << (time/60)%60 << endl;
        }
        string getUsername(){
            return Username;
        }

};
bool cmp1(QuanNet a, QuanNet b){
    if(a.GetTime() != b.GetTime()){
        return a.GetTime() > b.GetTime();
    }
    return a.getUsername() < b.getUsername();
}
void test4_5(){
    int n; cin >> n;
    QuanNet a[n];
    for(int i = 0; i < n; ++i){
        a[i].Input();
    }
    sort(a, a+n, cmp1);
    for(int i = 0; i < n; ++i){
        a[i].Output();
    }
    return;
}
int main(){
    
    return 0;
}