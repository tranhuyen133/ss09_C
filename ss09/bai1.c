#include <stdio.h>

int main() {
    const int MAX_SIZE = 100; 
    int arr[MAX_SIZE]; 
    int currentLength = 0; 
    int n, i, value, addIndex;

    printf("Nhap so phan tu muon nhap (toi da %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n > MAX_SIZE || n < 0) {
        printf("So phan tu kh�ng hop le\n");
        return 1;
    }

    printf("Nhap c�c phan tu:\n");
    for (i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i);
        scanf("%d", &arr[i]);
    }
    currentLength = n;

    printf("Nhap gi� tri muon th�m: ");
    scanf("%d", &value);
    printf("Nhap vi tr� muon th�m (tu 0 den %d): ", MAX_SIZE - 1);
    scanf("%d", &addIndex);

    if (addIndex < 0 || addIndex >= MAX_SIZE) {
        printf("Vi tr� kh�ng hop le\n");
        return 1;
    }

    if (addIndex >= currentLength) {
        arr[addIndex] = value;
        currentLength = addIndex + 1;
    } else {
        for (i = currentLength; i > addIndex; i--) {
            arr[i] = arr[i - 1];
        }
        arr[addIndex] = value;
        currentLength++;
    }

    printf("Mang sau khi th�m phan tu:\n");
    for (i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

