#include <iostream>
using namespace std;
void make_tree() {

    for (int i=0;i<5;++i){
        auto blink = ' ';
        auto dot = '*';
        for(int j=(4-i); j>0;--j){
            cout <<blink;
        }
        for (int j = (2*i+1); j>0; --j){
            cout << dot;
        }
        for(int j=(4-i); j>=0;--j){
            cout <<blink;
        }
        cout<<"\n";

    }
		// IMPLEMENT HERE
}

int main(void) {
		make_tree();
}
