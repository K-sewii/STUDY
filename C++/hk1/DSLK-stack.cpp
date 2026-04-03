#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* next;
};
typedef struct Node* node;
bool empty(node top){
    return top == NULL;
}
int size(node top){
    int cnt = 0;
    node tmp = top;
    while(tmp != NULL){
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}
node MakeNode(int x){
    //cap phat dong cho con tro node
    node tmp = new Node();
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}
void PushNode(node &top, int x){
    node tmp = MakeNode(x);
    if(top == NULL){
        top = tmp;
    }
    else{
        tmp->next = top;
        top = tmp;
    }
}
void PopNode(node &top){
    if(top == NULL){
        return;
    }
    top = top->next;
}
int GetTop(node top){
    return top->data;
}
using ll = long long;
int main(){
    node top = NULL;
    ll n; cin >> n;
    //chuyen doi so nhi phan(binary)
    while(n){
        int r = n % 2;
        PushNode(top, r);
        n /= 2;
    }
    while(!empty(top)){
        cout << GetTop(top);
        PopNode(top);
    }
    return 0;
}