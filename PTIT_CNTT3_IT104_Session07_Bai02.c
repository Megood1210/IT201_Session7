#include <stdio.h>
// Define để cố định 1 giá trị
#define MAX_LENGHT 1000

// Hàm sắp xếp theo thuật toán sắp xếp chọn
void selectionSort(int arr[], int n){
   for (int i = 0; i < n - 1; i++){
       int minIndex = i;
       // Tìm chỉ số phần tử nhỏ nhất trong đoạn chưa sắp xếp
       for (int j = i + 1; j < n; j++){
           if (arr[j] < arr[minIndex]){
               minIndex = j;
           }
       }
       // Hoán đổi
       if (minIndex != i){
           int temp = arr[i];
           arr[i] = arr[minIndex];
           arr[minIndex] = temp;
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
    //Nhập số phần tử của mảng
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
        selectionSort(arr, n);
        // In ra mảng sau khi sắp xếp
        printf("after:");
        printArray(arr, n);
    }while(n <= 0 || n >= MAX_LENGHT);

    return 0;
}

