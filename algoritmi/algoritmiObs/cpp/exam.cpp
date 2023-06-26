#include <ctime>
#include <iostream>

using namespace std;

int comb(int n, int poss) {
    if (n == 0) {
        return 1;
    }

    int count = 0;
    for (int i = 1; i <= min(n, poss); i++) {
        count += comb(n - i, poss);
    }
    return count;
}

int count(int n, int s) {
    int t[n + 1];
    t[0] = 1;
    for (int i = 1; i <= n; i++) {
        t[i] = 0;
        for (int k = 1; k <= min(i, s); k++) {
            t[i] += t[i - k];
        }
    }
    return t[n];
}

int binarySearch(int a[], int index, int n, int target) {
    if (n >= index) {
        int m = index + (n - index) / 2;

        if (a[m] == target) {
            return m;
        }
        if (a[m] > target) {
            return binarySearch(a, index, m, target);
        } else {
            return binarySearch(a, m + 1, n, target);
        }
    } else {
        return -1;
    }
}

int doubleIndex(int a[], int n, int lim) { 
    int maxC = 0, curr = 0, left = 0, right = 0; 

    while (right < n){
        if(a[right] - a[left] <= lim){
            curr++;
            maxC = max(maxC, curr);
            right++;
        } else {
            curr--;
            left++;
        }
    }
    return maxC;
        
}

int main(int argc, char const *argv[]) {
    int a[7] = {1, 3, 4, 4, 5, 7, 10};

    cout << doubleIndex(a, 6, 3) << endl;

    return 0;
}
