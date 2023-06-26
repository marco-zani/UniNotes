#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &arr, int p1, int p2) {
    int temp = arr[p1];
    arr[p1] = arr[p2];
    arr[p2] = temp;
}

int min(vector<int> arr, int offset) {
    int pos = offset;
    if (offset <= arr.size() - 1) {
        int min = arr[offset];
        for (int i = offset; i <= arr.size() - 1; i++) {
            if (arr[i] < min) {
                min = arr[i];
                pos = i;
            }
        }
    } else {
        pos = -1;
    }

    return pos;
}

void printArr(vector<int> arr) {
    for (int el : arr) {
        cout << el << ' ';
    }
    cout << endl;
}

void printArr(vector<int> arr, int begin, int end) {
    if (begin >= 0 && end <= arr.size() - 1) {
        for (int i = begin; i < end; i++) {
            cout << arr[i];
        }
    }
    cout << endl;
}

void selection_sort(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        int curr_min = min(arr, i);
        if (curr_min != -1) {
            swap(arr, i, curr_min);
        }
    }
}

void insertion_sort(vector<int> &arr) {
    for (int i = 1; i < arr.size(); i++) {
        int in_hand = arr[i];
        int ii = i;
        for (; ii > 0 && arr[ii - 1] > in_hand; ii--) {
            arr[ii] = arr[ii - 1];
        }
        arr[ii] = in_hand;
    }
}

void merge(vector<int> &arr, int begin, int mid, int end) {
    vector<int> temp;

    int left_index = begin, right_index = mid + 1;

    while (left_index <= mid && right_index <= end) {
        if (arr[left_index] <= arr[right_index]) {
            temp.push_back(arr[left_index]);
            left_index++;
        } else {
            temp.push_back(arr[right_index]);
            right_index++;
        }
    }

    if (left_index <= mid) {
        while (left_index <= mid) {
            temp.push_back(arr[left_index]);
            left_index++;
        }
    }

    for (int el : temp) {
        arr[begin] = el;
        begin++;
    }
}

void merge_sort(vector<int> &arr, int begin, int end) {
    if (begin < end) {
        int mid = (begin + end) / 2;

        merge_sort(arr, begin, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, begin, mid, end);
    }
}

void merge_sort(vector<int> &arr) { merge_sort(arr, 0, arr.size() - 1); }

int partition(vector<int> &arr, int begin, int end){
    int pivot = arr[begin],
    j = begin;
    for(int i = begin +1; i < end; i++){
        if(arr[i]<pivot){
            j++;
            swap(arr, i, j);
        }
    }
    arr[begin] = arr[j];
    arr[j]=pivot;
    return j;
}

void prvt_quickSort(vector<int> &arr, int begin, int end){
    if(begin<end){
        int pivot = partition(arr, begin, end);
        prvt_quickSort(arr,begin,pivot-1);
        prvt_quickSort(arr,pivot+1, end);
    }
}


void quickSort(vector<int> &arr){
    prvt_quickSort(arr,0,arr.size());
}


int main(int argc, char const *argv[]) {
    int input[] = {4, 1, 3, 5, 2};

    vector<int> arr;

    for (int el : input) {
        arr.push_back(el);
    }

    printArr(arr);

    quickSort(arr);

    printArr(arr);

    return 0;
}