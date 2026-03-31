#include <iostream>
using namespace std;

// Hàm tìm số lớn nhất trong mảng
int getMax(int arr[], int n) {
    int max = arr[0]; // giả sử phần tử đầu là lớn nhất

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) { // nếu tìm thấy số lớn hơn
            max = arr[i];   // cập nhật lại max
        }
    }

    return max; // trả về số lớn nhất
}

// Hàm sắp xếp theo từng chữ số (Counting Sort đơn giản)
void countingSort(int arr[], int n, int exp) {
    int output[100];     // mảng tạm để lưu kết quả
    int count[10] = {0}; // mảng đếm (0 → 9)

    // BƯỚC 1: Đếm số lần xuất hiện của từng chữ số
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10; // lấy chữ số (đơn vị, chục,...)
        count[digit]++;                  // tăng số đếm
    }

    // BƯỚC 2: Cộng dồn để biết vị trí
    for (int i = 1; i < 10; i++) {
        count[i] = count[i] + count[i - 1];
    }

    // BƯỚC 3: Xây dựng mảng output (duyệt từ phải qua trái)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;     // lấy chữ số
        output[count[digit] - 1] = arr[i];   // đặt vào đúng vị trí
        count[digit]--;                      // giảm count
    }

    // BƯỚC 4: Copy lại vào mảng gốc
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Hàm chính Radix Sort
void radixSort(int arr[], int n) {
    int max = getMax(arr, n); // tìm số lớn nhất

    // Lặp qua từng chữ số (1, 10, 100,...)
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp); // sắp xếp theo chữ số hiện tại
    }
}

// Hàm in mảng
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Hàm main
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = 8;

    cout << "Truoc khi sap xep: ";
    printArray(arr, n);

    radixSort(arr, n); // gọi hàm sắp xếp

    cout << "Sau khi sap xep: ";
    printArray(arr, n);

    return 0;
}