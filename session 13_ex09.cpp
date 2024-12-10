#include <stdio.h>

int check_ngto(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void inputarr(int n, int m, int arr[][100]) {
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void printf_arr(int n, int m, int arr[][100]) {
    printf("Gia tri cac phan tu cua ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void printf_ngto(int n, int m, int arr[][100]) {
    printf("Cac phan tu la so nguyen to trong ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (check_ngto(arr[i][j])) {
                printf("%d ", arr[i][j]);
            }
        }
    }
    printf("\n");
}

void printf_bien(int n, int m, int arr[][100]) {
    printf("Cac phan tu o duong bien cua mang:\n");
    for (int j = 0; j < m; j++) {
        printf("%d ", arr[0][j]); 
    }
    for (int i = 1; i < n - 1; i++) {
        printf("%d ", arr[i][0]); 
        printf("%d ", arr[i][m - 1]); 
    }
    for (int j = 0; j < m; j++) {
        printf("%d ", arr[n - 1][j]); 
    }
    printf("\n");
}

void printf_goc(int n, int m, int arr[][100]) {
    printf("Cac phan tu o goc cua mang:\n");
    printf("%d %d %d %d\n", arr[0][0], arr[0][m - 1], arr[n - 1][0], arr[n - 1][m - 1]);
}

void printf_chinh_phu(int n, int m, int arr[][100]) {
    printf("Cac phan tu tren duong cheo chinh va phu:\n");
    for (int i = 0; i < n && i < m; i++) {
        printf("%d ", arr[i][i]); 
        if (i < m) {
            printf("%d ", arr[i][m - 1 - i]); 
        }
    }
    printf("\n");
}

int main() {
    int n, m;
    printf("Nhap so hang: ");
    scanf("%d", &n);
    printf("Nhap so cot: ");
    scanf("%d", &m);

    int arr[100][100];
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap gia tri cua mang\n");
        printf("2. In gia tri cac phan tu co trong mang\n");
        printf("3. In cac phan tu la so nguyen to trong mang\n");
        printf("4. In cac phan tu o duong bien cua mang\n");
        printf("5. In cac phan tu o 4 goc cua mang\n");
        printf("6. In cac phan tu tren duong cheo chinh va phu\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputarr(n, m, arr);
                break;
            case 2:
                printf_arr(n, m, arr);
                break;
            case 3:
                printf_ngto(n, m, arr);
                break;
            case 4:
                printf_bien(n, m, arr);
                break;
            case 5:
                printf_goc(n, m, arr);
                break;
            case 6:
                printf_chinh_phu(n, m, arr);
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 0);

    return 0;
}

    					
	      			
