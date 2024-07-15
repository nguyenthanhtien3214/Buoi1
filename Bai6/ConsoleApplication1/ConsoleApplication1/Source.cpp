#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ERR_CODE "errcode"
#define CURRENT_YEAR 2021

typedef struct {
	char hoTen[50];
	int ngay;
	int thang;
	int nam;
	char gioiTinh[10];
} NguoiLaoDong;

void nhapThongTin(NguoiLaoDong* nld) {
	printf("Nhap ho ten: ");
	getchar(); 
	fgets(nld->hoTen, sizeof(nld->hoTen), stdin);
	nld->hoTen[strcspn(nld->hoTen, "\n")] = 0; 

	printf("Nhap ngay sinh (dd/mm/yyyy): ");
	scanf_s("%d/%d/%d", &nld->ngay, &nld->thang, &nld->nam);

	printf("Nhap gioi tinh (nam/nu): ");
	scanf_s("%s", nld->gioiTinh);
}

void tinhThoiGianNghiHuu(NguoiLaoDong nld) {
	int tuoi = CURRENT_YEAR - nld.nam;
	int tuoiNghiHuu = (strcmp(nld.gioiTinh, "nam") == 0) ? 62 : 60;

	if (tuoi < 18 || (strcmp(nld.gioiTinh, "nam") == 0 && tuoi > 62) || (strcmp(nld.gioiTinh, "nu") == 0 && tuoi > 60)) {
		printf("Loi ma 101\n");
		return;
	}

	if (strcmp(nld.gioiTinh, "nam") != 0 && strcmp(nld.gioiTinh, "nu") != 0) {
		printf("%s\n", ERR_CODE);
		return;
	}

	int namNghiHuu = nld.nam + tuoiNghiHuu;
	printf("%s, gioi tinh %s, sinh ngay %02d/%02d/%d. Hien tai (nam %d) da %d tuoi. Thoi gian nghi huu la thang %02d/%d.\n",
		nld.hoTen, nld.gioiTinh, nld.ngay, nld.thang, nld.nam, CURRENT_YEAR, tuoi, nld.thang, namNghiHuu);
}

int main() {
	NguoiLaoDong nld;

	nhapThongTin(&nld);
	tinhThoiGianNghiHuu(nld);

	printf("Nhan phim bat ky de ket thuc chuong trinh...");
	getchar(); 
	getchar(); 
	return 0;