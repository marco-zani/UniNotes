#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;

int count(vector<int> S, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        count = count + S[i];
    }
    return count;
}

vector<int> getVec(int n) {
    vector<int> out = vector<int>();
    for (int i = 0; i < n; i++) {
        out.push_back(-1);
    }
    return out;
}

void printVec(vector<int> v) {
    int count = 1;
    for (int el : v) {
        if (el == 1) {
            cout << count << " ";
        }
        count++;
    }
    cout << endl;
}

void kssRec1(int n, int k, vector<int> S, int i) {
    int size = count(S, n);
    if (i == n and size == k) {
        printVec(S);
    } else if (i == n && size != k) {
        return;
    } else {
        for (int el : {0, 1}) {
            S[i] = el;
            kssRec1(n, k, S, i + 1);
        }
    }
}

void kssRec2(int n, int missing, vector<int> S, int i) {
    if (i == n and missing == 0) {
        printVec(S);
    } else if (i == n and missing != 0) {
        return;
    } else {
        for (int el : {0, 1}) {
            S[i] = el;
            kssRec2(n, missing - el, S, i + 1);
        }
    }
}

void kssRec3(int n, int missing, vector<int> S, int i) {
    if (missing == 0) {
        printVec(S);
    } else if (i == n or missing < 0) {
        return;
    } else {
        for (int el : {0, 1}) {
            S[i] = el;
            kssRec3(n, missing - el, S, i + 1);
        }
    }
}

void kssRec4(int n, int missing, vector<int> S, int i) {
    if (missing == 0) {
        printVec(S);
    } else if (i == n || missing < 0 || n - i < missing) {
        return;
    } else {
        for (int el : {0, 1}) {
            S[i] = el;
            kssRec4(n, missing - el, S, i + 1);
        }
    }
}

void kssRec(int n, int missing, vector<int> S, int i) {
    if (missing == 0) {
        printVec(S);
    } else if (i <= n and missing > 0 and n - i > missing) {
        for (int el : {0, 1}) {
            S[i] = el;
            kssRec4(n, missing - el, S, i + 1);
        }
    }
}

void queens(int n, vector<int> S, int i) {
    if (i > n) {
        for(int el : S){
            cout << el << " ";
        }
        cout << endl;
    } else {
        for (int j = 0; j < n; j++) {
            bool legal = true;
            for (int k = 0; k < i; k++) {
                if (S[k] == j or S[k] == j + i - k or S[k] == j - i + k) {
                    legal = false;
                }
            }
            if (legal) {
                S[i] = j;
                queens(n, S, i + 1);
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    int size = 20, amount = 5;

    queens(4, getVec(4), 0);
    return 0;
}
