#include <stdio.h>
// Define để cố định 1 giá trị
#define MAX_LENGHT 1000

// Hàm sắp xếp theo thuật toán sắp xếp chèn
void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Hàm in mảng
void printArray(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    int n, arr[MAX_LENGHT];

    do{
        printf("Nhap so phan tu cua mang: ");
        scanf("%d", &n);
        // Nhập các phần tử của mảng
        for(int i = 0; i < n; i++){
            printf("Nhap phan tu thu %d: ", i + 1);
            scanf("%d", &arr[i]);
        }
        // In ra mảng trước khi sắp xếp
        printf("before:");
        printArray(arr, n);
        // Gọi hàm sắp xếp chèn
        insertionSort(arr, n);
        // In ra mảng sau khi sắp xếp
        printf("after:");
        printArray(arr, n);
    }while(n <= 0 || n >= MAX_LENGHT);

    return 0;
}
