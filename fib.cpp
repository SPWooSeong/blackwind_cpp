#include <iostream>

using namespace std;

int Fib(int n) {
	if (n==0)
		return 0;
		
	else if (n==1)
		return 1;
		


	int result=1,resultb1=1,resultb2=0;
	for (int j =2; j<n; j++){
		
		resultb2 = resultb1;
		resultb1 = result;
		
		
		result = resultb1 + resultb2;
	}
	return result;
}

int main() {
    int num = 30;
    int i = 1;

    for (i = 0; i < num; i++) {
        printf("%d ", Fib(i));
    }
}
