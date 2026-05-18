#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

// Global Variables
int counter = 0;
mutex mtx;

// 1. Basic Thread Function
void threadFunction() {
    cout << "Thread function running\n";
}

// 2. Increment Without Safety
void unsafeIncrement() {
    for (int i = 0; i < 5; i++){
        counter++;
        cout << "Unsafe Counter: " << counter << endl;
    }
}

// 3. Safe Version With Mutex
void safeIncrement() {
    for (int i = 0; i < 5; i++) {
        lock_guard<mutex> lock(mtx);
        counter++;
        cout << "Safe Counter: " << counter << endl;
    }
}

// Main Funtion
int main() {
    cout << "===== Basic Thread Demo =====" << endl;

    thread t(threadFunction);
    t.join();

    cout << "\n===== Unsafe Multithreading (Race Condition) =====" << endl;

    counter = 0;

    thread t1(unsafeIncrement);
    thread t2(unsafeIncrement);

    t1.join();
    t2.join();

    cout << "Final Unsafe Counter: " << counter << endl;

    cout << "\n===== Safe Multithreading (Mutex) =====" << endl;

    counter = 0;

    thread t3(safeIncrement);
    thread t4(safeIncrement);

    t3.join();
    t4.join();

    cout << "Final Safe Counter: " << counter << endl;

    cout << "\n===== End =====" << endl;

    return 0;
}