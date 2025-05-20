#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 100
#define FILE_NAME "transportasi.txt"

typedef struct {
    char rute[MAX_STR];
    char jadwal[MAX_STR];
    int penumpang;
    int kapasitas;
} Transportasi;

void simpanKeFile(Transportasi t) {
    FILE *file = fopen(FILE_NAME, "a");
    if (!file) {
        printf("Gagal membuka file!\n");
        return;
    }
    fprintf(file, "%s|%s|%d|%d\n", t.rute, t.jadwal, t.penumpang, t.kapasitas);
    fclose(file);
}

int bacaDariFile(Transportasi *list) {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) return 0;

    int count = 0;
    char baris[256];
    while (fgets(baris, sizeof(baris), file)) {
        char *token = strtok(baris, "|");
        if (token) strcpy(list[count].rute, token);

        token = strtok(NULL, "|");
        if (token) strcpy(list[count].jadwal, token);

        token = strtok(NULL, "|");
        if (token) list[count].penumpang = atoi(token);

        token = strtok(NULL, "|");
        if (token) list[count].kapasitas = atoi(token);

        count++;
    }
    fclose(file);
    return count;
}

void tampilkanSemua() {
    Transportasi list[100];
    int n = bacaDariFile(list);

    printf("\n=== DATA TRANSPORTASI PUBLIK ===\n");
    for (int i = 0; i < n; i++) {
        float kepadatan = (list[i].kapasitas == 0) ? 0 : (float)list[i].penumpang / list[i].kapasitas * 100;
        printf("[%d] %s | %s | %d/%d (%.2f%%) - %s\n", i + 1, list[i].rute, list[i].jadwal,
               list[i].penumpang, list[i].kapasitas, kepadatan,
               (kepadatan >= 100.0f) ? "PENUH" : "TERSEDIA");
    }
    if (n == 0) printf("Belum ada data.\n");
}

void tambahData() {
    Transportasi t;
    getchar(); // bersihkan newline
    printf("Nama Rute\t\t: ");
    fgets(t.rute, MAX_STR, stdin); t.rute[strcspn(t.rute, "\n")] = '\0';
    printf("Jadwal (HH:MM)\t\t: ");
    fgets(t.jadwal, MAX_STR, stdin); t.jadwal[strcspn(t.jadwal, "\n")] = '\0';
    printf("Jumlah Penumpang\t: ");
    scanf("%d", &t.penumpang);
    printf("Kapasitas Maks\t\t: ");
    scanf("%d", &t.kapasitas);

    simpanKeFile(t);
    printf("Data berhasil ditambahkan.\n");
}

void perbaruiData() {
    Transportasi list[100];
    int n = bacaDariFile(list);
    tampilkanSemua();

    int idx;
    printf("Masukkan nomor data yang ingin diperbarui: ");
    scanf("%d", &idx); idx--;

    if (idx < 0 || idx >= n) {
        printf("Indeks tidak valid!\n");
        return;
    }

    getchar();
    printf("Rute baru\t\t: ");
    fgets(list[idx].rute, MAX_STR, stdin); list[idx].rute[strcspn(list[idx].rute, "\n")] = '\0';
    printf("Jadwal baru (HH:MM)\t: ");
    fgets(list[idx].jadwal, MAX_STR, stdin); list[idx].jadwal[strcspn(list[idx].jadwal, "\n")] = '\0';
    printf("Penumpang baru\t\t: ");
    scanf("%d", &list[idx].penumpang);
    printf("Kapasitas baru\t\t: ");
    scanf("%d", &list[idx].kapasitas);

    // tulis ulang semua data
    FILE *file = fopen(FILE_NAME, "w");
    for (int i = 0; i < n; i++) {
        fprintf(file, "%s|%s|%d|%d\n", list[i].rute, list[i].jadwal, list[i].penumpang, list[i].kapasitas);
    }
    fclose(file);
    printf("Data berhasil diperbarui.\n");
}

void hapusData() {
    Transportasi list[100];
    int n = bacaDariFile(list);
    tampilkanSemua();

    int idx;
    printf("Masukkan nomor data yang ingin dihapus: ");
    scanf("%d", &idx); idx--;

    if (idx < 0 || idx >= n) {
        printf("Indeks tidak valid!\n");
        return;
    }

    FILE *file = fopen(FILE_NAME, "w");
    for (int i = 0; i < n; i++) {
        if (i != idx) {
            fprintf(file, "%s|%s|%d|%d\n", list[i].rute, list[i].jadwal, list[i].penumpang, list[i].kapasitas);
        }
    }
    fclose(file);
    printf("Data berhasil dihapus.\n");
}

void menu() {
    int pilihan;
    do {
        system("clear");
        tampilkanSemua();
        printf("\n=== MENU TRANSPORTASI PUBLIK ===\n");
        printf("1. Tambah data\n");
        printf("2. Perbarui data\n");
        printf("3. Hapus data\n");
        printf("4. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: tambahData(); break;
            case 2: perbaruiData(); break;
            case 3: hapusData(); break;
            case 4: printf("Keluar...\n"); break;
            default: printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 4);
}

int main() {
    menu();
    return 0;
}
