#include "Matrix.h"
#include <iomanip>
#include <sstream>

void Matrix::allocate() {
    data = new float* [rows];
    for (int i = 0; i < rows; ++i)
        data[i] = new float[cols] {};
}

void Matrix::deallocate() {
    for (int i = 0; i < rows; ++i)
        delete[] data[i];
    delete[] data;
}

Matrix::Matrix() : rows(2), cols(2) {
    allocate();
}

Matrix::Matrix(int size) : rows(size), cols(size) {
    allocate();
}

Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    allocate();
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    allocate();
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            data[i][j] = other.data[i][j];
}

Matrix::~Matrix() {
    deallocate();
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        deallocate();
        rows = other.rows;
        cols = other.cols;
        allocate();
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                data[i][j] = other.data[i][j];
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix& other) {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] + other.data[i][j];
    return result;
}

Matrix Matrix::operator-(const Matrix& other) {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] - other.data[i][j];
    return result;
}

Matrix& Matrix::operator+=(const Matrix& other) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            data[i][j] += other.data[i][j];
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            data[i][j] -= other.data[i][j];
    return *this;
}

Matrix Matrix::operator*(const Matrix& other) {
    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < other.cols; ++j)
            for (int k = 0; k < cols; ++k)
                result.data[i][j] += data[i][k] * other.data[k][j];
    return result;
}

float* Matrix::operator[](int index) {
    return data[index];
}

Matrix::operator string() const {
    ostringstream out;
    out << fixed << setprecision(2);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            out << setw(8) << data[i][j];
        out << '\n';
    }
    return out.str();
}

istream& operator>>(istream& in, Matrix& m) {
    for (int i = 0; i < m.rows; ++i)
        for (int j = 0; j < m.cols; ++j)
            in >> m.data[i][j];
    return in;
}

ostream& operator<<(ostream& out, const Matrix& m) {
    out << string(m);  // використовуємо приведення типу до string
    return out;
}
