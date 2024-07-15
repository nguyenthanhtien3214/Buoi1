#include <stdio.h>

int main() {

    int a, b;

    printf("Nhap vao gia tri cua a: ");
    scanf_s("%d", &a);
    printf("Nhap vao gia tri cua b: ");
    scanf_s("%d", &b);


    int* pa = &a;
    int* pb = &b;

    int sum, diff, product;
    float quotient;

    sum = *pa + *pb;
    diff = *pa - *pb;
    product = (*pa) * (*pb);
    if (*pb != 0) {
        quotient = (float)(*pa) / (*pb);
    }
    else {
        quotient = 0.0;
    }

    printf("Tong: %d, dia chi: %p\n", sum, (void*)&sum);
    printf("Hieu: %d, dia chi: %p\n", diff, (void*)&diff);
    printf("Tich: %d, dia chi: %p\n", product, (void*)&product);
    printf("Thuong: %f, dia chi: %p\n", quotient, (void*)&quotient);

    return 0;
}
