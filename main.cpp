#include "MyVector.hpp"
#include <iostream>
using namespace std;

int main()
{
    cout << "=== 測試 1: 基本功能 ===" << endl;
    MyVector<int> a;
    a.push_back(1);
    a.push_back(2);

    MyVector<int> b = a; // 呼叫 copy constructor
    MyVector<int> c;
    c = a;               // 呼叫 copy assignment operator

    a[0] = 999;

    cout << "b[0] = " << b[0] << "\n"; // 應該還是 1，不會變成 999
    cout << "c[0] = " << c[0] << "\n"; // 應該還是 1

    a.clear();
    cout << "a.getSize() = " << a.getSize() << "\n"; // 應該是 0

    cout << "\n=== 測試 2: 超容量測試 ===" << endl;
    MyVector<int> d;
    for (int i = 0; i < 20; ++i) {
        d.push_back(i);
    }
    cout << "d.getSize() = " << d.getSize() << "\n";       // 應該是 20
    cout << "d.getCapacity() = " << d.getCapacity() << "\n"; // 應該是 >= 20
    cout << "d[19] = " << d[19] << "\n";                  // 應該是 19

    cout << "\n=== 測試 3: 清空後新增 ===" << endl;
    d.clear();
    cout << "d.getSize() = " << d.getSize() << "\n";       // 應該是 0
    d.push_back(42);
    cout << "d[0] = " << d[0] << "\n";                    // 應該是 42

    cout << "\n=== 測試 4: 邊界條件 ===" << endl;
    try {
        cout << d[1] << endl; // 應該拋出異常
    } catch (const std::out_of_range& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    cout << "\n=== 測試完成 ===" << endl;
    return 0;
}