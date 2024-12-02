#include <stdio.h>

int main() {
    const int MAX_SIZE = 100; 
    int arr[MAX_SIZE]; 
    int currentLength = 0; 
    int n, i, choice, value, index;

    while (1) {
        // Hi?n th? menu
        printf("\nMENU\n");
        printf("1. Nhap vào mang\n");
        printf("2. Hien thi mang\n");
        printf("3. Thêm phan tu\n");
        printf("4. Sua phan tu\n");
        printf("5. Xóa phan tu\n");
        printf("6. Thoát\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Nhap so phan tu muon nhap (toi da %d): ", MAX_SIZE);
                scanf("%d", &n);
                if (n > MAX_SIZE || n < 0) {
                    printf("So phan tu không hop le\n");
                    break;
                }
                currentLength = n;
                printf("Nhap cac phan tu:\n");
                for (i = 0; i < n; i++) {
                    printf("Phan tu thu %d: ", i);
                    scanf("%d", &arr[i]);
                }
                break;

            case 2:
                printf("Mang hien tai:\n");
                if (currentLength == 0) {
                    printf("Mang rong!\n");
                } else {
                    for (i = 0; i < currentLength; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;

            case 3: 
                if (currentLength >= MAX_SIZE) {
                    printf("Mang dã day! Không the thêm phan tu.\n");
                    break;
                }
                printf("Nhap giá tri muon thêm: ");
                scanf("%d", &value);
                printf("Nhap vi tri muon thêm (tu 0 den %d): ", currentLength);
                scanf("%d", &index);
                if (index < 0 || index > currentLength) {
                    printf("Vi trí không hop le.\n");
                    break;
                }
                for (i = currentLength; i > index; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[index] = value;
                currentLength++;
                break;

            case 4: 
                printf("Nhap vi tri can sua (tu 0 den %d): ", currentLength - 1);
                scanf("%d", &index);
                if (index < 0 || index >= currentLength) {
                    printf("Vi trí không hop le! Vui lòng thu lai.\n");
                    break;
                }
                printf("Nhap giá tri moi: ");
                scanf("%d", &value);
                arr[index] = value;
                break;

            case 5: 
                printf("Nhap vi trí can xóa (tu 0 den %d): ", currentLength - 1);
                scanf("%d", &index);
                if (index < 0 || index >= currentLength) {
                    printf("Vi trí không hop le.\n");
                    break;
                }
                for (i = index; i < currentLength - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                currentLength--;
                break;

            case 6: 
                printf("Thoát chuong trình.\n");
                return 0;

            default:
                printf("Lua chon không hop le\n");
        }
    }
}

