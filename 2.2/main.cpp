#include "Matrix.h"
#include <iostream>
#include <iomanip>

#pragma pack(1)
class PackTest {
    Matrix m;
};
#pragma pack()

int main() {
    Matrix A(2, 2), B(2, 2);
    cout << "Enter matrix A (2x2):\n"; cin >> A;
    cout << "Enter matrix B (2x2):\n"; cin >> B;

    Matrix C = A + B;
    Matrix D = A * B;

    cout << "A + B =\n" << C;
    cout << "A * B =\n" << D;

    string str = string(C);
    cout << "Matrix C as string:\n" << str;

    cout << "Size of Matrix class: " << sizeof(Matrix) << " bytes\n";
    cout << "Size of class with #pragma pack(1): " << sizeof(PackTest) << " bytes\n";

    return 0;
}
