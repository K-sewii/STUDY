#include <bits/stdc++.h>
using namespace std;

const int MOD = (int) 1e9 + 7;
using ll = long long;
int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}
int lcm(int a, int b){
    return a / gcd(a, b) * b;
}
ll count_uoc(ll n){
    int cnt = 0;
    for(int i = 1; i <= sqrt(n); i++){
        if( n % i == 0 ){
            cnt += 2;
        }
    }
    int c = sqrt(n);
    if( c*c == n){
        cnt--;
    }
    return cnt;
}
ll count_uoc2(ll n){
    int res = 1;
    for(int i = 2; i <= sqrt(n); i++){
        // ko can check lai if(n % i == 0) cung dc tai vi neu no ko phai so nt thi res *= 1 cung bang chinh no
        int cnt = 0;
        while(n%i == 0){
            cnt++;
            n /= i;
        }
        res *= (cnt+1);
    }
    if(n!=1){
        res *= 2;
    }
    return res;
}
//ham luy thua nhi pham
// de tinh nhung so mu qua lon
ll pow1(ll a, ll b){
    a %= MOD;
    ll res = 1;
    while(b){
        if(b & 1){
            res *= a;
            res %= MOD;
        }
        b /= 2;
        a *= a;
        a %= MOD;
    }
    return res;
}
ll pow2(int a, int b){
    if(b == 0){
        return 1;
    }
    ll x = pow2(a, b/2);
    if(b & 1){
        return x*x*a;
    }
    else return x*x;
}
//phi ham euler
// dem co bn so ma gcd cua no voi uoc cua no == 1
ll count(ll n){
    ll res = n; 
    for(int i = 2; i <= sqrt(n); i++){
        if( n % i == 0 ){
            while(n % i == 0){
                n /= i;
            }
            // n-n/i;
            res -= res/i;
        } 
    }
    if(n != 1){
        res -= res/n;
    }
    return res;
}
//tinh so fibo bang ma tran
//tao function nhan 2 ma tran
void nhan(ll a[2][2], ll b[2][2]){
    ll res[2][2];
    for(int i = 0 ; i < 2; i++){
        for(int j = 0; j < 2; j++){
            res[i][j] = 0;
            for(int k = 0; k < 2; k++){
                res[i][j] += a[i][k] * b[k][j] % MOD;
            }
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            a[i][j] = res[i][j];
        }
    }
}
//tao funtion a^n de tim so fibo
//O(logn)
void fibo_pow(ll n){
    ll res[2][2] = {1, 0, 0, 1};
    ll a[2][2] = {1, 1, 1, 0};
    //thuat toan luy thua nhi phan tai vi so fibo rat lon, co the xay ra truong hop tran so
    while(n){
        //2 tac dung: 
        // cap nhat ket qua cuoi cung
        // va nhan neu so mu la so le
        if(n & 1){
            nhan(res, a);
        }
        //a^n
        nhan(a, a);
        n /= 2;
    }
    cout << res[0][1] << endl;

}
bool nt(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if( n % i == 0){
            return false;
        }
    }
    return n > 1;
}
bool sohoanhao(ll n){
    //duyet cac so nt tu i:1-> 32 thi de co the duyet cac so hoan hao bang cong thuc 2^i * 2 ^ i ( tu 1-> 10^18 so hoan hao)
    for(int i = 2; i <= 32; i++){
        if(nt(i)){
            int tmp = (int) pow(2, i) - 1;
            if(nt(tmp)){
                ll shh = 1ll*tmp * pow(2, i-1);
                return shh == n;
            }
        }
    }
    return false;
}
//so hoan hao la so ma tong cac uoc nguyen duong cua no bang chinh no
//2^n-1 la so nguyen to 
//- > 2^(n-1) * 2^n -1 là số hoàn hảo

// nCk
int nCk(int n, int k){
    int res = 1;
    k = min(k, n - k); //giam do phuc tap
    for(int i = 0; i < k; i++){
        //xet den k - 1
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
ll fibo(int n){
    ll a[n+1]; 
    a[0] = 0; a[1] = 1;
    for(int i = 2; i <= n; i++){
        a[n] = a[n-1] + a[n-2]; 
        a[n] %= MOD;
    }
    return a[n] % MOD;
}

// tim mu x lon nhat sao cho so N! chia het cho k^x
//duyet trau
int degree(int n, int k){
    int ans = 0;
    for(int i = k ; i <= n; i += k){
        int m = i;
        while( m % k == 0){
            ans++;
            m /= k;
        }
    }
    return ans;
}

// legendre
int degree2(int n, int k){
    int ans = 0;
    for(int i = k ; i <= n; i *= k){
        ans += n / i;
        // lay phan nguyen cua n / k^i | i: k..k*k... k*k*k
    }
    return ans;
}
//dem so luong so 0 tan cung cua n!
//10 = 2 x 5. so luong so 0 tan cung cung phu thuoc vao so cap (2,5) trong n!
//nhung khi phan tich thua so nguyen to: so luong 2 nhieu hon 5 => so luong thua so 5 trong n! quyet dinh so luong so 0 tan cung
void soluongso0tancungtrong_n_giaithua(){
    int n; cin >> n;
    cout << degree2(n, 5);
}
// sang so uoc nho nhat
int p[1000001];
void sang_uocmin(){
    for(int i = 1; i <= 1000000; i++){
        p[i] = i;
    }
    for(int i = 2; i <= sqrt(1000000); i++){
        if(p[i] == i){
            for(int j = i*i; j <= 1000000; j += i){
                if(p[j] == j){
                    // kiem tra coi no da tung dc duyet chua
                    //neu chua duyet thi moi cap nhat uoc nho nhat
                    p[j] = i;
                }
            }
        }
    }
}
void ptthuasonguyento_sang_uocmin(){
    sang_uocmin();
    int n; cin >> n;
    while(n != 1){
        cout << p[n] << " ";
        n /= p[n];
    }
}
//sang phi ham euler
int phi[1000001];
void sang_phihameuler(){
    for(int i = 1; i <= 1000000; i++){
        phi[i] = i;
    }
    // ko duyet sqrt nhu sang_uoc va sang_nt
    for(int i = 2; i <= 1000000; i++){
        if(phi[i] == i){
            phi[i] = i - 1; // do neu i la so nguyen to thi phi cua no bang i - 1
            for(int j = 2*i; j <= 1000000; j += i){
                phi[j] = phi[j] - phi[j] / i;
            }
        }

    }
}
//quy hoach dong nCk
ll C[1001][1001]; // to hop chap j cua i = nCk
// voi 0 <= k <= n <= 1000
void init(){
    for(int i = 0; i <= 1000; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i){
                C[i][j] = 1;
            }
            else{
                C[i][j] = C[i-1][j-1] + C[i-1][j];
                C[i][j] %= MOD;
            }
        }
    }
}
//dinh ly nho cua fermat
// neu m la so nguyen to thi moi xay ra

//A^(m-2) % m = A^-1 
// tim nghich dao modul
int powMod(ll a, ll b , ll c){
    int res = 1;
    while(b){
        if( b & 1 ){
            res *= a;
            res %= c;
        }
        a *= a;
        a %= c;
        b /= 2;
    }
    return res;
}
int main(){
    int a, m; cin >> a >> m;
    cout << powMod(a, m-2, m);
    return 0;
}