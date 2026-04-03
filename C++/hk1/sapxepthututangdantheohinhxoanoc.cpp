#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc; cin >> tc;
    while(tc--){
        int n, m; cin >> n ;
        int v[n*n];// tao mang 1 chieu de chua phan tu da dc sap xep tang dan
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        sort(v, v+n*n);//sap xep mang 1 chieu theo chieu tang dan
        int h1 = 0, h2 = n - 1, c1 = 0, c2 = m -1, cnt = 0, a[n][n];
        while(h1 <= h2 && c1 <= c2){// tao vong lap while check dieu kien 
            for(int i = c1; i <= c2; i++){// in so tu cot 0 -> n-1
                a[h1][i] = v[cnt++];// luu mang a theo hinh xoan oc theo thu tu tang dan cua mang v da dc sap xep truoc do
            }
            ++h1; // tang so hang de in so tiep theo (theo 1 hang doc) 
            for(int i = h1; i <= h2; i++){
                a[i][c2] = v[cnt++];
            }
            --c2;// tru so c2 de in so tiep theo theo hinh xoan oc
            if(h1 <= h2){ // phai check dieu kien de ma tran ko bi loi
            // do ko phai ma tran vuong no se co truong hop nhieu cot it hang nen phai check dieu kien
            // no co the dang xay dung cot ma hang thi da xay dung xong tu lau do chi so hang < cot
                for(int i = c2; i >= c1; i--){
                    a[h2][i]=v[cnt++];// vong lap for i-- de in theo huong nguoc lai theo hinh xoan oc
                }
            }
            --h2;//tru so hang de in theo hinh xoan oc
            if(c1 <= c2){//cung la do ko phai ma tran vuong nen co truong hop nhieu hang it cot
                for (int i = h2; i >= h1; i--){
                    a[i][c1] = v[cnt++];
                }
            }
            ++c1; 
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j < n; j++){
                cout << a[i][j] << " ";// in ra mang a
            }
        }
        cout << endl;
    }
    return 0;
}