#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc; cin >> tc;
    while(tc--){
        int n, m; cin >> n >> m;
        int a[500][500];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }
        int h1 = 0, h2 = n - 1, c1 = 0, c2 = m -1;
        while(h1 <= h2 && c1 <= c2){// tao vong lap while check dieu kien 
            for(int i = c1; i <= c2; i++){// in so tu cot 0 -> n-1
                cout << a[h1][i] << " ";
            }
            ++h1; // tang so hang de in so tiep theo (theo 1 hang doc) 
            for(int i = h1; i <= h2; i++){
                cout << a[i][c2] << " ";
            }
            --c2;// tru so c2 de in so tiep theo theo hinh xoan oc
            if(h1 <= h2){ // phai check dieu kien de ma tran ko bi loi
            // do ko phai ma tran vuong no se co truong hop nhieu cot it hang nen phai check dieu kien
            // no co the dang xay dung cot ma hang thi da xay dung xong tu lau do chi so hang < cot
                for(int i = c2; i >= c1; i--){
                    cout << a[h2][i] << " ";// vong lap for i-- de in theo huong nguoc lai theo hinh xoan oc
                }
            }
            --h2;//tru so hang de in theo hinh xoan oc
            if(c1 <= c2){//cung la do ko phai ma tran vuong nen co truong hop nhieu hang it cot
                for (int i = h2; i >= h1; i--){
                    cout << a[i][c1] << " ";
                }
            }
            ++c1; 
        }
        cout << endl;
    }
    return 0;
}