#include <iostream>
using namespace std;

int N = 7;

void swap(int& a, int& b){
    a = a + b;
    b = a - b;
    a = a - b;
}

void Max_heap(int* A, int i, int heap_size = 7){
    int max;
    int left = i * 2;
    int right = i * 2  + 1;
    if (i > heap_size/2)
        return;
    if (left <= heap_size && A[i] < A[left]){
        max = left;
    }
    else {
        max = i;
    }
    if (right <= heap_size && A[max] < A[right]){
        max = right;
    }
    if (i != max){
        swap(A[i],A[max]);
    }
    Max_heap(A,max,heap_size);
}

void run_max_heap(int* A){
    //O(n)
    for (int i = N/2; i >= 1; i--){
        Max_heap(A,i);
    }
}

void Max_heap_sort(int* A){
    int heap_size = N;
    run_max_heap(A);
    for (int i = N; i >= 2; i--){
        swap(A[i],A[1]);
        Max_heap(A,1,--heap_size);
    }
}

//priority queue
void insert_element(int* A,int val){
    N = N + 1;
    int i = N;
    A[i] = val;
    while (i > 1 && A[i] > A[i/2]){
        swap(A[i],A[i/2]);
        i = i/2;
    }
}

int pop(int* A){
    if (N == 0){
        cout << "empty" << endl;
    }
    int max = A[1];
    A[1] = A[N];
    N--;
    Max_heap(A,1,N);
    return max;
}

int main() {
    int A[8] = {-1,1,4,3,7,8,9,10};
    run_max_heap(A);
    for (int i = 1; i <= N; i++){
        cout << A[i] << ' ';
    }
    return 0;
}