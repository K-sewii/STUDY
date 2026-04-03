#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* next; // con tro 
};
typedef struct Node* node;
// cap phat dong mot node voi moi du lieu la so nguyen x
node MakeNode(int x){
    node tmp = new Node();
    tmp->data= x;
    tmp->next = NULL;
    return tmp;
}
//kiem tra empty
bool emty(node a){
    return a == NULL;
}
int size(node a){
    int cnt = 0;
    // dieu kien vong while ko co a->next de duyet qua phan tu cuoi cung
    while(a != NULL){
        cnt++;
        a = a->next;
    }
    return cnt;
}
// them 1 phan tu vao dau danh sach lien ket 
void insertFirst(node &a, int x){
    node tmp = MakeNode(x);
    // neu dslk chua co gia trị nào
    if(a == NULL){
        a= tmp;
    }
    // nếu dslk đã có giá trị thì lưu địa chỉ của a vào node tmp rồi cập nhật node a la node tmp sau khi cập nhật next của a, để ko bị những đứt đoạn liên kết
    else{
        tmp->next = a;
        a = tmp;// cap nhat vi tri con tro a(vi tri dau) la node tmp
    }
}
void insertLast(node &a, int x){
    node tmp = MakeNode(x);
    if(a == NULL){
        a = tmp;
    }
    else{
        // ko the lay node a de duyet -> gay nen dslk deu la phan tu a(trung nhau)
        node pos = a;
        //chi tao 1 con tro
        // dieu khien vong while de duyet den phan tu cuoi cung
        while(pos->next){
            pos = pos->next;
        }
        pos->next = tmp;
    }
}
void insertMiddle(node &a, int x, int pos){
    int n = size(a);
    if(pos <= 0 || pos > n + 1){
        cout << "Vi tri chen khong hop le\n ";
    }
    if(pos == 1){
        insertFirst(a, x); return;
    }
    else if(pos == n + 1){
        insertLast(a, x); return;
    }   
    node p = a;
    for(int i = 1; i < pos - 1; i++){
        p = p->next;
        // vi khi cap nhat p->next thi chi can pos o vi tri pos - 1 thi p->next o pos
        // nen dieu kien chi can o pos-2
    }
    node tmp = MakeNode(x);
    tmp->next = p->next;
    //dia chi cua tmp = dia chi pos
    p->next = tmp;
    //dia chi cua pos - 1 = dia chi cua tmp
}
void deleteFirst(node &a){
    if(a == NULL) return;
    a = a->next;
}
void deleteLast(node &a){
    if(a == NULL) return;
    node truoc = NULL, sau = a;
    while(sau->next != NULL){
        // truoc khi sau->next = NULL va while se ket thuc thi minh se cap nhat node truoc la phan tu sau cua vong while truoc( co nghia la cap nhat con tro *truoc truoc con tro *sau)
        truoc = sau;
        sau = sau->next;
    }
    if(truoc == NULL){
        a = NULL;
        // neu chi co 1 phan tu
    }
    else{
        truoc->next = NULL;
        // khoi tao truoc->next lien ket NULL, chat dut lien ket NULL cua sau->next. Cho nen ta nhan dc ket qua la xoa dc phan tu cuoi cung
    }
}
//toi uu code
void deleteLast2(node &a){
    if(a == NULL) return;
    if(a->next = NULL){
        delete a;
        a = NULL;
       // return;
    }
    node tmp = a;
    while(tmp->next->next != NULL){
        tmp = tmp->next;
    }
    delete tmp->next;// xoa phan tu cuoi
    tmp->next = NULL; // chat dut lien ket cu
}
void deleteMiddle(node &a, int pos){
    if(pos <= 0 || pos > size(a) + 1) return;
    else if(a == NULL) return;
    node truoc = NULL, sau = a;
    for(int i = 1; i < pos;i++){
        truoc = sau;
        sau = sau->next;
    }
    if(truoc == NULL){
        a = NULL;// xoa phan tu a(truong hop chi co 1 phan tu)
    }
    else{
        truoc->next = sau->next;
        //cap nhat lien ket cua node truoc = node tiep theo cua node sau
    }
}
void in(node a){
    cout << "----------------------------------------\n";
    while(a != NULL){
        cout << a->data << " ";
        a= a->next;
    }
    cout << endl;
    cout << "-----------------------------------------\n";
}
void sapxep(node &a){
    //selection sort( sap xep chon )
    for(node q = a; q->next != NULL; q = q->next){
        // do sap xep chi can n-1 phan tu
        node min = q;
        for(node r = q; r != NULL; r= r->next){
            // vong for nay bat buoc phai duyet het phan tu trong danh sach de tim gia tri nho nhat
            if(r->data < min->data){
                min = r;
            }
        }
        int tmp = min->data;
        //tao bien tmp luu gia tri nho nhat
        min->data = q->data;
        q->data = tmp;
    }
    //insertion sort( sắp xếp chèn ) chỉ dùng được trong danh sach liên kết kép
}
int main(){
    //int *a= new int[1000000000];
    // cu phap cap phat dong
    node dslk = NULL;
    while(1){
        cout << "-------------------------MENU------------------------\n";
        cout << "1. Chen phan tu vao dau danh sach\n";
        cout << "2. Chen phan tu vao cuoi danh sach\n";
        cout << "3. Chen phan tu vao giua danh sach\n";
        cout << "4. Xoa phan tu o dau danh sach\n";
        cout << "5. Xoa phan tu o cuoi danh sach\n";
        cout << "6. Xoa phan tu o giua danh sach\n";
        cout << "7. Thong tin danh sach\n";
        cout << "8. Sap xep danh sach\n";
        cout << "0. STOP!\n";
        cout << "------------------------------------------------------\n";
        int lc; cin >> lc;
        if(lc == 1){
			int x; cout << "Nhap gia tri can chen :"; cin >> x;
			insertFirst(dslk, x);
		}
		else if(lc == 2){
			int x; cout << "Nhap gia tri can chen :"; cin >> x;
			insertLast(dslk, x);
		}
		else if(lc == 3){
			int x; cout << "Nhap gia tri can chen :"; cin >> x;
			int pos; cout << "Nhap vi tri can chen :"; cin >> pos;
			insertMiddle(dslk, x, pos);
		}
		else if(lc == 4){
			deleteFirst(dslk);
		}
		else if(lc == 5){
			deleteLast(dslk);
		}
		else if(lc == 6){
			int pos; cout << "Nhap vi tri can xoa:"; cin >> pos;
			deleteMiddle(dslk, pos);
		}
		else if(lc == 7){
			in(dslk);
		}
        else if(lc == 8){
            sapxep(dslk);
        }
		else if(lc == 0){
			break;
		}
    }
    return 0;
}

