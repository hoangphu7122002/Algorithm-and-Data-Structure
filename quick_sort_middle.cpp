#include <iostream>

using namespace std;

//prototype
void print(int*,int);

void swap(int& a,int& b){
    int c = a;
    a = b;
    b = c;
}

//one loop for quick sort;
void quickSortOneLoop(int* arr,int left,int right){
    if (left == right){
        return;
    }
    int middle = left + (right - left)/2;
    int pivot = arr[middle];
    int l = left;
    int r = right;
    while (l <= r){
        while (l < middle && arr[l] <= pivot) l++;
        while (r > middle && arr[r] >= pivot) r--;
        if (l <= r){
            swap(arr[l],arr[r]);
            l++;
            r--;
        }
    }
    if (l < right){
        quickSortOneLoop(arr,l,right);
    }
    if (left < r){
        quickSortOneLoop(arr,left,r);
    }
}

void quickSort(int* arr,int n){
    quickSortOneLoop(arr,0,n - 1);
}

void print(int* arr,int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
}

int main() {
    int arr[] = {10,10,10,10,10,10,10};
    quickSort(arr,7);
    print(arr,7);
    return 0;
}