//1 2 3 4 
//5 6 7 8

#pragma once
#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    float** data;

    void allocate();
    void deallocate();

public:
    Matrix();                                // конструктор за умовчанн€м
    Matrix(int size);                        // квадратна матриц€
    Matrix(int r, int c);                    // пр€мокутна матриц€
    Matrix(const Matrix& other);             // конструктор коп≥юванн€
    ~Matrix();                               // деструктор

    Matrix& operator=(const Matrix& other);  // присвоЇнн€
    Matrix operator+(const Matrix& other);
    Matrix operator-(const Matrix& other);
    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix operator*(const Matrix& other);

    float* operator[](int index);            // доступ до р€дк≥в
    operator string() const;                 // перетворенн€ у р€док

    friend istream& operator>>(istream& in, Matrix& m);
    friend ostream& operator<<(ostream& out, const Matrix& m);
};
