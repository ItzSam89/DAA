#include <iostream>
#include <vector>
using namespace std;

// Add two matrices
vector<vector<int>> addMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Subtract two matrices
vector<vector<int>> subtractMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Strassen's algorithm for matrix multiplication
vector<vector<int>> strassen(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();

    // Base case: If the matrix size is 1x1
    if (n == 1)
    {
        vector<vector<int>> C(1, vector<int>(1));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    // Divide matrices into quarters
    int mid = n / 2;
    vector<vector<int>> A11(mid, vector<int>(mid)), A12(mid, vector<int>(mid)), A21(mid, vector<int>(mid)), A22(mid, vector<int>(mid));
    vector<vector<int>> B11(mid, vector<int>(mid)), B12(mid, vector<int>(mid)), B21(mid, vector<int>(mid)), B22(mid, vector<int>(mid));

    for (int i = 0; i < mid; ++i)
    {
        for (int j = 0; j < mid; ++j)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    // Compute sub-matrices
    vector<vector<int>> P1 = strassen(A11, subtractMatrices(B12, B22));
    vector<vector<int>> P2 = strassen(addMatrices(A11, A12), B22);
    vector<vector<int>> P3 = strassen(addMatrices(A21, A22), B11);
    vector<vector<int>> P4 = strassen(A22, subtractMatrices(B21, B11));
    vector<vector<int>> P5 = strassen(addMatrices(A11, A22), addMatrices(B11, B22));
    vector<vector<int>> P6 = strassen(subtractMatrices(A12, A22), addMatrices(B21, B22));
    vector<vector<int>> P7 = strassen(subtractMatrices(A11, A21), addMatrices(B11, B12));

    // Compute result sub-matrices
    vector<vector<int>> C11 = addMatrices(subtractMatrices(addMatrices(P5, P4), P2), P6);
    vector<vector<int>> C12 = addMatrices(P1, P2);
    vector<vector<int>> C21 = addMatrices(P3, P4);
    vector<vector<int>> C22 = subtractMatrices(subtractMatrices(addMatrices(P5, P1), P3), P7);

    // Concatenate result sub-matrices
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < mid; ++i)
    {
        for (int j = 0; j < mid; ++j)
        {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }

    return C;
}

// Print matrix
void printMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> A = {{1, 2, 3, 4},
                             {5, 6, 7, 8},
                             {9, 10, 11, 12},
                             {13, 14, 15, 16}};

    vector<vector<int>> B = {{17, 18, 19, 20},
                             {21, 22, 23, 24},
                             {25, 26, 27, 28},
                             {29, 30, 31, 32}};

    if (A.size() != B.size() || A[0].size() != B[0].size() || A.size() != A[0].size())
    {
        cout << "Matrix dimensions are not compatible for multiplication." << endl;
        return 1;
    }

    vector<vector<int>> C = strassen(A, B);

    cout << "Matrix A:" << endl;
    printMatrix(A);
    cout << endl;

    cout << "Matrix B:" << endl;
    printMatrix(B);
    cout << endl;

    cout << "Resultant Matrix C:" << endl;
    printMatrix(C);

    return 0;
}
