#include <iostream>
using namespace std;

void countingSort(int arr[], int size) {
    //--------IMPLEMENT HERE-------------
    int max =0;
    for (int i =0; i<size; i++){
        if (arr[i]>max) max=arr[i];
    }
    int countingarr[max+1];
    for(int i =0; i < max+1; i++){
        countingarr[i] = 0;
    }
    for (int i =0; i<size; i++){
        countingarr[arr[i]] += 1;
    }
    int index = 0;
    for (int i = 0; i<max+1; i++){
        countingarr[i+1] += countingarr[i];
        while (index<countingarr[i])
        {
            arr[index] = i;
            ++index;
        }
        

    }
}

int main() {
    int n;
    cout << "배열 크기를 입력하세요: ";
    cin >> n;

    int* arr = new int[n];
    cout << "배열 요소를 입력하세요:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    countingSort(arr, n);

    cout << "정렬된 배열: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}