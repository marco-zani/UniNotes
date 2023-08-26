#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> getMatrix(int rows, int colums) {
    vector<vector<int>> out;
    for (int r = 0; r < rows; r++) {
        vector<int> temp;
        for (int c = 0; c < colums; c++) {
            temp.push_back(-1);
        }
        out.push_back(temp);
    }
    return out;
}

void printMatrix(vector<vector<int>> m, int rows, int columns) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            cout << m[r][c] << " ";
        }
        cout << endl;
    }
}

int knapsack_DP(int capacity, vector<int> weigths, vector<int> values) {
    int n = weigths.size();
    vector<vector<int>> DP = getMatrix(n, capacity);

    for (int i = 0; i < capacity; i++) {
        DP[0][i] = 0;
    }
    for (int i = 0; i < n; i++) {
        DP[i][0] = 0;
    }

    for (int i = 1; i < n; i++) {
        for (int c = 1; c < capacity; c++) {
            if (weigths[i] <= c) {
                DP[i][c] = max(
                    DP[i - 1]
                      [c] /*ho capienza ma conviene tenere il precedente*/,
                    DP[i - 1][c - weigths[i]] +
                        values[i] /*ho capienza e conviene prendere questo*/);
            } else {
                DP[i][c] =
                    DP[i - 1][c];  // non ho capienza, tengo quello precedente
            }
        }
    }

    printMatrix(DP, n, capacity);

    return DP[n - 1][capacity - 1];
}

int knapsack_Rec(vector<vector<int>> &mem, vector<int> weigths,
                 vector<int> values, int row, int column) {
    if (column < 0) {
        return -1;
    } else if (column == 0 or row == 0) {
        return 0;
    } else {
        if (mem[row][column] < 0) {
            int notTaken = knapsack_Rec(mem, weigths, values, row - 1, column);
            int taken = knapsack_Rec(mem, weigths, values, row - 1,
                                     column - weigths[row - 1]) +
                        values[row];
            mem[row][column] = max(taken, notTaken);
        }
        return mem[row][column];
    }
}

int knapsack_Mem(int capacity, vector<int> weigths, vector<int> values) {
    int n = weigths.size();
    vector<vector<int>> mem = getMatrix(n, capacity);

    int out = knapsack_Rec(mem, weigths, values, n - 1, capacity - 1);

    printMatrix(mem, n, capacity);

    return out;
}

int commonSubSequence(vector<char> string1, vector<char> string2, int index1,
                      int index2, vector<vector<int>> &DP) {
    if (index1 == -1 or index2 == -1) {
        return 0;
    } else if (DP[index1][index2] != -1) {
        return DP[index1][index2];
    } else if (string1[index1] == string2[index2]) {
        DP[index1][index2] =
            1 + commonSubSequence(string1, string2, index1 - 1, index2 - 1, DP);
        return DP[index1][index2];
    } else {
        DP[index1][index2] =
            max(commonSubSequence(string1, string2, index1, index2 - 1, DP),
                commonSubSequence(string1, string2, index1 - 1, index2, DP));
        return DP[index1][index2];
    }
}

void test_knapsackMem(){
        vector<int> w;
        w.push_back(0);
        w.push_back(4);
        w.push_back(2);
        w.push_back(3);
        w.push_back(4);

        vector<int> v;
        v.push_back(0);
        v.push_back(10);
        v.push_back(7);
        v.push_back(8);
        v.push_back(6);

        cout << knapsack_Mem(9 + 1, w, v) << endl;
}

void test_commonSubSequence(){
    vector<char> s1 = vector<char>();
    vector<char> s2 = vector<char>();

    s1.push_back('L');
    s1.push_back('T');
    s1.push_back('C');
    s1.push_back('S');
    s1.push_back('A');

    s2.push_back('B');
    s2.push_back('L');
    s2.push_back('T');
    s2.push_back('S');
    s2.push_back('C');

    auto m = getMatrix(5,5);

    cout << commonSubSequence(s1,s2,4,4,m) << endl;

    printMatrix(m,5,5);
}

int main(int argc, char const *argv[]) {
    test_commonSubSequence();

    return 0;
}
