#include <stdio.h>
// Define để cố định 1 giá trị
#define MAX_LENGHT 1000

// Hàm sắp xếp theo thuật toán sắp xếp nổi bọt
void bubbleSort(int arr[], int n){
    // Nếu không có hoán đổi thì dừng sớm
    int multipleSwap = 0;
    for (int i = 0; i < n - 1; i++){
        multipleSwap = 0;
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                multipleSwap = 1;
            }
        }
        if(!multipleSwap){
            break;
        }
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
        // Gọi hàm sắp xếp nổi bọt
        bubbleSort(arr, n);
        // In ra mảng sau khi sắp xếp
        printf("after:");
        printArray(arr, n);
    }while(n <= 0 || n >= MAX_LENGHT);

    return 0;
}
