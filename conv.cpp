#include <iostream>
using namespace std;

int* conv_calc(int arr1[], int size1, int arr2[], int size2) {
    int* result = new int[size1 + size2 - 1];
    for (int n = 0; n < size1 + size2 - 1; n++) {
        result[n]=0;
        for (int i = 0; i<=n; i++){
            if (i>=size1) arr1[i] = 0;
            if ((n-i)>=size2) arr2[n-i] = 0;
            result[n] += arr1[i]*arr2[n-i];
        }
    }
		return result;
}
int main() {
    int x_array[] = {3, 1, 5, 7};
    int y_array[] = {4, 0, 2};
    int size1 = sizeof(x_array) / sizeof(x_array[0]);
    int size2 = sizeof(y_array) / sizeof(y_array[0]);
    int* result = conv_calc(x_array, size1, y_array, size2);
    for (int i = 0; i < size1 + size2 - 1; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    delete[] result;
    return 0;
}