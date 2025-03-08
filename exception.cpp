#include <iostream>
using namespace std;


int main(void) {
    int num = 5;
    
    try {
        for (int i=0; i<15; ++i) {
            for (int j=0; j<15; ++j) {
                if (num == j) throw num;
            }
        }
    }
    catch (int num) {
        cout <<"number : "<<num<<endl;
    }
    
}
