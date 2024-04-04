#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isSafe(vector<int>& y, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (y[i] == col || abs(y[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

void solveNQueens(int n, int row, vector<int>& y) {
    if (row == n) { // All queens are placed successfully
        for (int i = 0; i < n; i++)
            cout << y[i] << " ";
        cout << endl;
        return;
    }

    // Try placing queen in each column of current row
    for (int col = 0; col < n; col++) {
        if (isSafe(y, row, col)) { //Check if queen can be placed
            y[row] = col; 
            solveNQueens(n, row + 1, y); //for next row
        }
    }
}

// handle N-Queens problem
void nQueens(int n) {
    vector<int> y(n, -1); // Vector to store column positions of queens
    solveNQueens(n, 0, y); // Start first row
}

int main() {
    int n;
    cin >> n;

    if (n <= 3) {
        return 0;
    } else {
        nQueens(n);
    }

    return 0;
}