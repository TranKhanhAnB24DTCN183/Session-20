#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char maSach[20];
    char tenSach[100];
    char tacGia[50];
    float gia;
} Sach;

void nhapThongTinSach(Sach ds[], int *n);
void hienThiThongTinSach(Sach ds[], int n);
void themSachVaoViTri(Sach ds[], int *n, int viTri);
void xoaSachTheoMa(Sach ds[], int *n, char maSach[]);
void capNhatThongTinSach(Sach ds[], int n, char maSach[]);
void sapXepSachTheoGia(Sach ds[], int n, int tangDan);
void timKiemSachTheoTen(Sach ds[], int n, char tenSach[]);

int main() {
    Sach ds[MAX];
    int n = 0;
    int luaChon;
    char maSach[20];
    char tenSach[100];

    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin sach.\n");
        printf("2. Hien thi thong tin sach.\n");
        printf("3. Them sach vao vi tri.\n");
        printf("4. Xoa sach theo ma sach.\n");
        printf("5. Cap nhat thong tin sach theo ma sach.\n");
        printf("6. Sap xep sach theo gia (tang/giam).\n");
        printf("7. Tim kiem sach theo ten sach.\n");
        printf("8. Thoat.\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapThongTinSach(ds, &n);
                break;
            case 2:
                hienThiThongTinSach(ds, n);
                break;
            case 3: {
                int viTri;
                printf("Nhap vi tri muon them: ");
                scanf("%d", &viTri);
                themSachVaoViTri(ds, &n, viTri);
                break;
            }
            case 4:
                printf("Nhap ma sach can xoa: ");
                scanf("%s", maSach);
                xoaSachTheoMa(ds, &n, maSach);
                break;
            case 5:
                printf("Nhap ma sach can cap nhat: ");
                scanf("%s", maSach);
                capNhatThongTinSach(ds, n, maSach);
                break;
            case 6: {
                int tangDan;
                printf("Sap xep tang (1) hay giam (0): ");
                scanf("%d", &tangDan);
                sapXepSachTheoGia(ds, n, tangDan);
                break;
            }
            case 7:
                printf("Nhap ten sach can tim: ");
                scanf(" %[^\n]", tenSach);
                timKiemSachTheoTen(ds, n, tenSach);
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le, vui long thu lai.\n");
        }
    } while (luaChon != 8);

    return 0;
}

void nhapThongTinSach(Sach ds[], int *n) {
    printf("Nhap so luong sach: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Nhap thong tin sach thu %d:\n", i + 1);
        printf("Ma sach: ");
        scanf("%s", ds[i].maSach);
        printf("Ten sach: ");
        scanf(" %[^\n]", ds[i].tenSach);
        printf("Tac gia: ");
        scanf(" %[^\n]", ds[i].tacGia);
        printf("Gia: ");
        scanf("%f", &ds[i].gia);
    }
}

void hienThiThongTinSach(Sach ds[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Sach %d:\n", i + 1);
        printf("  Ma sach: %s\n", ds[i].maSach);
        printf("  Ten sach: %s\n", ds[i].tenSach);
        printf("  Tac gia: %s\n", ds[i].tacGia);
        printf("  Gia: %.2f\n", ds[i].gia);
    }
}

void themSachVaoViTri(Sach ds[], int *n, int viTri) {
    if (viTri < 0 || viTri > *n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for (int i = *n; i > viTri; i--) {
        ds[i] = ds[i - 1];
    }
    printf("Nhap thong tin sach moi:\n");
    printf("Ma sach: ");
    scanf("%s", ds[viTri].maSach);
    printf("Ten sach: ");
    scanf(" %[^\n]", ds[viTri].tenSach);
    printf("Tac gia: ");
    scanf(" %[^\n]", ds[viTri].tacGia);
    printf("Gia: ");
    scanf("%f", &ds[viTri].gia);
    (*n)++;
}

void xoaSachTheoMa(Sach ds[], int *n, char maSach[]) {
    for (int i = 0; i < *n; i++) {
        if (strcmp(ds[i].maSach, maSach) == 0) {
            for (int j = i; j < *n - 1; j++) {
                ds[j] = ds[j + 1];
            }
            (*n)--;
            printf("Xoa sach thanh cong.\n");
            return;
        }
    }
    printf("Khong tim thay sach voi ma: %s\n", maSach);
}

void capNhatThongTinSach(Sach ds[], int n, char maSach[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].maSach, maSach) == 0) {
            printf("Nhap thong tin moi:\n");
            printf("Ten sach: ");
            scanf(" %[^\n]", ds[i].tenSach);
            printf("Tac gia: ");
            scanf(" %[^\n]", ds[i].tacGia);
            printf("Gia: ");
            scanf("%f", &ds[i].gia);
            printf("Cap nhat thanh cong.\n");
            return;
        }
    }
    printf("Khong tim thay sach voi ma: %s\n", maSach);
}

void sapXepSachTheoGia(Sach ds[], int n, int tangDan) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((tangDan && ds[i].gia > ds[j].gia) || (!tangDan && ds[i].gia < ds[j].gia)) {
                Sach temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
    printf("Sap xep thanh cong.\n");
}

void timKiemSachTheoTen(Sach ds[], int n, char tenSach[]) {
    int timThay = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(ds[i].tenSach, tenSach)) {
            printf("Tim thay sach:\n");
            printf("  Ma sach: %s\n", ds[i].maSach);
            printf("  Ten sach: %s\n", ds[i].tenSach);
            printf("  Tac gia: %s\n", ds[i].tacGia);
            printf("  Gia: %.2f\n", ds[i].gia);
            timThay = 1;
        }
    }
    if (!timThay) {
        printf("Khong tim thay sach voi ten: %s\n", tenSach);
    }
}

