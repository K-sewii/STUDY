#include <bits/stdc++.h>
using namespace std;

struct sinhvien{
    string ma, ten, lop, ns;
    double gpa;
    void nhap(){
        cout << "Nhap ma sinh vien :"; cin >> ma;
        cout << "Nhap ten sinh vien :"; cin.ignore();
        getline(cin, ten);
        cout << "Nhap lop sinh vien :";
        cin >> lop;
        cout << "Nhap ngay sinh cua sinh vien :"; cin >> ns;
        cout << "Nhap gpa cua sinh vien :"; cin >> gpa;
    }
    void in(){
        cout << "-------------------------------------------\n";
        cout << "Ma sinh vien :" << ma << endl;
        cout << "Ten sinh vien :" << ten << endl;
        cout << "Lop sinh vien :" << lop << endl;
        cout << "Ngay sinh cua sinh vien :" << ns << endl;
        cout << " Gpa :" << gpa << endl;
        cout << "--------------------------------------------\n";
    }
};
void inds(sinhvien a[], int n){
    cout << "Thong tin danh sach sinh vien :\n";
    for(int i = 0; i < n;i++){
        a[i].in();
    }
}
void timkiemtheomasinhvien(sinhvien a[], int n){
    string ma;
    cout << "Nhap ma sinh vien can tim :"; cin >> ma;
    for(int i = 0; i < n;i++){
        if(ma == a[i].ma){
            a[i].in(); return;
        }
    }
    cout << "Khong co sinh vien nao trong danh sach da co !\n";
}
void lietkesinhvien(sinhvien a[], int n){
    int res = 0;
    for(int i = 0; i < n;i++){
        if( a[i].gpa > res ) res = a[i].gpa;
    }
    cout << "Danh sach sinh vien co diem gpa cao nhat :\n";
    for(int i  = 0; i < n; i++){
        if(a[i].gpa == res ) a[i].in();
    }
}
bool cmp(sinhvien a, sinhvien b){
    return a.gpa > b.gpa;
}
void lietkesinhvien2(sinhvien a[], int n){
    vector<sinhvien> v;
    for(int i = 0; i < n;i++ ){
        if(a[i].gpa >= 2.5){
            v.push_back(a[i]);
        }
    }
    sort(v.begin(), v.end(), cmp);
    cout << "Danh sach sinh vien co gpa >= 2.5 :\n";
    for(sinhvien x : v){
        x.in();
    }
}
vector<string> chuanhoa(string name){
    stringstream ss(name);
    vector<string> v;
    string tmp = "";
    while( ss >> tmp){
        v.push_back(tmp);
    }
    return v;
}
// bool cmp2(sinhvien a, sinhvien b){
//     string x = chuanhoa(a.ten);
//     string y = chuanhoa(b.ten);
//     return x < y;
// }
// xoa do nhieu bien so
bool cmp2(sinhvien a, sinhvien b){
    vector<string> v1 = chuanhoa(a.ten);
    vector<string> v2 = chuanhoa(b.ten);
    if(v1.back() != v2.back()) return v1.back() < v1.back();
    int s1 = v1.size(), s2 = v2.size();
    for(int i = 0; i < min(s1, s2); i++){
        if(v1[i] != v2[i]) return v1[i] < v2[i];
    }
    return s1 < s2;
}
void sapxepsinhvien(sinhvien a[], int n){
    sort(a, a+n, cmp2);
}
bool cmp3(sinhvien a, sinhvien b){
    if(a.lop != b.lop) return a.lop < b.lop;
    vector<string> v1 = chuanhoa(a.ten);
    vector<string> v2 = chuanhoa(b.ten);
    if(v1.back() != v2.back()) return v1.back() < v1.back();
    int s1 = v1.size(), s2 = v2.size();
    for(int i = 0; i < min(s1, s2); i++){
        if(v1[i] != v2[i]) return v1[i] < v2[i];
    }
    return s1 < s2;
}
void sxsinhvientheolop(sinhvien a[], int n){
    sort(a, a + n, cmp3);
}
bool cmp4(sinhvien a,sinhvien b){
    if(a.lop != b.lop) return a.lop < b.lop;
    return a.gpa > b.gpa;
}
void sxsinhvientheogpa(sinhvien a[], int n){
    sort(a, a+n, cmp4);
}
void solve(){
    sinhvien a[10000];
    int n = 0; // luu so sinh vien
    while(1){
        cout << "---------------------------MENU-----------------------------\n";
        cout << "1. Nhap thong tin sinh vien\n";
        cout << "2. Hien thi toan bo danh sach sinh vien\n";
        cout << "3. Tim kiem sinh vien theo ma\n";
        cout << "4. Liet ke sinh vien co diem gpa cao nhat\n";
        cout << "5. Liet ke sinh vien co diem gpa >= 2.5\n";
        cout << "6. Sap xep sinh vien theo ho va ten\n";
        cout << "7. Sap xep sinh vien theo lop\n";
        cout << "8. Sap xep sinh vien theo gpa cao nhat\n";
        cout << "0. EXIT!\n";
        cout << "------------------------------------------------------------\n";
        cout << " Nhap vao lua chon ban muon:\n";
        int lc; cin >> lc;
        if(lc == 1){
            a[n].nhap();
            n++; // sau khi nhap xong thi tang bien n coi nhu so luong sinh vien co san trong danh sach
        }
        else if(lc == 2){
            inds(a, n);
        }
        else if(lc == 3){
            timkiemtheomasinhvien(a, n);
        }
        else if(lc == 4){
            lietkesinhvien(a, n);
        }
        else if(lc == 5){
            lietkesinhvien2(a, n);
        }
        else if(lc == 6){
            sapxepsinhvien(a, n);
        }
        else if(lc == 7){
            sxsinhvientheolop(a, n);
        }
        else if(lc == 8){
            sxsinhvientheogpa(a, n);
        }
        else if(lc == 0){
            break;
        }
    }
    return;
}
struct Student{
	string name, id, email;
	double gpa;
};

struct SV{
	Student s;
	SV *next;
};

typedef struct SV* sv;

//Cap phat dong mot node moi voi du lieu la so nguyen x
sv makeNode(){
	Student s;
	cout << "Nhap thong tin sinh vien :\n";
	cout << "Nhap ID :"; cin >> s.id;
	cout << "Nhap ten :"; cin.ignore();
	getline(cin, s.name);
	cout << "Nhap email cua sinh vien"; cin>> s.email;
	cout << "Nhap gpa :"; cin >> s.gpa;
	sv tmp = new SV();
	tmp->s = s;
	tmp->next = NULL;
	return tmp;
}

//Kiem tra rong
bool empty(sv a){
	return a == NULL;
}

int Size(sv a){
	int cnt = 0;
	while(a != NULL){
		++cnt;
		a = a->next; // gan dia chi cua not tiep theo cho node hien tai
		//cho node hien tai nhay sang not tiep theo
	}
	return cnt;
}

//them 1 phan tu vao dau danh sach lien ket
void insertFirst(sv &a){
	sv tmp = makeNode();
	if(a == NULL){
		a = tmp;
	}
	else{
		tmp->next = a;
		a = tmp;
	}
}

//Them 1 phan tu vao cuoi dslk
void insertLast(sv &a){
	sv tmp = makeNode();
	if(a == NULL){
		a = tmp;
	}
	else{
		sv p = a;
		while(p->next != NULL){
			p = p->next;
		}
		p->next = tmp;
	}
}

//Them 1 phan tu vao giua
void insertMiddle(sv &a,int pos){
	int n = Size(a);
	if(pos <= 0 || pos > n + 1){
		cout << "Vi tri chen khong hop le !\n"; return;
	}
	if(pos == 1){
		insertFirst(a); return;
	}
	else if(pos == n + 1 ){
		insertLast(a); return;
	}
	sv p = a;
	for(int i = 1; i < pos - 1; i++){
		p = p->next;
	}
	sv tmp = makeNode();
	tmp->next = p->next;
	p->next = tmp;
}

//xoa phan tu o dau
void deleteFirst(sv &a){
	if(a == NULL) return;
	a = a->next;
}

//xoa phan tu o cuoi
void deleteLast(sv &a){
	if(a == NULL) return;
	sv truoc = NULL, sau = a;
	while(sau->next != NULL){
		truoc = sau;
		sau = sau->next;
	}
	if(truoc == NULL){
		a = NULL;
	}
	else{
		truoc->next = NULL;
	}
}

//Xoa o giua
void deleteMiddle(sv &a, int pos){
	if(pos <=0 || pos > Size(a)) return;
	sv truoc = NULL, sau = a;
	for(int i = 1; i < pos; i++){
		truoc = sau;
		sau = sau->next;
	}
	if(truoc == NULL){
		a = a->next;
	}
	else{
		truoc->next = sau->next;
	}
}

void in(Student s){
	cout << "--------------------------------\n";
	cout << "ID : " << s.id << endl;
	cout << "Ho ten :" << s.name << endl;
	cout << "Email :" << s.email << endl;
	cout << "GPA : " << fixed << setprecision(2) << s.gpa << endl; 
	cout << "--------------------------------\n";
}

void inds(sv a){
	cout << "Danh sach sinh vien :\n";
	while(a != NULL){
		in(a->s);
		a = a->next;
	}
	cout << endl;
}

void SapXepGPA(sv &a){
	for(sv p = a; p->next != NULL; p = p->next){
		sv min = p;
		for(sv q = p->next; q != NULL; q = q->next){
			if(q->s.gpa < min->s.gpa){
				min = q;
			}
		}
		Student tmp = min->s;
		min->s = p->s;
		p->s = tmp;
	}
}
void SapXepID(sv &a){
	for(sv p = a; p->next != NULL; p = p->next){
		sv min = p;
		for(sv q = p->next; q != NULL; q = q->next){
			if(q->s.id < min->s.id){
				min = q;
			}
		}
		Student tmp = min->s;
		min->s = p->s;
		p->s = tmp;
	}
}

//Tim kiem trong dslk
//Tim phan tu lon nhat, nho nhat
//Tim kiem sinh vien theo ten, theo ma, id ...


void DSLK_Student(){
	sv dslk = NULL;
	while(1){
		cout << "-----------------MENU---------------\n";
		cout << "1. Chen sinh vien vao dau danh sach\n";
		cout << "2. Chen sinh vien vao cuoi danh sach\n";
		cout << "3. Chen sinh vien vao giua danh sach\n";
		cout << "4. Xoa phan tu o dau\n";
		cout << "5. Xoa phan tu o cuoi\n";
		cout << "6. Xoa phan tu o giua\n";
		cout << "7. Duyet danh sach lien ket\n";
		cout << "8. Sap xep cac sinh vien trong dslk theo gpa\n";
		cout << "9. Sap xep cac sinh vien trong dslk theo ID\n";
		cout << "0. Thoat !\n";
		cout << "-------------------------------------\n";
		cout << "Nhap lua chon :";
		int lc; cin >> lc;
			if(lc == 1){
				insertFirst(dslk);
			}
			else if(lc == 2){
				insertLast(dslk);
			}
			else if(lc == 3){
				int pos; cout << "Nhap vi tri can chen :"; cin >> pos;
				insertMiddle(dslk, pos);
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
				inds(dslk);
			}
			else if(lc == 8){
				SapXepGPA(dslk);
			}
			else if(lc == 9){
				SapXepID(dslk);
			}
			else if(lc == 0){
				break;
			}
	}
	return;
}
int main(){
    //solve();
    DSLK_Student();
    return 0;
}
