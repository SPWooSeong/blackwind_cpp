#include <iostream>

using namespace std;

void arrSwap(int** arr1, int** arr2){
    cout << *arr1 << endl;
    cout << *arr2 << endl;
    int* cache = *arr1;
    *arr1 = *arr2;
    *arr2 = cache;


    cout << *arr1 << endl;
    cout << *arr2 << endl;
}


int main() {
    int size1, size2;
    cout << "첫 번째 배열의 크기를 입력하세요: ";
    cin >> size1;
    cout << "두 번째 배열의 크기를 입력하세요: ";
    cin >> size2;
    int* arr1 = new int[size1];
    int* arr2 = new int[size2];

    cout << "첫 번째 배열의 요소를 입력하세요:\n";
    for (int i = 0; i < size1; ++i) {
        cin >> arr1[i];
    }
    
    cout << "두 번재 배열의 요소를 입력하세요:\n";
    for (int i = 0; i < size2; ++i) {
        cin >> arr2[i];
    }

    arrSwap(&arr1, &arr2);
    
    for (int i =0; i<size2; i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    for (int i =0; i<size1; i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;

    delete[] arr1;
    delete[] arr2;
    

    return 0;
}