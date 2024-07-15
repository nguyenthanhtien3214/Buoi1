#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int tu;
	int mau;
} PhanSo;

void nhapPhanSo(PhanSo* ps) {
	printf("Nhap tu so: ");
	scanf_s("%d", &ps->tu);
	do {
		printf("Nhap mau so (khac 0): ");
		scanf_s("%d", &ps->mau);
		if (ps->mau == 0) {
			printf("Mau so phai khac 0. Vui long nhap lai.\n");
		}
	} while (ps->mau == 0);
}

void xuatPhanSo(PhanSo ps) {
	printf("%d/%d\n", ps.tu, ps.mau);
}

void nhapMangPhanSo(PhanSo* mang, int kichThuoc) {
	for (int i = 0; i < kichThuoc; i++) {
		printf("Nhap phan so thu %d:\n", i + 1);
		nhapPhanSo(&mang[i]);
	}
}

void xuatMangPhanSo(PhanSo* mang, int kichThuoc) {
	for (int i = 0; i < kichThuoc; i++) {
		xuatPhanSo(mang[i]);
	}
}

void xuatPhanSoMauLonHonTu(PhanSo* mang, int kichThuoc) {
	printf("Cac phan so co mau > tu:\n");
	for (int i = 0; i < kichThuoc; i++) {
		if (mang[i].mau > mang[i].tu) {
			xuatPhanSo(mang[i]);
		}
	}
}

int demPhanSoChan(PhanSo* mang, int kichThuoc) {
	int count = 0;
	for (int i = 0; i < kichThuoc; i++) {
		if (mang[i].tu % 2 == 0 && mang[i].mau % 2 == 0) {
			count++;
		}
	}
	return count;
}

int uscln(int a, int b) {
	while (b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

PhanSo rutGonPhanSo(PhanSo ps) {
	int uc = uscln(ps.tu, ps.mau);
	ps.tu /= uc;
	ps.mau /= uc;
	return ps;
}

PhanSo tichPhanSo(PhanSo* mang, int kichThuoc) {
	PhanSo tich = { 1, 1 };
	for (int i = 0; i < kichThuoc; i++) {
		tich.tu *= mang[i].tu;
		tich.mau *= mang[i].mau;
	}
	return rutGonPhanSo(tich);
}

int soSanhPhanSo(PhanSo ps1, PhanSo ps2) {
	float giaTri1 = (float)ps1.tu / ps1.mau;
	float giaTri2 = (float)ps2.tu / ps2.mau;
	return giaTri1 > giaTri2;
}

PhanSo timPhanSoLonNhat(PhanSo* mang, int kichThuoc) {
	PhanSo max = mang[0];
	for (int i = 1; i < kichThuoc; i++) {
		if (soSanhPhanSo(mang[i], max)) {
			max = mang[i];
		}
	}
	return max;
}

int main() {
	int kichThuoc;

	printf("Nhap so luong phan so: ");
	scanf_s("%d", &kichThuoc);

	PhanSo* mang = (PhanSo*)malloc(kichThuoc * sizeof(PhanSo));

	nhapMangPhanSo(mang, kichThuoc);

	printf("Mang phan so vua nhap:\n");
	xuatMangPhanSo(mang, kichThuoc);

	xuatPhanSoMauLonHonTu(mang, kichThuoc);

	int soPhanSoChan = demPhanSoChan(mang, kichThuoc);
	printf("So luong phan so co tu va mau la so chan: %d\n", soPhanSoChan);

	printf("Mang phan so sau khi rut gon:\n");
	for (int i = 0; i < kichThuoc; i++) {
		mang[i] = rutGonPhanSo(mang[i]);
		xuatPhanSo(mang[i]);
	}

	PhanSo tich = tichPhanSo(mang, kichThuoc);
	printf("Tich cua cac phan so trong mang (sau khi rut gon): ");
	xuatPhanSo(tich);

	PhanSo max = timPhanSoLonNhat(mang, kichThuoc);
	printf("Phan so lon nhat trong mang: ");
	xuatPhanSo(max);

	free(mang);

	printf("Nhan phim bat ky de ket thuc chuong trinh...");
	getchar(); 
	getchar(); 
	return 0;
}