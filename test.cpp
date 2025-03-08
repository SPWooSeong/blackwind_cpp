#include <iostream>
#include <list>

int main() {
    std::list<int> mylist = {1, 2, 3, 4, 5};

    for (std::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it) {
        if (*it == 0) {
            std::cout << "Iterator points to an element with value 0" << std::endl;
        } else {
            std::cout << "Iterator points to an element with value other than 0" << std::endl;
        }
    }

    return 0;
}
