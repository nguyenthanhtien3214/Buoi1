// 2001200628_NguyenThanhTien
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h>

void nhapM1C_SoNguyen(int* &a, int &n) {
	n = 10;
	a = (int*)malloc(n * sizeof(int)); // Cấp phát a có 10 phần tử
	for (int i = 0; i < n; i++) {
		*(a + i) = rand() % 100;
	}
}

void xuatM1C_SoNguyen(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("Phan tu thu %d co gia tri %d va dia chi o nho la %p\n", i, *(a + i), (a + i));
		printf("Phan tu thu %d co gia tri %d va dia chi o nho la %p\n", i, a[i], (a + i));
	}
}

void timPhanTuLonNhat(int* a, int n) {
	int* max = a;
	for (int i = 1; i < n; i++) {
		if (*(a + i) > *max) {
			max = a + i;
		}
	}
	printf("Phan tu lon nhat la %d tai dia chi %p\n", *max, max);
}

void timChanLeLonNhoNhat(int* a, int n) {
	int* chanMax = NULL;
	int* leMin = NULL;

	for (int i = 0; i < n; i++) {
		if (*(a + i) % 2 == 0) {
			if (chanMax == NULL || *(a + i) > *chanMax) {
				chanMax = a + i;
			}
		}
		else {
			if (leMin == NULL || *(a + i) < *leMin) {
				leMin = a + i;
			}
		}
	}

	if (chanMax) {
		printf("Phan tu chan lon nhat tai dia chi %p\n", chanMax);
	}
	else {
		printf("Khong co phan tu chan trong mang.\n");
	}

	if (leMin) {
		printf("Phan tu le nho nhat tai dia chi %p\n", leMin);
	}
	else {
		printf("Khong co phan tu le trong mang.\n");
	}
}

void xoaPhanTuKhong(int* &a, int &n) {
	int newSize = 0;
	for (int i = 0; i < n; i++) {
		if (*(a + i) != 0) {
			*(a + newSize) = *(a + i);
			newSize++;
		}
	}
	n = newSize;
	a = (int*)realloc(a, n * sizeof(int));
}

void themPhanTuSauDauTien(int* &a, int &n, int x) {
	a = (int*)realloc(a, (n + 1) * sizeof(int));
	for (int i = n; i > 1; i--) {
		*(a + i) = *(a + i - 1);
	}
	*(a + 1) = x;
	n++;
}

bool laSoChinhPhuong(int n) {
	int sqrt_n = (int)sqrt((double)n);
	return sqrt_n * sqrt_n == n;
}

int tongSoChinhPhuong(int* a, int n) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		if (laSoChinhPhuong(*(a + i))) {
			tong += *(a + i);
		}
	}
	return tong;
}

void xuatCucDai(int* a, int n) {
	for (int i = 0; i < n; i++) {
		if ((i == 0 && *(a + i) > *(a + i + 1)) ||
			(i == n - 1 && *(a + i) > *(a + i - 1)) ||
			(i > 0 && i < n - 1 && *(a + i) > *(a + i - 1) && *(a + i) > *(a + i + 1))) {
			printf("Cuc dai: %d tai dia chi %p\n", *(a + i), (a + i));
		}
	}
}

int main() {
	int* a;
	int n = 0;

	nhapM1C_SoNguyen(a, n);
	xuatM1C_SoNguyen(a, n);

	timPhanTuLonNhat(a, n);
	timChanLeLonNhoNhat(a, n);

	xoaPhanTuKhong(a, n);
	printf("Mang sau khi xoa cac phan tu 0:\n");
	xuatM1C_SoNguyen(a, n);

	themPhanTuSauDauTien(a, n, 7);
	printf("Mang sau khi them 7 sau phan tu dau tien:\n");
	xuatM1C_SoNguyen(a, n);

	int tong = tongSoChinhPhuong(a, n);
	printf("Tong cac phan tu la so chinh phuong: %d\n", tong);

	xuatCucDai(a, n);

	free(a);

	printf("Nhan phim bat ky de ket thuc chuong trinh...");
	getchar(); 
	return 0;
}
