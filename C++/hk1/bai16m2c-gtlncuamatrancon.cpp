#include <bits/stdc++.h>
using namespace std;

#define ms(s,n) memset(s,n,sizeof(s))
#define all(a) a.begin(),a.end()
#define present(t, x) (t.find(x) != t.end())
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair
#define endl "\n"


typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;

const int MOD = (int) 1e9+7;
const int INF = (int) 1e9+2804;
inline ll gcd(ll a,ll b){ll r;while(b){r=a%b;a=b;b=r;}return a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int major[402][402], minor[402][402] = {0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int TC; TC = 1;
	while(TC--){
		int n, m; cin >> n;
		int a[n + 1][n + 1];
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++) cin >> a[i][j];//duyet tu 1 -> n de cac phan tu hang va cot i == j == 0 thi no bang 0 
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i == 1 || j == 1){
					major[i][j] = a[i][j];
				}
				else{
					major[i][j] = a[i][j] + major[i - 1][j - 1];//tao ma tran cho tinh sum cua duong cheo chinh
				}
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = n; j >= 1; j--){
				if(i == 1 || j == n){
					minor[i][j] = a[i][j];
				}
				else{
					minor[i][j] = minor[i - 1][j + 1] + a[i][j];//tao ma tran cho tinh sum cua duong cheo phu
				}
			}
		}
		ll ans = -1e18;
		for(int i = n; i >= 1; i--){
			for(int j = n; j >= 1; j--){//duyet tu chu so cuoi tai vi no la tong cua duong cheo chinh 
				int tmp = min(j, i); // tai vi la ma tran vuong nen chi so cua no sau khi xet [i][j] la so nho nhat trong 2 so
				int hang = i - tmp, cot = j - tmp; // tmp la kich thuoc ma tran vuong, cho nen [i][j] la ma tran tong - kich thuoc ma tran con ra so hang va cot can de tru 
				for(int k = 0; k < min(i, j); k++){// xet tung ma tran con nho hon trong ma tran lon dang xet
					ans = max(ans, 0ll + major[i][j] - major[hang + k][cot + k] - 
					(minor[i][cot + k + 1] - minor[hang + k][j + 1]));
				}
			}
		}
        // 0ll de luu so do la kieu long long ma ko gay thay doi gia tri
        // major:hang + k va cot + k de sau moi lan k++ thi hang va cot can tru cung se thay doi theo
        // cot + k + 1 la cong thuc de tim so tong cua duong cheo phu doi voi ma tran con do
        // minor[hang+k][j+1] la cong thuc de tim so can tru cua duong cheo phu sau khi xet tung ma tran con
		cout << ans << endl;
	}
	return 0;
}

