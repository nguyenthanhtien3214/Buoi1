#include <stdio.h>
#include <stdlib.h>

void chiaMang(int a[], int b[], int n, int m) {
    if (n != m) {
        printf("Hai mang phai co cung kich thuoc.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        if (b[i] == 0) {
            printf("Phep chia tai vi tri %d khong hop le (chia cho 0).\n", i);
        }
        else {
            printf("a[%d] / b[%d] = %.2f\n", i, i, (float)a[i] / b[i]);
        }
    }
}

int main() {
    int n, m;

    printf("Nhap so luong phan tu cua mang a: ");
    scanf_s("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));
    printf("Nhap cac phan tu cua mang a: ");
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &a[i]);
    }

    printf("Nhap so luong phan tu cua mang b: ");
    scanf_s("%d", &m);
    int* b = (int*)malloc(m * sizeof(int));
    printf("Nhap cac phan tu cua mang b: ");
    for (int i = 0; i < m; i++) {
        scanf_s("%d", &b[i]);
    }

    chiaMang(a, b, n, m);

    free(a);
    free(b);

    return 0;
}
