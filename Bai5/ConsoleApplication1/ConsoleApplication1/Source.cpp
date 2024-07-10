#include <stdio.h>
#include <conio.h>

int main() {
	int a, b, c;
	printf("Nhập ba số nguyên a, b, c: ");
	scanf_s("%d %d %d", &a, &b, &c);

	if (a - b == 0) {
		printf("Lỗi: Phép chia cho 0 không hợp lệ.\n");
	}
	else {
		float result = (float)c / (a - b);
		printf("Kết quả của c / (a - b) là: %.2f\n", result);
	}

	_getch(); 
	return 0;
}