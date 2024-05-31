#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SO_BENH_NHAN_TOI_DA 100
#define DO_DAI_TEN_TOI_DA 50

typedef struct {
    int ma_so;
    char ten[DO_DAI_TEN_TOI_DA];
    int tuoi;
    char gioi_tinh;
    char chan_doan[DO_DAI_TEN_TOI_DA];
} BenhNhan;

BenhNhan danh_sach_benh_nhan[SO_BENH_NHAN_TOI_DA];
int so_luong_benh_nhan = 0;

void xoaKiTuThua(char* str) {
    str[strcspn(str, "\n")] = 0; // Xóa kí tu newline '\n' do fgets thêm vào
}
void themBenhNhan() {
    if (so_luong_benh_nhan >= SO_BENH_NHAN_TOI_DA) {
        printf("Danh sach benh nhan da day!\n");
        return;
    }

    BenhNhan benh_nhan_moi;
    benh_nhan_moi.ma_so = so_luong_benh_nhan + 1;

    printf("\nNhap ten benh nhan: ");
    getchar();
    fgets(benh_nhan_moi.ten, sizeof(benh_nhan_moi.ten), stdin);
    xoaKiTuThua(benh_nhan_moi.ten);

    printf("\nNhap tuoi benh nhan: ");
    scanf("%d", &benh_nhan_moi.tuoi);

    printf("\nNhap gioi tinh benh nhan (M/F): ");
    scanf(" %c", &benh_nhan_moi.gioi_tinh);

    printf("\nNhap chan doan: ");
    getchar();
    fgets(benh_nhan_moi.chan_doan, sizeof(benh_nhan_moi.chan_doan), stdin);
    xoaKiTuThua(benh_nhan_moi.chan_doan);
   

    danh_sach_benh_nhan[so_luong_benh_nhan++] = benh_nhan_moi;

    printf("Them benh nhan thanh cong!\n");
}

void hienThiDanhSachBenhNhan() {
    if (so_luong_benh_nhan == 0) {
        printf("Không co benh nhan trong he thong.\n");
        return;
    }

    for (int i = 0; i < so_luong_benh_nhan; i++) {
        printf("Ma so benh nhan: %d\n", danh_sach_benh_nhan[i].ma_so);
        printf("Ten: %s\n", danh_sach_benh_nhan[i].ten);
        printf("Tuoi: %d\n", danh_sach_benh_nhan[i].tuoi);
        printf("Gioi tinh: %c\n", danh_sach_benh_nhan[i].gioi_tinh);
        printf("Chan doan: %s\n", danh_sach_benh_nhan[i].chan_doan);
        printf("-------------------\n");
    }
}

int main() {
    int lua_chon;

    while (1) {
        printf("He thong quan ly phong kham\n");
        printf("1.Them benh nhan\n");
        printf("2.Hien thi danh sach benh nhan\n");
        printf("3.Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &lua_chon);

        switch (lua_chon) {
            case 1:
                themBenhNhan();
                break;
            case 2:
                hienThiDanhSachBenhNhan();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Lua chon khong hop ly, vui long thu lai.\n");
        }
    }

    return 0;
}
