#include <iostream>
#include <string>
using namespace std;

int calculator(int num1, string operation, int num2) {

    if (operation == "+"){
        return num1 + num2;
    }
    else if (operation == "/"){
        if (num2 == 0){
            return 88888888;
        }
        return num1 / num2;
    }
    else if (operation == "*"){
        return num1 * num2;
    }
    else if (operation == "-"){
        return num1 - num2;
    }
    else if (operation == "%"){
        if (num2 == 0){
            return 88888888;
        }
        return num1 % num2;
    }
    else{
        return 88888888;
    }

}


int main() {
    cout << "Your code: " << calculator(1, "+", 4) << endl;
    cout << "Answer: 5" << endl;
    cout << endl;
    cout << "Your code: " << calculator(2, "/", 0) << endl;
    cout << "Answer: 88888888" << endl;
    cout << endl;
    cout << "Your code: " << calculator(3, "*", 27) << endl;
    cout << "Answer: 81" << endl;
    cout << endl;
    cout << "Your code: " << calculator(9, "-", 12) << endl;
    cout << "Answer: -3" << endl;
    cout << endl;
    cout << "Your code: " << calculator(18, "/", 4) << endl;
    cout << "Answer: 4" << endl;
    cout << endl;
    cout << "Your code: " << calculator(18, "a", 4) << endl;
    cout << "Answer: 88888888" << endl;
    cout << endl;
    cout << "Your code: " << calculator(10, "%", 4) << endl;
    cout << "Answer: 2" << endl;
    cout << endl;
    return 0;
}