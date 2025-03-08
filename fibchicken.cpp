#include <iostream>

using namespace std;
int people;
int sum = 0;

int Fib(int n) {
    if (n<=0) return 0;
    if (n==1) return 1;
    if (n==2) return 1;
    int result = Fib(n-1) + Fib(n-2);
    return result;
	
}

int Fib_chicken(int peo){
    if (people ==0){
        return sum;
    }
    
    int i=1;
    while (true) {
        if (Fib(i) ==peo){
            if (i==1){
                return sum +1;
            }
            people = people - Fib(i);
            sum = sum + Fib(i-1);
            return Fib_chicken(people);


        }
        if (Fib(i) >peo){
            people = people - Fib(i-1);
            sum = sum + Fib(i-2);
            return Fib_chicken(people);
        }
        ++i;
    }
}



int main() {
    cout << "치킨을 몇명이 먹나요 : ";
    cin >> people;
    
    cout<<Fib_chicken(people)<<endl;

}
