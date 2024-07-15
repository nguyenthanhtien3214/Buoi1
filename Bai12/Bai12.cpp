#include <stdio.h>

typedef struct {
    int tu; 
    int mau; 
} PhanSo;


double giaTriThuc(PhanSo ps) {
    return (double)ps.tu / ps.mau;
}

PhanSo timPhanSoLonNhat(PhanSo arr[], int n) {
    PhanSo max = arr[0];
    for (int i = 1; i < n; i++) {
        if (giaTriThuc(arr[i]) > giaTriThuc(max)) {
            max = arr[i];
        }
    }
    return max;
}

PhanSo timPhanSoNhoNhat(PhanSo arr[], int n) {
    PhanSo min = arr[0];
    for (int i = 1; i < n; i++) {
        if (giaTriThuc(arr[i]) < giaTriThuc(min)) {
            min = arr[i];
        }
    }
    return min;
}

void xoaPhanTu(PhanSo arr[], int* n, int k) {
    if (k < 0 || k >= *n) {
        printf("Vi tri k khong hop le\n");
        return;
    }
    for (int i = k; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void themPhanTu(PhanSo arr[], int* n, PhanSo x, int k) {
    if (k < 0 || k > *n) {
        printf("Vi tri k khong hop le\n");
        return;
    }
    for (int i = *n; i > k; i--) {
        arr[i] = arr[i - 1];
    }
    arr[k] = x;
    (*n)++;
}

void nhapPhanSo(PhanSo* ps) {
    printf("Nhap tu so: ");
    scanf_s("%d", &ps->tu);
    printf("Nhap mau so: ");
    scanf_s("%d", &ps->mau);
    while (ps->mau == 0) {
        printf("Mau so khong duoc bang 0. Nhap lai mau so: ");
        scanf_s("%d", &ps->mau);
    }
}

void xuatPhanSo(PhanSo ps) {
    printf("%d/%d ", ps.tu, ps.mau);
}

int main() {
    PhanSo arr[100];
    int n, choice, k;
    PhanSo x;

    printf("Nhap so luong phan tu: ");
    scanf_s("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap phan so thu %d:\n", i + 1);
        nhapPhanSo(&arr[i]);
    }

    do {
        printf("\nMenu:\n");
        printf("1. Tim phan so lon nhat\n");
        printf("2. Tim phan so nho nhat\n");
        printf("3. Xoa phan tu tai vi tri k\n");
        printf("4. Them phan tu x tai vi tri k\n");
        printf("5. Thoat\n");
        printf("Nhap lua chon: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1: {
            PhanSo max = timPhanSoLonNhat(arr, n);
            printf("Phan so lon nhat: ");
            xuatPhanSo(max);
            printf("\n");
            break;
        }
        case 2: {
            PhanSo min = timPhanSoNhoNhat(arr, n);
            printf("Phan so nho nhat: ");
            xuatPhanSo(min);
            printf("\n");
            break;
        }
        case 3:
            printf("Nhap vi tri k: ");
            scanf_s("%d", &k);
            xoaPhanTu(arr, &n, k);
            printf("Mang sau khi xoa: ");
            for (int i = 0; i < n; i++) {
                xuatPhanSo(arr[i]);
            }
            printf("\n");
            break;
        case 4:
            printf("Nhap phan so can them:\n");
            nhapPhanSo(&x);
            printf("Nhap vi tri k: ");
            scanf_s("%d", &k);
            themPhanTu(arr, &n, x, k);
            printf("Mang sau khi them: ");
            for (int i = 0; i < n; i++) {
                xuatPhanSo(arr[i]);
            }
            printf("\n");
            break;
        case 5:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 5);

    return 0;
}
