#include <stdio.h>
#define MAX_LENGHT 1000

// Hàm hoán đổi 2 phần tử
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm chia mảng và trả về chỉ số pivot sau cùng
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++){
        if (arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Hàm quick sort đệ quy
void quickSort(int arr[], int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);
        // Sắp xếp 2 nửa mảng
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Haàm in mảng
void printArray(int arr[], int n){
    printf("[");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
        if(i < n - 1){
            printf(",");
        }
    }
    printf("]");
    printf("\n");
}
int main(){
    int n;

    //Nhập số phần tử của mảng
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    // Kiểm tra số phần tử của mảng
    if (n <= 0 || n >=  MAX_LENGHT){
        printf("So luong phan tu khong hop le\n");
        return 0;
    }
    int arr[MAX_LENGHT];
    // Nhập các phần tử của mảng
    for(int i = 0; i < n; i++){
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    // In ra mảng trước khi sắp xếp
    printf("before = ");
    printArray(arr, n);
    // Gọi hàm sắp xếp nổi bọt
    quickSort(arr,0, n-1);
    // In ra mảng sau khi sắp xếp
    printf("after = ");
    printArray(arr, n);
    return 0;
}
