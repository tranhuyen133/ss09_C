#include <stdio.h>

int main() {
    const int MAX_SIZE = 100; 
    int arr[MAX_SIZE]; 
    int currentLength = 0; 
    int n, i, deleteIndex;

    printf("Nhap so phan tu muon nhap (toi da %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n > MAX_SIZE || n < 0) {
        printf("So phan tu khong hop le\n");
        return 1;
    }

    printf("Nhap các phan tu:\n");
    for (i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i);
        scanf("%d", &arr[i]);
    }
    currentLength = n;

    printf("Mang ban dau:\n");
    for (i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Nhap vi trí can xóa (tu 0 den %d): ", currentLength - 1);
    scanf("%d", &deleteIndex);

    if (deleteIndex < 0 || deleteIndex >= currentLength) {
        printf("Vi trí không hop le\n");
        return 1;
    }

    for (i = deleteIndex; i < currentLength - 1; i++) {
        arr[i] = arr[i + 1]; 
    }

    currentLength--; 

    printf("Mang sau khi xóa:\n");
    for (i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

