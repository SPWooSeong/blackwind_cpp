#include <iostream>

using namespace std;

int Fib(int n) {
    if (n==1) return 1;
    if (n==2) return 1;
    int result = Fib(n-1) + Fib(n-2);
    return result;
	
}

int main() {
    int num;
    cout << "몇 번째 피보나치 수열을 구할까요? : ";
    cin >> num;
    cout<<Fib(num)<<endl;

}
