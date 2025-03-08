#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

class Queue {
protected:
    int elements[MAX_SIZE];
    int frontIndex;
    int rearIndex;

public:
    Queue() : frontIndex(-1), rearIndex(-1) {}

    bool isEmpty() {
        return frontIndex == -1;
    }

    bool isFull() {
        if (rearIndex - frontIndex == 99) return 1;
        else return 0;
    }

    void enqueue(int value) {
        //IMPLEMENT HERE
        ++rearIndex;
        if (frontIndex==-1) ++frontIndex;
        elements[rearIndex] = value;
    }

    void dequeue() {
        //IMPLEMENT HERE
        elements[frontIndex] = 0;
        ++frontIndex;
    }

    int front() {
        if (!isEmpty()) {
            return elements[frontIndex];
        }
        return -1; // 예외 처리: Queue가 비어있을 때
    }
};

class Deque : public Queue {
public:
    void enqueueFront(int value) {
        //IMPLEMENT HERE
        --frontIndex;
        if (frontIndex == -1){
            frontIndex = 99;
        }
        elements[frontIndex] = value;
        
    }

    void dequeueRear() {
        //IMPLEMENT HERE
        elements[rearIndex] = 0;
        --rearIndex;
        if (rearIndex == -1) rearIndex=99;
      

    }

    int rear() {
        if (!isEmpty()) {
            return elements[rearIndex];
        }
        return -1;
    }
};

int main() {
    Queue myQueue;
    myQueue.enqueue(5);
    myQueue.enqueue(10);
    myQueue.enqueue(15);

    cout << "Front of Queue: " << myQueue.front() << endl;

    myQueue.dequeue();
    cout << "Front of Queue after dequeue: " << myQueue.front() << endl;

    Deque myDeque;
    myDeque.enqueue(20);
    myDeque.enqueueFront(25);
    myDeque.enqueueFront(30);

    cout << "Front of Deque: " << myDeque.front() << endl;
    cout << "Rear of Deque: " << myDeque.rear() << endl;

    myDeque.dequeue();
    myDeque.dequeueRear();

    cout << "Front of Deque after dequeue: " << myDeque.front() << endl;
    cout << "Rear of Deque after dequeue: " << myDeque.rear() << endl;

    return 0;
}