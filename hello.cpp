#include <iostream>

using namespace std;

// 두 정수의 비트 AND, OR, XOR 결과 출력
void bitwiseOperations(int num1, int num2) {

    int andResult = num1 & num2;
	int orResult = num1 | num2;
	int xorResult = num1 ^ num2;
	
	cout<< andResult  << endl;
	cout<< orResult << endl;
	cout<< xorResult << endl;

}

// 정수의 이진 표현 출력
void printBinaryRepresentation(int num) {
}

// 특정 비트 설정(1로 변경)
void setBit(int &num, int pos) {
	num = num | (1<<(pos-1));
}

// 특정 비트 클리어(0으로 변경)
void clearBit(int &num, int pos) {
	unsigned int revNum = (unsigned int)num;
	unsigned int revPos = (unsigned int)pos;

	
	revNum = revNum & (~(1<<(revPos-1)));
	num = (int)revNum;
}
// 특정 비트 토글(반전)
void toggleBit(int &num, int pos) {
	unsigned int revNum = (unsigned int)num;
	unsigned int revPos = (unsigned int)pos;
	revNum = revNum & (~(1<<(revPos-1)));
	revNum = revNum | (1<<(revPos-1));
	num = (int)revNum;		
}

int main() {
    int number1 = 25;
    int number2 = 42;
    int position = 3;

    bitwiseOperations(number1, number2);

    setBit(number2, position);
    cout << "After setting bit " << position << ": " << number2 << endl;

    clearBit(number2, position);
    cout << "After clearing bit " << position << ": " << number2 << endl;

    toggleBit(number2, position);
    cout << "After toggling bit " << position << ": " << number2 << endl;

    return 0;
}