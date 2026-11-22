
#include <iostream>
#include <memory>
using namespace std;

int main()
{
    // 1. Raw Pointer
    cout << "Raw Pointer Example:" << endl;

    int *p = new int(10);

    cout << "Value: " << *p << endl;

    delete p;

    // 2. Unique Pointer
    cout << "\nUnique Pointer Example:" << endl;

    unique_ptr<int> ptr1 = make_unique<int>(20);

    cout << "Value: " << *ptr1 << endl;

    // 3. Unique Pointer Array
    cout << "\nUnique Pointer Array:" << endl;

    unique_ptr<int[]> arr = make_unique<int[]>(3);

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }

    // 4. Shared Pointer
    cout << "\n\nShared Pointer Example:" << endl;

    shared_ptr<int> ptr2 = make_shared<int>(50);

    shared_ptr<int> ptr3 = ptr2;

    cout << "Value: " << *ptr2 << endl;

    cout << "Reference Count: " << ptr2.use_count() << endl;

    cout << "Both pointers share the same object." << endl;

    ptr3.reset();

    cout << "Reference Count After Reset: "
         << ptr2.use_count() << endl;

    cout << "\nProgram Completed Successfully!" << endl;

    return 0;
}
