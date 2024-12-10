#include <stdio.h>


int inputarr(int arr[]) {
    int n;
    printf("Nh?p s? ph?n t? (t?i da 100): ");
    scanf("%d", &n);
    if (n > 100) {
        printf("S? ph?n t? kh�ng h?p l?! Gi?i h?n t?i da l� 100.\n");
        n = 100;
    }
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    return n;
}


void printf_arr(int n, int arr[]) {
    printf("Gi� tr? c�c ph?n t? dang qu?n l�:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int them_arr(int n, int arr[]) {
    if (n >= 100) {
        printf("M?ng d?y, kh�ng th? th�m ph?n t?.\n");
        return n;
    }
    int vitri_them, phantu_them;
    printf("Nh?p v? tr� mu?n th�m (0-%d): ", n);
    scanf("%d", &vitri_them);
    if (vitri_them < 0 || vitri_them > n) {
        printf("V? tr� kh�ng h?p l?.\n");
        return n;
    }
    printf("Nh?p ph?n t? c?n th�m: ");
    scanf("%d", &phantu_them);
    for (int i = n; i > vitri_them; i--) {
        arr[i] = arr[i - 1];
    }
    arr[vitri_them] = phantu_them;
    return n + 1;
}


int xoa_arr(int n, int arr[]) {
    int vitri_xoa;
    printf("Nh?p v? tr� mu?n x�a (0-%d): ", n - 1);
    scanf("%d", &vitri_xoa);
    if (vitri_xoa < 0 || vitri_xoa >= n) {
        printf("V? tr� kh�ng h?p l?.\n");
        return n;
    }
    for (int i = vitri_xoa; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return n - 1;
}


void sapxep_arrtang(int n, int arr[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


void sapxep_arrgiam(int n, int arr[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


int linearSearch(int n, int arr[], int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}


int binarySearch(int n, int arr[], int value) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}


int main() {
    int n = 0;
    int arr[100];
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nh?p m?ng\n");
        printf("2. In m?ng\n");
        printf("3. Th�m ph?n t?\n");
        printf("4. X�a ph?n t?\n");
        printf("5. S?p x?p tang d?n\n");
        printf("6. S?p x?p gi?m d?n\n");
        printf("7. T�m ki?m tuy?n t�nh\n");
        printf("8. T�m ki?m nh? ph�n\n");
        printf("0. Tho�t\n");
        printf("L?a ch?n: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                n = inputarr(arr);
                break;
            case 2:
                printf_arr(n, arr);
                break;
            case 3:
                n = them_arr(n, arr);
                break;
            case 4:
                n = xoa_arr(n, arr);
                break;
            case 5:
                sapxep_arrtang(n, arr);
                printf("M?ng sau khi s?p x?p tang d?n:\n");
                printf_arr(n, arr);
                break;
            case 6:
                sapxep_arrgiam(n, arr);
                printf("M?ng sau khi s?p x?p gi?m d?n:\n");
                printf_arr(n, arr);
                break;
            case 7: {
                int value;
                printf("Nh?p gi� tr? c?n t�m: ");
                scanf("%d", &value);
                int pos = linearSearch(n, arr, value);
                if (pos != -1) {
                    printf("T�m th?y t?i v? tr�: %d\n", pos);
                } else {
                    printf("Kh�ng t�m th?y gi� tr? n�y.\n");
                }
                break;
            }
            case 8: {
                int value;
                printf("Nh?p gi� tr? c?n t�m: ");
                scanf("%d", &value);
                sapxep_arrtang(n, arr); 
                int pos = binarySearch(n, arr, value);
                if (pos != -1) {
                    printf("T�m th?y t?i v? tr�: %d\n", pos);
                } else {
                    printf("Kh�ng t�m th?y gi� tr? n�y.\n");
                }
                break;
            }
            case 0:
                printf("Tho�t chuong tr�nh.\n");
                break;
            default:
                printf("L?a ch?n kh�ng h?p l?.\n");
        }
    } while (choice != 0);

    return 0;
}

