#include <iostream>
#include <cstdlib>

using namespace std;

void swap(int &a,int &b){
    int c = a;
    a = b;
    b = c;
}

int index_partion(int* &arr,int begin,int end){
    int i = begin - 1;
    int partion = arr[end - 1];
    for (int j = begin; j < end; j++){
        if (arr[j] <= partion){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    return i;
}

void quick_sort(int* arr,int low,int high){
    if (low < high){
        int index = index_partion(arr,low,high);
        quick_sort(arr,low,index);
        quick_sort(arr,index + 1,high);   
    }
}

int main(){
    int* arr = new int[19]{1, 4, 2, 4, 2, 4, 1, 2, 4, 1, 2, 2, 2, 2, 4, 1, 4, 4, 4};
    quick_sort(arr,0,19);
    for (int i = 0; i < 19; i++){
        cout << arr[i] << ' ';
    }
    delete[] arr;
}