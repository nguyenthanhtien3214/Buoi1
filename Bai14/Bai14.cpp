#include <stdio.h>
#include <string.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char hoTen[100];
    Date ngaySinh;
    char gioiTinh[10];
} NguoiLaoDong;

int tinhTuoi(Date ngaySinh, int namHienTai) {
    return namHienTai - ngaySinh.year;
}

int kiemTraNgoaiLe(NguoiLaoDong nguoi, int namHienTai) {
    int tuoi = tinhTuoi(nguoi.ngaySinh, namHienTai);

    if (strcmp(nguoi.gioiTinh, "nam") == 0) {
        if (tuoi < 18 || tuoi > 62) {
            return 101;
        }
    }
    else if (strcmp(nguoi.gioiTinh, "nu") == 0) {
        if (tuoi < 18 || tuoi > 60) {
            return 101;
        }
    }
    else {
        return -1; 
    }
    return 0;
}

void tinhThoiGianNghiHuu(NguoiLaoDong nguoi) {
    int tuoiNghiHuu = 0;

    if (strcmp(nguoi.gioiTinh, "nam") == 0) {
        if (nguoi.ngaySinh.year >= 1961 && nguoi.ngaySinh.year <= 1963) tuoiNghiHuu = 62;
        else if (nguoi.ngaySinh.year == 1964) tuoiNghiHuu = 61 + 3 / 12;
        else if (nguoi.ngaySinh.year == 1965) tuoiNghiHuu = 61 + 6 / 12;
        else if (nguoi.ngaySinh.year == 1966) tuoiNghiHuu = 61 + 9 / 12;
        else if (nguoi.ngaySinh.year >= 1967) tuoiNghiHuu = 62;
    }
    else if (strcmp(nguoi.gioiTinh, "nu") == 0) {
        if (nguoi.ngaySinh.year >= 1966 && nguoi.ngaySinh.year <= 1970) tuoiNghiHuu = 60;
        else if (nguoi.ngaySinh.year == 1971) tuoiNghiHuu = 58 + 4 / 12;
        else if (nguoi.ngaySinh.year == 1972) tuoiNghiHuu = 58 + 8 / 12;
        else if (nguoi.ngaySinh.year == 1973) tuoiNghiHuu = 59;
        else if (nguoi.ngaySinh.year == 1974) tuoiNghiHuu = 59 + 4 / 12;
        else if (nguoi.ngaySinh.year == 1975) tuoiNghiHuu = 59 + 8 / 12;
        else if (nguoi.ngaySinh.year >= 1976) tuoiNghiHuu = 60;
    }

    int namNghiHuu = nguoi.ngaySinh.year + tuoiNghiHuu;
    printf("%s se nghi huu vao nam %d\n", nguoi.hoTen, namNghiHuu);
}

int main() {
    NguoiLaoDong nguoi;
    int namHienTai = 2024;
    int err;

    printf("Nhap ho ten: ");
    fgets(nguoi.hoTen, sizeof(nguoi.hoTen), stdin);
    nguoi.hoTen[strcspn(nguoi.hoTen, "\n")] = '\0'; 

    printf("Nhap ngay sinh (dd mm yyyy): ");
    if (scanf_s("%d %d %d", &nguoi.ngaySinh.day, &nguoi.ngaySinh.month, &nguoi.ngaySinh.year) != 3) {
        printf("Loi: Ngay sinh khong hop le.\n");
        return 1;
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    printf("Nhap gioi tinh (nam/nu): ");
    fgets(nguoi.gioiTinh, sizeof(nguoi.gioiTinh), stdin);
    nguoi.gioiTinh[strcspn(nguoi.gioiTinh, "\n")] = '\0'; 

    err = kiemTraNgoaiLe(nguoi, namHienTai);
    if (err == 101) {
        printf("Loi 101: Tuoi khong thuoc trong tuoi lao dong.\n");
        return 1;
    }
    else if (err == -1) {
        printf("Loi: Gioi tinh khong hop le.\n");
        return 1;
    }

    tinhThoiGianNghiHuu(nguoi);

    return 0;
}
