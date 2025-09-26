#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
private:
    vector<int> q;    // array to hold queue elements
    int front, rear;  // pointers
    int count;        // current size
    int capacity;     // maximum size

public:
    // Constructor
    MyCircularQueue(int k) {
        capacity = k;
        q.resize(k);
        front = 0;
        rear = -1;
        count = 0;
    }

    // Insert element
    bool enQueue(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % capacity;
        q[rear] = value;
        count++;
        return true;
    }

    // Delete element
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        count--;
        return true;
    }

    // Get front element
    int Front() {
        if (isEmpty()) return -1;
        return q[front];
    }

    // Get rear element
    int Rear() {
        if (isEmpty()) return -1;
        return q[rear];
    }

    // Check if empty
    bool isEmpty() {
        return count == 0;
    }

    // Check if full
    bool isFull() {
        return count == capacity;
    }
};

int main() {
    MyCircularQueue q(3);  // Queue capacity = 3

    cout << boolalpha; // print true/false instead of 1/0
    cout << q.enQueue(1) << endl; // true
    cout << q.enQueue(2) << endl; // true
    cout << q.enQueue(3) << endl; // true
    cout << q.enQueue(4) << endl; // false (full)
    cout << q.Rear() << endl;     // 3
    cout << q.isFull() << endl;   // true
    cout << q.deQueue() << endl;  // true
    cout << q.enQueue(4) << endl; // true
    cout << q.Rear() << endl;     // 4

    return 0;
}