#include <iostream>
using namespace std;

// Function to add two 2x2 matrices
void add(int A[2][2], int B[2][2], int C[2][2]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Function to subtract one 2x2 matrix from another
void subtract(int A[2][2], int B[2][2], int C[2][2]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Function to perform Strassen's matrix multiplication for 2x2 matrices
void strassen(int A[2][2], int B[2][2], int C[2][2]) {
    int M1, M2, M3, M4, M5, M6, M7;
    int A11 = A[0][0], A12 = A[0][1], A21 = A[1][0], A22 = A[1][1];
    int B11 = B[0][0], B12 = B[0][1], B21 = B[1][0], B22 = B[1][1];

    M1 = (A11 + A22) * (B11 + B22);
    M2 = (A21 + A22) * B11;
    M3 = A11 * (B12 - B22);
    M4 = A22 * (B21 - B11);
    M5 = (A11 + A12) * B22;
    M6 = (A21 - A11) * (B11 + B12);
    M7 = (A12 - A22) * (B21 + B22);

    C[0][0] = M1 + M4 - M5 + M7;
    C[0][1] = M3 + M5;
    C[1][0] = M2 + M4;
    C[1][1] = M1 - M2 + M3 + M6;
}

int main() {
    int A[2][2], B[2][2], C[2][2];

    cout << "Enter elements of matrix A (2x2):" << endl;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cin >> A[i][j];

    cout << "Enter elements of matrix B (2x2):" << endl;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cin >> B[i][j];

    strassen(A, B, C);

    cout << "Resulting matrix C (2x2) after Strassen's multiplication:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}
