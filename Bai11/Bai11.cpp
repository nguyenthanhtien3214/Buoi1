#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void xuatCucTieu(int arr[], int n) {
    if (n < 3) {
        printf("Khong co so cuc tieu\n");
        return;
    }
    printf("Cac so cuc tieu la: ");
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void xoaPhanTu(int arr[], int* n, int k) {
    if (k < 0 || k >= *n) {
        printf("Vi tri k khong hop le\n");
        return;
    }
    for (int i = k; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void themPhanTu(int arr[], int* n, int x, int k) {
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

void chuyenChanLenDau(int arr[], int n) {
    int* temp = (int*)malloc(n * sizeof(int));
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            temp[index++] = arr[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            temp[index++] = arr[i];
        }
    }
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
    free(temp);
}

int kiemTraXenKe(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if ((arr[i] % 2 == 0 && arr[i + 1] % 2 == 0) || (arr[i] % 2 != 0 && arr[i + 1] % 2 != 0)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int arr[100];
    int n, choice, x, k;

    printf("Nhap so luong phan tu: ");
    scanf_s("%d", &n);

    printf("Nhap cac phan tu cua mang: ");
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);
    }

    do {
        printf("\nMenu:\n");
        printf("1. Xuat cac so cuc tieu\n");
        printf("2. Xoa phan tu tai vi tri k\n");
        printf("3. Them phan tu x tai vi tri k\n");
        printf("4. Chuyen so chan len dau mang, so le xuong cuoi mang\n");
        printf("5. Kiem tra mang co chua chan le xen ke khong\n");
        printf("6. Thoat\n");
        printf("Nhap lua chon: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            xuatCucTieu(arr, n);
            break;
        case 2:
            printf("Nhap vi tri k: ");
            scanf_s("%d", &k);
            xoaPhanTu(arr, &n, k);
            printf("Mang sau khi xoa: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 3:
            printf("Nhap phan tu x: ");
            scanf_s("%d", &x);
            printf("Nhap vi tri k: ");
            scanf_s("%d", &k);
            themPhanTu(arr, &n, x, k);
            printf("Mang sau khi them: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 4:
            chuyenChanLenDau(arr, n);
            printf("Mang sau khi chuyen chan len dau: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 5:
            if (kiemTraXenKe(arr, n)) {
                printf("Mang co chua chan le xen ke.\n");
            }
            else {
                printf("Mang khong chua chan le xen ke.\n");
            }
            break;
        case 6:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 6);

    return 0;
}
