#include <stdio.h>
#include <math.h>

int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int arr[100]; 
    int n, i, choice, value, index, count, total, max, min;

    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu v� gi� tri c�c phan tu\n");
        printf("2. In ra gi� tri c�c phan tu dang quan l�\n");
        printf("3. In ra gi� tri c�c phan tu chan v� t�nh tong\n");
        printf("4. In ra gi� tri lon nhat v� nho nhat trong mang\n");
        printf("5. In ra c�c phan tu l� so nguy�n tu trong mang v� t�nh tong\n");
        printf("6. Nhap v�o mot so v� thong k� trong mang c� bao nhi�u phan tu d�\n");
        printf("7. Th�m mot phan tu v�o vi tr� chi dinh\n");
        printf("8. Tho�t\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Nh?p s? ph?n t? v� gi� tr? c�c ph?n t?
                printf("Nhap so phan tu can nhap: ");
                scanf("%d", &n);
                if (n > 100 || n < 0) {
                    printf("So phan tu kh�ng hop le.\n");
                    break;
                }
                printf("Nhap c�c phan tu:\n");
                for (i = 0; i < n; i++) {
                    printf("Phan tu thu %d: ", i);
                    scanf("%d", &arr[i]);
                }
                break;

            case 2: // In ra gi� tr? c�c ph?n t? dang qu?n l�
                printf("Gi� tri c�c phan tu dang quan l�:\n");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 3: // In ra gi� tr? c�c ph?n t? ch?n v� t�nh t?ng
                printf("C�c ph?n t? ch?n:\n");
                total = 0;
                for (i = 0; i < n; i++) {
                    if (arr[i] % 2 == 0) {
                        printf("%d ", arr[i]);
                        total += arr[i];
                    }
                }
                printf("\nTong c�c phan tu chon: %d\n", total);
                break;

            case 4: // In ra gi� tr? l?n nh?t v� nh? nh?t trong m?ng
                if (n == 0) {
                    printf("Mang rong!\n");
                    break;
                }
                max = arr[0];
                min = arr[0];
                for (i = 1; i < n; i++) {
                    if (arr[i] > max) max = arr[i];
                    if (arr[i] < min) min = arr[i];
                }
                printf("Gi� tri lon nhat trong mang: %d\n", max);
                printf("Gi� tri nho nhat trong mang: %d\n", min);
                break;

            case 5: 
                printf("C�c phan tu l� so nguy�n to:\n");
                total = 0;
                for (i = 0; i < n; i++) {
                    if (isPrime(arr[i])) {
                        printf("%d ", arr[i]);
                        total += arr[i];
                    }
                }
                printf("\nTong c�c s? nguy�n t?: %d\n", total);
                break;

            case 6: // Nh?p v�o m?t s? v� th?ng k� trong m?ng c� bao nhi�u ph?n t? d�
                printf("Nhap so can thong k�: ");
                scanf("%d", &value);
                count = 0;
                for (i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        count++;
                    }
                }
                printf("So %d xuat hien %d lon trong mang.\n", value, count);
                break;

            case 7: // Th�m m?t ph?n t? v�o v? tr� ch? d?nh
                if (n >= 100) {
                    printf("Mang d� day! Kh�ng the th�m phan tu.\n");
                    break;
                }
                printf("Nhap gi� tri phan tu muon th�m: ");
                scanf("%d", &value);
                printf("Nhap vi tr� muon th�m (tu 0 den %d): ", n);
                scanf("%d", &index);
                if (index < 0 || index > n) {
                    printf("Vi tr� kh�ng hop l?.\n");
                    break;
                }
                for (i = n; i > index; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[index] = value;
                n++;
                printf("Phan tu %d d� duoc th�m v�o va tr� %d.\n", value, index);
                break;

            case 8: // Tho�t
                printf("Tho�t chuong tr�nh.\n");
                return 0;

            default:
                printf("Lua chon kh�ng hop le! Vui l�ng thu lai.\n");
        }
    }
}

