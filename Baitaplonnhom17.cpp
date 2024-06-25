#include <stdio.h>
#include <string.h>

#define SO_BENH_NHAN_TOI_DA 100
#define DO_DAI_TEN 100
#define DO_DAI_LICH_SU 500
#define DO_DAI_CHAN_DOAN 500
#define DO_DAI_DON_THUOC 500
#define DO_DAI_KET_QUA 500
#define SO_HOA_DON_TOI_DA 100
#define DO_DAI_TEN 100
#define DO_DAI_MO_TA 500

// Cau truc du lieu Benh Nhan
typedef struct {
    int id;
    char ten[DO_DAI_TEN];
    int tuoi;
    char lich_su[DO_DAI_LICH_SU];
    char chan_doan[DO_DAI_CHAN_DOAN];
    char don_thuoc[DO_DAI_DON_THUOC];
    char ket_qua_xet_nghiem[DO_DAI_KET_QUA];
} BenhNhan;




BenhNhan benh_nhan[SO_BENH_NHAN_TOI_DA]; // Mang luu tru cac benh nhan
int so_luong_benh_nhan = 0; // Dem so luong benh nhan

// Ham tao benh nhan moi
void tao_benh_nhan() {
    if (so_luong_benh_nhan >= SO_BENH_NHAN_TOI_DA) {
        printf("Khong the them benh nhan moi. Bo nho day.\n");
        return;
    }
    BenhNhan benh_nhan_moi;
    benh_nhan_moi.id = so_luong_benh_nhan + 1;
    printf("Nhap ten benh nhan: ");
    scanf(" %[^\n]%*c", benh_nhan_moi.ten);
    printf("Nhap tuoi benh nhan: ");
    scanf("%d", &benh_nhan_moi.tuoi);
    getchar(); // De tieu thu ky tu newline sau scanf
    printf("Nhap lich su kham benh: ");
    scanf(" %[^\n]%*c", benh_nhan_moi.lich_su);
    printf("Nhap chan doan: ");
    scanf(" %[^\n]%*c", benh_nhan_moi.chan_doan);
    printf("Nhap don thuoc: ");
    scanf(" %[^\n]%*c", benh_nhan_moi.don_thuoc);
    printf("Nhap ket qua xet nghiem: ");
    scanf(" %[^\n]%*c", benh_nhan_moi.ket_qua_xet_nghiem);
    benh_nhan[so_luong_benh_nhan] = benh_nhan_moi;
    so_luong_benh_nhan++;
    printf("Da them benh nhan thanh cong!\n");
}

// Ham cap nhat thong tin benh nhan
void cap_nhat_benh_nhan() {
    int id;
    printf("Nhap ID benh nhan can cap nhat: ");
    scanf("%d", &id);
    getchar(); // De tieu thu ky tu newline sau scanf
    if (id < 1 || id > so_luong_benh_nhan) {
        printf("ID benh nhan khong hop le.\n");
        return;
    }
    BenhNhan *bn = &benh_nhan[id - 1];
    printf("Nhap ten moi cho benh nhan: ");
    scanf(" %[^\n]%*c", bn->ten);
    printf("Nhap tuoi moi cho benh nhan: ");
    scanf("%d", &bn->tuoi);
    getchar(); // De tieu thu ky tu newline sau scanf
    printf("Nhap lich su kham benh moi: ");
    scanf(" %[^\n]%*c", bn->lich_su);
    printf("Nhap chan doan moi: ");
    scanf(" %[^\n]%*c", bn->chan_doan);
    printf("Nhap don thuoc moi: ");
    scanf(" %[^\n]%*c", bn->don_thuoc);
    printf("Nhap ket qua xet nghiem moi: ");
    scanf(" %[^\n]%*c", bn->ket_qua_xet_nghiem);
    printf("Cap nhat thong tin benh nhan thanh cong!\n");
}

// Ham tim kiem benh nhan
void tim_kiem_benh_nhan() {
    int id;
    printf("Nhap ID benh nhan can tim kiem: ");
    scanf("%d", &id);
    getchar(); // De tieu thu ky tu newline sau scanf
    if (id < 1 || id > so_luong_benh_nhan) {
        printf("Khong tim thay benh nhan.\n");
        return;
    }
    BenhNhan bn = benh_nhan[id - 1];
    printf("ID benh nhan: %d\n", bn.id);
    printf("Ten: %s\n", bn.ten);
    printf("Tuoi: %d\n", bn.tuoi);
    printf("Lich su kham benh: %s\n", bn.lich_su);
    printf("Chan doan: %s\n", bn.chan_doan);
    printf("Don thuoc: %s\n", bn.don_thuoc);
    printf("Ket qua xet nghiem: %s\n", bn.ket_qua_xet_nghiem);
}

// Ham liet ke danh sach benh nhan
void danh_sach_benh_nhan() {
    if (so_luong_benh_nhan == 0) {
        printf("Chua co benh nhan nao.\n");
        return;
    }
    for (int i = 0; i < so_luong_benh_nhan; i++) {
        printf("ID benh nhan: %d\n", benh_nhan[i].id);
        printf("Ten: %s\n", benh_nhan[i].ten);
        printf("Tuoi: %d\n", benh_nhan[i].tuoi);
        printf("Lich su kham benh: %s\n", benh_nhan[i].lich_su);
        printf("Chan doan: %s\n", benh_nhan[i].chan_doan);
        printf("Don thuoc: %s\n", benh_nhan[i].don_thuoc);
        printf("Ket qua xet nghiem: %s\n", benh_nhan[i].ket_qua_xet_nghiem);
        printf("----------------------\n");
    }
}

// Ham ghi nhan thong tin kham benh, chan doan va dieu tri
void ghi_nhan_kham_benh() {
    int id;
    printf("Nhap ID benh nhan can ghi nhan thong tin kham benh: ");
    scanf("%d", &id);
    getchar(); // De tieu thu ky tu newline sau scanf
    if (id < 1 || id > so_luong_benh_nhan) {
        printf("ID benh nhan khong hop le.\n");
        return;
    }
    BenhNhan *bn = &benh_nhan[id - 1];
    printf("Nhap thong tin chan doan: ");
    scanf(" %[^\n]%*c", bn->chan_doan);
    printf("Nhap don thuoc: ");
    scanf(" %[^\n]%*c", bn->don_thuoc);
    printf("Nhap ket qua xet nghiem: ");
    scanf(" %[^\n]%*c", bn->ket_qua_xet_nghiem);
    printf("Ghi nhan thong tin kham benh thanh cong!\n");
}


// Cau truc du lieu hoa don
typedef struct {
    int id;
    char ten[DO_DAI_TEN];
    char mo_ta[DO_DAI_MO_TA];
    float so_tien;
    char ngay[11];
} HoaDon;

HoaDon hoa_don[SO_HOA_DON_TOI_DA]; // Mang luu tru cac hoa don
int so_luong_hoa_don = 0; // Ðem so luong hoa don

// Ham tao hoa don moi
void tao_hoa_don() {
    if (so_luong_hoa_don >= SO_HOA_DON_TOI_DA) {
        printf("Khong the them hoa don moi, bo nho day.\n");
        return;
    }
    HoaDon hoa_don_moi;
    hoa_don_moi.id = so_luong_hoa_don + 1;
    printf("Nhap ten hoa don: ");
    scanf(" %[^\n]%*c", hoa_don_moi.ten);
    printf("Nhap mo ta hoa don: ");
    scanf(" %[^\n]%*c", hoa_don_moi.mo_ta);
    printf("Nhap so tien: ");
    scanf("%f", &hoa_don_moi.so_tien);
    getchar(); // De tieu thu ky tu newline sau scanf
    printf("Nhap ngay (dd/mm/yyyy): ");
    scanf(" %[^\n]%*c", hoa_don_moi.ngay);
    hoa_don[so_luong_hoa_don] = hoa_don_moi;
    so_luong_hoa_don++;
    printf("Ða them hoa don thanh cong!\n");
}

// Ham cap nhat hoa don
void cap_nhat_hoa_don() {
    int id;
    printf("Nhap ID hoa don can cap nhat: ");
    scanf("%d", &id);
    getchar(); // Ðe tieu thu ky tu newline sau scanf
    if (id < 1 || id > so_luong_hoa_don) {
        printf("ID hoa don khong hop le.\n");
        return;
    }
    HoaDon *hd = &hoa_don[id - 1];
    printf("Nhap ten moi cho hoa don: ");
    scanf(" %[^\n]%*c", hd->ten);
    printf("Nhap mo ta moi cho hoa don: ");
    scanf(" %[^\n]%*c", hd->mo_ta);
    printf("Nhap so tien moi: ");
    scanf("%f", &hd->so_tien);
    getchar(); // De tieu thu ky tu newline sau scanf
    printf("Nhap ngay moi (dd/mm/yyyy): ");
    scanf(" %[^\n]%*c", hd->ngay);
    printf("Cap nhat hoa don thanh cong!\n");
}

// Ham tim kiem hoa don
void tim_kiem_hoa_don() {
    int id;
    printf("Nhap ID hoa don can tim kiem : ");
    scanf("%d", &id);
    getchar(); // De tieu thu ky tu newline sau scanf
    if (id < 1 || id > so_luong_hoa_don) {
        printf("Khong tim thay hoa don.\n");
        return;
    }
    HoaDon hd = hoa_don[id - 1];
    printf("ID hoa don: %d\n", hd.id);
    printf("Ten: %s\n", hd.ten);
    printf("Mo ta: %s\n", hd.mo_ta);
    printf("So tien: %.2f\n", hd.so_tien);
    printf("Ngay: %s\n", hd.ngay);
}

// ham liet ke danh sach hoa don
void danh_sach_hoa_don() {
    if (so_luong_hoa_don == 0) {
        printf("Chua co hoa don nao.\n");
        return;
    }
    for (int i = 0; i < so_luong_hoa_don; i++) {
        printf("ID hoa don: %d\n", hoa_don[i].id);
        printf("Ten: %s\n", hoa_don[i].ten);
        printf("Mo ta: %s\n", hoa_don[i].mo_ta);
        printf("So tien: %.2f\n", hoa_don[i].so_tien);
        printf("Ngay: %s\n", hoa_don[i].ngay);
        printf("----------------------\n");
    }
}

// Hsm theo doi va lap bao cao doanh thu, chi phi
void bao_cao_doanh_thu_chi_phi() {
    float tong_doanh_thu = 0, tong_chi_phi = 0;
    for (int i = 0; i < so_luong_hoa_don; i++) {
        if (hoa_don[i].so_tien > 0) {
            tong_doanh_thu += hoa_don[i].so_tien;
        } else {
            tong_chi_phi += hoa_don[i].so_tien;
        }
    }
    printf("Tong danh thu: %.2f\n", tong_doanh_thu);
    printf("Tang chi phi: %.2f\n", tong_chi_phi);
    printf("Loi nhuan: %.2f\n", tong_doanh_thu + tong_chi_phi);
}

// Ham quan ly bao hiem y te
void quan_ly_bao_hiem_y_te() {
    // Gia dinh rang thong tin bao hiem duoc quan ly trong cac hoa don 
    printf("Danh sách các hóa don b?o hi?m y t?:\n");
    for (int i = 0; i < so_luong_hoa_don; i++) {
        if (strstr(hoa_don[i].mo_ta, "b?o hi?m") != NULL) {
            printf("ID hóa don: %d\n", hoa_don[i].id);
            printf("Ten: %s\n", hoa_don[i].ten);
            printf("Mo ta: %s\n", hoa_don[i].mo_ta);
            printf("So tien: %.2f\n", hoa_don[i].so_tien);
            printf("Ngay: %s\n", hoa_don[i].ngay);
            printf("----------------------\n");
        }
    }
}



// Ham chinh (main) chua menu
// Ham chinh (main) chua menu
int main() {
    int lua_chon;
    do {
        printf("He thong quan ly ho so benh nhan\n");
        printf("1. Quan ly benh nhan\n");
        printf("2. Quan ly kham benh\n");
        printf("3. Quan ly hoa don va thanh toan\n"); // S?a tiêu d? menu cho dúng
        printf("4. Theo doi va lap bao cao doanh thu, chi phi\n"); // Chuy?n theo dõi báo cáo doanh thu vào m?c 4
        printf("5. Thoat\n"); // Chuy?n thoát thành m?c 5
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &lua_chon);
        getchar(); // De tieu thu ky tu newline sau scanf
        switch (lua_chon) {
            case 1: {
                int lua_chon_nho;
                do {
                    printf("\nQuan ly benh nhan:\n");
                    printf("1. Tao ho so benh nhan\n");
                    printf("2. Cap nhat thong tin benh nhan\n");
                    printf("3. Tra cuu thong tin benh nhan\n");
                    printf("4. Danh sach benh nhan\n");
                    printf("5. Quay lai\n");
                    printf("Nhap lua chon cua ban: ");
                    scanf("%d", &lua_chon_nho);
                    getchar(); // De tieu thu ky tu newline sau scanf

                    switch (lua_chon_nho) {
                        case 1:
                            tao_benh_nhan();
                            break;
                        case 2:
                            cap_nhat_benh_nhan();
                            break;
                        case 3:
                            tim_kiem_benh_nhan();
                            break;
                        case 4:
                            danh_sach_benh_nhan();
                            break;
                        case 5:
                            printf("Quay lai menu chinh...\n");
                            break;
                        default:
                            printf("Lua chon khong hop le. Vui long thu lai.\n");
                    }
                } while (lua_chon_nho != 5);
                break;
            }
            
            
            case 2: {
                int lua_chon_kham_benh;
                do {
                    printf("\nQuan ly kham benh:\n");
                    printf("1. Ghi nhan thong tin kham benh, chan doan va dieu tri\n");
                    printf("2. Quay lai\n");
                    printf("Nhap lua chon cua ban: ");
                    scanf("%d", &lua_chon_kham_benh);
                    getchar(); // De tieu thu ky tu newline sau scanf

                    switch (lua_chon_kham_benh) {
                        case 1:
                            ghi_nhan_kham_benh();
                            break;
                        case 2:
                            printf("Quay lai menu chinh...\n");
                            break;
                        default:
                            printf("Lua chon khong hop le. Vui long thu lai.\n");
                    }
                } while (lua_chon_kham_benh != 2);
                break;
            }
            
            case 3: {
                int lua_chon_nho;
                do {
                    printf("\nQuan ly hoa don va thanh toan:\n");
                    printf("1. Tao hoa don\n");
                    printf("2. Cap nhat hoa don\n");
                    printf("3. Tra cuu hoa don\n");
                    printf("4. Danh sach hoa don\n");
                    printf("5. Quay lai\n");
                    printf("Nhap lua chon cua ban: ");
                    scanf("%d", &lua_chon_nho);
                    getchar(); // De tieu thu ky tu newline sau scanf

                    switch (lua_chon_nho) {
                        case 1:
                            tao_hoa_don();
                            break;
                        case 2:
                            cap_nhat_hoa_don();
                            break;
                        case 3:
                            tim_kiem_hoa_don();
                            break;
                        case 4:
                            danh_sach_hoa_don();
                            break;
                        case 5:
                            printf("Quay lai menu chinh...\n");
                            break;
                        default:
                            printf("Lua chon khong hop le. Vui long thu lai.\n");
                    }
                } while (lua_chon_nho != 5);
                break;
            }
            
            case 4:
                bao_cao_doanh_thu_chi_phi(); // Gui ham theo doi va bao cao doanh thu, chi phi
                break;

            case 5:
                printf("Thoat chuong trinh...\n");
                break;
                
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (lua_chon != 5); // Sua phong lap de thoat chuong trinh
    return 0;
}

