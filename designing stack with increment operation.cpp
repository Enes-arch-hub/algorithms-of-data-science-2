#include <bits/stdc++.h>
using namespace std;

class CustomStack {
private:
    int maxSize;                // maximum allowed size
    vector<int> stack;          // stack storage
    vector<int> inc;            // to track increments

public:
    // Constructor
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        stack.reserve(maxSize);
        inc.resize(maxSize, 0);
    }

    // Push operation
    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);
        }
    }

    // Pop operation
    int pop() {
        if (stack.empty()) return -1;

        int idx = stack.size() - 1;
        int res = stack[idx] + inc[idx];

        if (idx > 0) {
            inc[idx - 1] += inc[idx]; // propagate increment
        }
        inc[idx] = 0;
        stack.pop_back();

        return res;
    }

    // Increment bottom k elements
    void increment(int k, int val) {
        int n = min(k, (int)stack.size());
        if (n > 0) {
            inc[n - 1] += val; // add increment marker
        }
    }
};

int main() {
    CustomStack st(5);   // Stack of max size 5

    st.push(1);          // Stack = [1]
    st.push(2);          // Stack = [1, 2]
    st.push(3);          // Stack = [1, 2, 3]

    st.increment(2, 100); // Stack = [101, 102, 3]

    cout << st.pop() << endl; // 3
    cout << st.pop() << endl; // 102
    cout << st.pop() << endl; // 101
    cout << st.pop() << endl; // -1 (empty)

    return 0;
}