#include <iostream>
#include <time.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <random>

using namespace std;

template <class T>
void swap(T& a,T& b){
    T x = a;
    a = b;
    b = x;
}

//--------------------------------------------------------------------------------------------------------

//i study from "Le Duy Thuc" Githubs

//generate random arr
void GenerateRandomData(int* arr,int n){
    srand(time(NULL));
    for (int i = 0; i < n; i++){
        arr[i] = rand() % n;
    }
}

void random_index(int* arr,int n){
    srand(time(NULL));
    int i = 2 * (rand() % n);
    while (i--){
        int left = rand() % n;
        int right = rand() % n;
        if (left == right)
            continue;
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }
}

//generate random n-distinct arr 
void GenerateRandomDataDistinct(int* arr,int n){
    srand(time(NULL));
    for (int i = 0; i < n; i++){
        arr[i] = i;
    }
    random_index(arr,n);
}

void GenerateDateSorted(int* arr,int n){
    for (int i = 0; i < n; i++){
        arr[i] = i;
    }
}

void GenerateDataInverse(int* arr,int n){
    for (int i = 0; i < n; i++){
        arr[i] = n - i - 1;
    }
}

void GenerateDataNearlySorted(int* arr,int n){
    for (int i = 0; i < n; i++){
        arr[i] = i;
    }
    srand(time(NULL));
    for (int i = 0; i < n/2; i++){
        int r1 = rand() % n;
        int r2 = rand() % n;
        int temp = arr[r1];
        arr[r1] = arr[r2];
        arr[r2] = temp;
    }
}

#define RANDOM_DATA 0
#define SORTED_DATA 1
#define REVERSED_DATA 2
#define NEARLY_SORTER_DATA 3
#define RANDOM_DISTINCT_DATA 4

void GenerateDate(int* arr,int n){
    srand(time(NULL));
    int typ = rand() % 5;
    switch(typ){
        case RANDOM_DATA:
            GenerateRandomData(arr,n);
            break;
        case SORTED_DATA:
            GenerateDateSorted(arr,n);
            break;
        case REVERSED_DATA:
            GenerateDataInverse(arr,n);
            break;
        case NEARLY_SORTER_DATA:
            GenerateDataNearlySorted(arr,n);
            break;
        default:
            GenerateRandomDataDistinct(arr,n);
    }
}

void printArray(int* arr,int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main(){
    int n = 20;
    int* arr = new int[n];
    GenerateDate(arr,n);
    printArray(arr,n);
    return 0;
}