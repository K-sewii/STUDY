#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct {
    char tenSach[MAX_LEN];
    char tacGia[MAX_LEN];
    float gia;
} Sach;

void nhapSach(Sach *s) {
    getchar(); // Xóa bộ đệm
    printf("Nhập tên sách: ");
    fgets(s->tenSach, MAX_LEN, stdin);
    s->tenSach[strcspn(s->tenSach, "\n")] = '\0'; // Xóa ký tự xuống dòng

    printf("Nhập tác giả: ");
    fgets(s->tacGia, MAX_LEN, stdin);
    s->tacGia[strcspn(s->tacGia, "\n")] = '\0'; // Xóa ký tự xuống dòng

    printf("Nhập giá sách (triệu đồng): ");
    scanf("%f", &s->gia);
}

void luuFile(Sach *ds, int n, const char *filename) {
    FILE *f = fopen(filename, "w");
    if (!f) {
        printf("Không thể mở file %s\n", filename);
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(f, "%s - %s - %.2f\n", ds[i].tenSach, ds[i].tacGia, ds[i].gia);
    }
    fclose(f);
}

void docFile(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Không thể mở file %s\n", filename);
        return;
    }
    char line[MAX_LEN * 2];
    while (fgets(line, sizeof(line), f)) {
        printf("%s", line);
    }
    fclose(f);
}

int main() {
    int n;
    printf("Nhập số lượng sách: ");
    scanf("%d", &n);

    Sach *ds = malloc(n * sizeof(Sach));
    if (!ds) {
        printf("Không đủ bộ nhớ!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nNhập thông tin sách %d:\n", i + 1);
        nhapSach(&ds[i]);
    }

    luuFile(ds, n, "books.txt");
    printf("\nDanh sách sách đã lưu vào file books.txt:\n");
    docFile("books.txt");

    free(ds);
    return 0;
}