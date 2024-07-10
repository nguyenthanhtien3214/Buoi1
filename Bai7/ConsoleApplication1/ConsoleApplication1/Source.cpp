#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool laSoChinhPhuong(int n) {
	double canBacHai = sqrt((double)n); 
	return (canBacHai == (int)canBacHai);
}

void timMax(int *arr, int kichThuoc, int **phanTuMax) {
	*phanTuMax = arr;
	for (int i = 1; i < kichThuoc; i++) {
		if (*(arr + i) > **phanTuMax) {
			*phanTuMax = (arr + i);
		}
	}
}

void timChanLe(int *arr, int kichThuoc, int **phanTuChanMax, int **phanTuLeMin) {
	*phanTuChanMax = NULL;
	*phanTuLeMin = NULL;

	for (int i = 0; i < kichThuoc; i++) {
		if (*(arr + i) % 2 == 0) {
			if (*phanTuChanMax == NULL || *(arr + i) > **phanTuChanMax) {
				*phanTuChanMax = (arr + i);
			}
		}
		else {
			if (*phanTuLeMin == NULL || *(arr + i) < **phanTuLeMin) {
				*phanTuLeMin = (arr + i);
			}
		}
	}
}

void xoaPhanTuKhong(int **arr, int *kichThuoc) {
	int *mangMoi = (int*)malloc(*kichThuoc * sizeof(int));
	int kichThuocMoi = 0;

	for (int i = 0; i < *kichThuoc; i++) {
		if (*(*arr + i) != 0) {
			mangMoi[kichThuocMoi++] = *(*arr + i);
		}
	}

	*arr = (int*)realloc(*arr, kichThuocMoi * sizeof(int));
	for (int i = 0; i < kichThuocMoi; i++) {
		*(*arr + i) = mangMoi[i];
	}
	*kichThuoc = kichThuocMoi;

	free(mangMoi);
}

void themPhanTu(int **arr, int *kichThuoc, int x) {
	*arr = (int*)realloc(*arr, (*kichThuoc + 1) * sizeof(int));

	for (int i = *kichThuoc; i > 0; i--) {
		*(*arr + i) = *(*arr + i - 1);
	}
	*(*arr + 1) = x;
	(*kichThuoc)++;
}

int tongSoChinhPhuong(int *arr, int kichThuoc) {
	int tong = 0;
	for (int i = 0; i < kichThuoc; i++) {
		if (laSoChinhPhuong(*(arr + i))) {
			tong += *(arr + i);
		}
	}
	return tong;
}

void timCucDai(int *arr, int kichThuoc) {
	for (int i = 0; i < kichThuoc; i++) {
		if ((i == 0 && *(arr + i) > *(arr + i + 1)) ||
			(i == kichThuoc - 1 && *(arr + i) > *(arr + i - 1)) ||
			(i > 0 && i < kichThuoc - 1 && *(arr + i) > *(arr + i - 1) && *(arr + i) > *(arr + i + 1))) {
			printf("Cuc dai: %d tai dia chi %p\n", *(arr + i), (arr + i));
		}
	}
}

int main() {
	int kichThuoc = 10;
	int *arr = (int*)malloc(kichThuoc * sizeof(int));

	int giaTri[] = { 1, 3, 4, 5, 0, 16, 9, 0, 2, 4 };
	for (int i = 0; i < kichThuoc; i++) {
		arr[i] = giaTri[i];
	}

	int *phanTuMax;
	timMax(arr, kichThuoc, &phanTuMax);
	printf("Phan tu lon nhat: %d tai dia chi %p\n", *phanTuMax, phanTuMax);

	int *phanTuChanMax, *phanTuLeMin;
	timChanLe(arr, kichThuoc, &phanTuChanMax, &phanTuLeMin);
	if (phanTuChanMax != NULL) {
		printf("Phan tu chan lon nhat tai dia chi %p\n", phanTuChanMax);
	}
	else {
		printf("Khong co phan tu chan trong mang.\n");
	}
	if (phanTuLeMin != NULL) {
		printf("Phan tu le nho nhat tai dia chi %p\n", phanTuLeMin);
	}
	else {
		printf("Khong co phan tu le trong mang.\n");
	}

	xoaPhanTuKhong(&arr, &kichThuoc);
	printf("Mang sau khi xoa cac phan tu 0:\n");
	for (int i = 0; i < kichThuoc; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	themPhanTu(&arr, &kichThuoc, 7);
	printf("Mang sau khi them 7 sau phan tu dau tien:\n");
	for (int i = 0; i < kichThuoc; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	int tong = tongSoChinhPhuong(arr, kichThuoc);
	printf("Tong cac phan tu la so chinh phuong: %d\n", tong);

	timCucDai(arr, kichThuoc);

	free(arr);

	printf("Nhan phim bat ky de ket thuc chuong trinh...");
	getchar(); 
	getchar(); 
	return 0;
}
