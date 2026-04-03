#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

Node *makeRoot(Node *root, int u, int v, char c){
    if(c == 'L') root->left = new Node(v);
    else root->right = new Node(v);
}

void insertRoot(Node *root, int u, int v, char c){
    if(root == NULL) return;
    if(root->data = u){
        makeRoot(root, u, v, c);
    }
    else{
        insertRoot(root->left,u, v, c);
        insertRoot(root->right, u, v, c);
    }
}
void inorder(Node *root){
    if( root != NULL ){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    /*
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
    */
}
void levelOrder(Node *root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* tmp = q.front(); q.pop();
        cout << tmp->data << " ";
        if(tmp->left != NULL){
            q.push(tmp->left);
        }
        if(tmp->right != NULL){
            q.push(tmp->right);
        }
    }
}

// cay nhi phan tim kiem
Node* search(Node* root, int x){
    if(root = NULL) return NULL;
    if(root->data == x) return root;
    if(x < root->data) return search(root->left, x);
    else return search(root->right, x);
}

Node* insert(Node* root, int x){
    if(root == NULL) return new Node(x);
    if(x < root->data) root->left = insert(root->left, x);
    else root->right = insert(root->right, x);
    return root;
}
Node* minValueNode(Node* node){
    Node* current = node;
    while(current && current->left != NULL){
        current = current->left;
    }
    return current;
}
Node* deleteNode(Node* root, int x){
    if(root == NULL) return root;
    if(x < root->data) root->left = deleteNode(root->left, x);
    else if(x > root->data) root->right = deleteNode(root->right, x);
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    Node *root = NULL; // chi la 1 con tro cau truc, ko quan li gi ca (NULL)
    int n; cin >> n;
    for(int i = 0; i < n ;i++){
        int u, v; char c;
        cin >> u >> v >> c;
        if( root == NULL){
            root = new Node(u);
            // phai cap phat dong cho no quan li
            makeRoot(root, u, v, c);// dua no ve ben trai hay phai
        }
        else{
            insertRoot(root, u, v, c);
        }
    }
    
    return 0;
}