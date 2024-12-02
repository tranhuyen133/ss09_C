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
        printf("1. Nhap so phan tu và giá tri các phan tu\n");
        printf("2. In ra giá tri các phan tu dang quan lý\n");
        printf("3. In ra giá tri các phan tu chan và tính tong\n");
        printf("4. In ra giá tri lon nhat và nho nhat trong mang\n");
        printf("5. In ra các phan tu là so nguyên tu trong mang và tính tong\n");
        printf("6. Nhap vào mot so và thong kê trong mang có bao nhiêu phan tu dó\n");
        printf("7. Thêm mot phan tu vào vi trí chi dinh\n");
        printf("8. Thoát\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Nh?p s? ph?n t? và giá tr? các ph?n t?
                printf("Nhap so phan tu can nhap: ");
                scanf("%d", &n);
                if (n > 100 || n < 0) {
                    printf("So phan tu không hop le.\n");
                    break;
                }
                printf("Nhap các phan tu:\n");
                for (i = 0; i < n; i++) {
                    printf("Phan tu thu %d: ", i);
                    scanf("%d", &arr[i]);
                }
                break;

            case 2: // In ra giá tr? các ph?n t? dang qu?n lý
                printf("Giá tri các phan tu dang quan lý:\n");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 3: // In ra giá tr? các ph?n t? ch?n và tính t?ng
                printf("Các ph?n t? ch?n:\n");
                total = 0;
                for (i = 0; i < n; i++) {
                    if (arr[i] % 2 == 0) {
                        printf("%d ", arr[i]);
                        total += arr[i];
                    }
                }
                printf("\nTong các phan tu chon: %d\n", total);
                break;

            case 4: // In ra giá tr? l?n nh?t và nh? nh?t trong m?ng
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
                printf("Giá tri lon nhat trong mang: %d\n", max);
                printf("Giá tri nho nhat trong mang: %d\n", min);
                break;

            case 5: 
                printf("Các phan tu là so nguyên to:\n");
                total = 0;
                for (i = 0; i < n; i++) {
                    if (isPrime(arr[i])) {
                        printf("%d ", arr[i]);
                        total += arr[i];
                    }
                }
                printf("\nTong các s? nguyên t?: %d\n", total);
                break;

            case 6: // Nh?p vào m?t s? và th?ng kê trong m?ng có bao nhiêu ph?n t? dó
                printf("Nhap so can thong kê: ");
                scanf("%d", &value);
                count = 0;
                for (i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        count++;
                    }
                }
                printf("So %d xuat hien %d lon trong mang.\n", value, count);
                break;

            case 7: // Thêm m?t ph?n t? vào v? trí ch? d?nh
                if (n >= 100) {
                    printf("Mang dã day! Không the thêm phan tu.\n");
                    break;
                }
                printf("Nhap giá tri phan tu muon thêm: ");
                scanf("%d", &value);
                printf("Nhap vi trí muon thêm (tu 0 den %d): ", n);
                scanf("%d", &index);
                if (index < 0 || index > n) {
                    printf("Vi trí không hop l?.\n");
                    break;
                }
                for (i = n; i > index; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[index] = value;
                n++;
                printf("Phan tu %d dã duoc thêm vào va trí %d.\n", value, index);
                break;

            case 8: // Thoát
                printf("Thoát chuong trình.\n");
                return 0;

            default:
                printf("Lua chon không hop le! Vui lòng thu lai.\n");
        }
    }
}

