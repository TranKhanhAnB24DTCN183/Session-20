#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char maSanPham[20];
    char tenSanPham[100];
    float giaNhap;
    float giaBan;
    int soLuong;
} SanPham;

void nhapThongTinSanPham(SanPham ds[], int *n, float *doanhThu);
void hienThiDanhSachSanPham(SanPham ds[], int n);
void nhapSanPham(SanPham ds[], int *n, float *doanhThu);
void capNhatThongTinSanPham(SanPham ds[], int n);
void sapXepSanPhamTheoGia(SanPham ds[], int n, int tangDan);
void timKiemSanPham(SanPham ds[], int n);
void banSanPham(SanPham ds[], int n, float *doanhThu);
void hienThiDoanhThu(float doanhThu);

int main() {
    SanPham ds[MAX];
    int n = 0;
    float doanhThu = 0;
    int luaChon;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin san pham.\n");
        printf("2. Hien thi danh sach san pham.\n");
        printf("3. Nhap san pham.\n");
        printf("4. Cap nhat thong tin san pham.\n");
        printf("5. Sap xep san pham theo gia (tang/giam).\n");
        printf("6. Tim kiem san pham.\n");
        printf("7. Ban san pham.\n");
        printf("8. Hien thi doanh thu hien tai.\n");
        printf("9. Thoat.\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapThongTinSanPham(ds, &n, &doanhThu);
                break;
            case 2:
                hienThiDanhSachSanPham(ds, n);
                break;
            case 3:
                nhapSanPham(ds, &n, &doanhThu);
                break;
            case 4:
                capNhatThongTinSanPham(ds, n);
                break;
            case 5: {
                int tangDan;
                printf("Sap xep tang (1) hay giam (0): ");
                scanf("%d", &tangDan);
                sapXepSanPhamTheoGia(ds, n, tangDan);
                break;
            }
            case 6:
                timKiemSanPham(ds, n);
                break;
            case 7:
                banSanPham(ds, n, &doanhThu);
                break;
            case 8:
                hienThiDoanhThu(doanhThu);
                break;
            case 9:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le, vui long thu lai.\n");
        }
    } while (luaChon != 9);

    return 0;
}

void nhapThongTinSanPham(SanPham ds[], int *n, float *doanhThu) {
    printf("Nhap so luong san pham: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Nhap thong tin san pham thu %d:\n", i + 1);
        printf("Ma san pham: ");
        scanf("%s", ds[i].maSanPham);
        printf("Ten san pham: ");
        scanf(" %[^\n]", ds[i].tenSanPham);
        printf("Gia nhap: ");
        scanf("%f", &ds[i].giaNhap);
        printf("Gia ban: ");
        scanf("%f", &ds[i].giaBan);
        printf("So luong: ");
        scanf("%d", &ds[i].soLuong);
        *doanhThu -= ds[i].soLuong * ds[i].giaNhap;
    }
}

void hienThiDanhSachSanPham(SanPham ds[], int n) {
    for (int i = 0; i < n; i++) {
        printf("San pham %d:\n", i + 1);
        printf("  Ma san pham: %s\n", ds[i].maSanPham);
        printf("  Ten san pham: %s\n", ds[i].tenSanPham);
        printf("  Gia nhap: %.2f\n", ds[i].giaNhap);
        printf("  Gia ban: %.2f\n", ds[i].giaBan);
        printf("  So luong: %d\n", ds[i].soLuong);
    }
}

void nhapSanPham(SanPham ds[], int *n, float *doanhThu) {
    char maSanPham[20];
    int soLuongNhap;
    printf("Nhap ma san pham: ");
    scanf("%s", maSanPham);
    for (int i = 0; i < *n; i++) {
        if (strcmp(ds[i].maSanPham, maSanPham) == 0) {
            printf("Nhap so luong: ");
            scanf("%d", &soLuongNhap);
            ds[i].soLuong += soLuongNhap;
            *doanhThu -= soLuongNhap * ds[i].giaNhap;
            return;
        }
    }
    printf("San pham moi:\n");
    strcpy(ds[*n].maSanPham, maSanPham);
    printf("Ten san pham: ");
    scanf(" %[^\n]", ds[*n].tenSanPham);
    printf("Gia nhap: ");
    scanf("%f", &ds[*n].giaNhap);
    printf("Gia ban: ");
    scanf("%f", &ds[*n].giaBan);
    printf("So luong: ");
    scanf("%d", &ds[*n].soLuong);
    *doanhThu -= ds[*n].soLuong * ds[*n].giaNhap;
    (*n)++;
}

void capNhatThongTinSanPham(SanPham ds[], int n) {
    char maSanPham[20];
    printf("Nhap ma san pham can cap nhat: ");
    scanf("%s", maSanPham);
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].maSanPham, maSanPham) == 0) {
            printf("Ten san pham moi: ");
            scanf(" %[^\n]", ds[i].tenSanPham);
            printf("Gia nhap moi: ");
            scanf("%f", &ds[i].giaNhap);
            printf("Gia ban moi: ");
            scanf("%f", &ds[i].giaBan);
            printf("So luong moi: ");
            scanf("%d", &ds[i].soLuong);
            printf("Cap nhat thanh cong.\n");
            return;
        }
    }
    printf("Khong tim thay san pham voi ma: %s\n", maSanPham);
}

void sapXepSanPhamTheoGia(SanPham ds[], int n, int tangDan) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((tangDan && ds[i].giaBan > ds[j].giaBan) || (!tangDan && ds[i].giaBan < ds[j].giaBan)) {
                SanPham temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
    printf("Sap xep thanh cong.\n");
}

void timKiemSanPham(SanPham ds[], int n) {
    char tenSanPham[100];
    printf("Nhap ten san pham can tim: ");
    scanf(" %[^\n]", tenSanPham);
    for (int i = 0; i < n; i++) {
        if (strstr(ds[i].tenSanPham, tenSanPham)) {
            printf("San pham:\n");
            printf("  Ma san pham: %s\n", ds[i].maSanPham);
            printf("  Ten san pham: %s\n", ds[i].tenSanPham);
            printf("  Gia nhap: %.2f\n", ds[i].giaNhap);
            printf("  Gia ban: %.2f\n", ds[i].giaBan);
            printf("  So luong: %d\n", ds[i].soLuong);
        }
    }
}

void banSanPham(SanPham ds[], int n, float *doanhThu) {
    char maSanPham[20];
    int soLuongBan;
    printf("Nhap ma san pham: ");
    scanf("%s", maSanPham);
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].maSanPham, maSanPham) == 0) {
            if (ds[i].soLuong == 0) {
                printf("Het hang.\n");
                return;
            }
            printf("Nhap so luong can ban: ");
            scanf("%d", &soLuongBan);
            if (soLuongBan > ds[i].soLuong) {
                printf("Khong con du hang.\n");
                return;
            }
            ds[i].soLuong -= soLuongBan;
            *doanhThu += soLuongBan * ds[i].giaBan;
            printf("Ban thanh cong.\n");
            return;
        }
    }
}
void hienThiDoanhThu(float doanhThu) {
    printf("Doanh thu hien tai: %.2f\n", doanhThu);
}

