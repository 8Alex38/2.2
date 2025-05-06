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
    Matrix();                                // ����������� �� ����������
    Matrix(int size);                        // ��������� �������
    Matrix(int r, int c);                    // ���������� �������
    Matrix(const Matrix& other);             // ����������� ���������
    ~Matrix();                               // ����������

    Matrix& operator=(const Matrix& other);  // ���������
    Matrix operator+(const Matrix& other);
    Matrix operator-(const Matrix& other);
    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix operator*(const Matrix& other);

    float* operator[](int index);            // ������ �� �����
    operator string() const;                 // ������������ � �����

    friend istream& operator>>(istream& in, Matrix& m);
    friend ostream& operator<<(ostream& out, const Matrix& m);
};
