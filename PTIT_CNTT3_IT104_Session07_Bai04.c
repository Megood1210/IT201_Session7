#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Hàm hoán đổi 2 ký tự
void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm sắp xếp chuỗi từ a đến z
void sortString(char str[]){
    int len = strlen(str);
    // Chuyển các ký tự sang chữ thường
    for (int i = 0; i < len; i++){
        str[i] = tolower(str[i]);
    }
    // Sắp xếp các ký từ a đến z bằng sắp xếp chọn
    for (int i = 0; i < len - 1; i++){
        for (int j = 0; j < len - i - 1; j++){
            if (str[j] > str[j + 1]){
                swap(&str[j], &str[j + 1]);
            }
        }
    }
}

int main(){
    char str[1000];
    // Nhập chuỗi
    printf("str = ");
    fgets(str, 1000, stdin);
    // Xóa ký tự xuống dòng
    size_t len = strlen(str);
    if (len>0 && str[len - 1] == '\n'){
        str[len - 1] = '\0';
        len--;
    }
    // Kiểm tra chuỗi
    if (len == 0){
        printf("Chuoi khong hop le\n");
        return 0; // Cập nhật độ dài chuỗi
    }
    // In chuỗi trước khi sắp xếp
    printf("%s\n", str);
    // Gọi hàm sắp xếp
    sortString(str);
    // In chuỗi sau khi sắp xếp
    printf("%s\n", str);
    return 0;
}