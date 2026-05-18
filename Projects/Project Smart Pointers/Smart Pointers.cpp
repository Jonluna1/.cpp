#include <iostream>
#include <memory>
using namespace std;

// 1. Unique Pointer
void uniquePointerDemo() {
    unique_ptr<int> ptr1 = make_unique<int>(10);

    cout << "Unique Pointer Value: " << *ptr1 << endl;

    // Transfer ownership
    unique_ptr<int> ptr2 = move(ptr1);

    if (!ptr1)
    cout << "ptr1 is now empty after move\n";

    cout << "ptr2 now owns value: " << *ptr2 << endl;
}

// 2. Shared Pointer
void sharedPointerDemo() {
    shared_ptr<int> ptr1 = make_shared<int>(20);

    cout << "Shared Pointer Value: " << *ptr1 << endl;
    cout << "Use Count: " << ptr1.use_count() << endl;

    shared_ptr<int> ptr2 = ptr1;

    cout << "After copying ptr1 to ptr2\n";
    cout << "Use Count: " << ptr1.use_count() << endl;
}

// 3. Weak Pointer
void weakPointerDemo() {
    shared_ptr<int> sp = make_shared<int>(30);
    weak_ptr<int> wp = sp;

    cout << "Weak Pointer created\n";
    cout << "Use Count (shared): " << sp.use_count() << endl;

    if (auto temp = wp.lock()) {
        cout << "Weak Pointer locked value: " << *temp << endl;
    }

    sp.reset();

    if (wp.expired()) {
        cout << "Weak Pointer expired after shared_ptr reset\n";
    }
}

// Main Function
int main() {
    cout << "===== Unique Pointer =====" << endl;
    uniquePointerDemo();

    cout << "\n===== Shared Pointer =====" << endl;
    sharedPointerDemo();

    cout << "\n===== Weak Pointer =====" << endl;
    weakPointerDemo();

    cout << "\n===== End =====" << endl;

    return 0;
}