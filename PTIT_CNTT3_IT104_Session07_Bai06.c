#include <stdio.h>
#define MAX_LENGHT 1000

// Hàm gộp hai mảng đã sắp xếp
void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    //Tạo mảng tạm
    int l[n1], r[n2];
    // Sao chép dữ liệu vào mảng tạm
    for (int i = 0; i < n1; i++){
        l[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++){
        r[j] = arr[mid + 1 + j];
    }
    // Gộp hai mảng lại
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2){
        if (l[i] <= r[j]){
            arr[k++] = l[i++];
        }
        else{
            arr[k++] = r[j++];
        }
    }
    // Sao chép phần còn lại
    while (i < n1){
        arr[k++] = l[i++];
    }
    while (j < n2){
        arr[k++] = r[j++];
    }
}
// Hàm sắp xếp mảng theo giải thuật Merge Sort
void mergeSort(int arr[], int left, int right){
    if (left < right){
        int mid = (left + right) / 2;
        // Chia đôi mảng
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        // Gộp hai mảng con
        merge(arr, left, mid, right);
    }
}

// Hàm in mảng
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
    mergeSort(arr, 0, n - 1);
    // In ra mảng sau khi sắp xếp
    printf("after = ");
    printArray(arr, n);
    return 0;
}
