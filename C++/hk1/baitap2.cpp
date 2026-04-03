#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
bool nt (int);
bool check (int);
bool check ( int n ){
    int sum = 0;
    while (n){
        sum += n % 10;
        n /= 10;
    }  
    if (nt(sum))
        return true;
    else return false;
}
bool nt(int n){ // int, void, bool
    for(int i = 2; i <= sqrt(n);i++){
        if (n % i == 0)
            return false;
    }
    return n > 1;
}
int main (){
    int i ; cin >> i;
    if (check (i)){
        cout << "TRUE" << endl;
    }
    else cout <<" INVALID ";
    return 0;
}