#include <iostream>
using namespace std;

int main() {
    int year;
    cout << "연도를 입력하세요 : ";
    cin >> year;
    if ((year%4)==0){
        if ((year%100)==0){
            if ((year%400)==0){
                cout << "윤년" << endl;
                return 0;
            }
            cout<< "윤년아님" << endl;
            return 0;
        }
        cout << "윤년" << endl;
        return 0;
        
    }
    else{
        cout<< "윤년아님" << endl;
        return 0;
    }
}