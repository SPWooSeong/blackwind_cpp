#include <iostream>
using namespace std;

int count;

void foo() {
    count++;
    if (count == 6) throw 6.0;  // Throw a double instead of an int
    foo();
    cout << count << endl;
}
int main(void) {
    count = 0;
    
    try {
        foo();
    } catch (double dd) {  // Catch the correct type
        cout << "end" << dd << endl;
    }
}
