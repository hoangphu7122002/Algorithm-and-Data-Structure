#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 100;
const int logMAX = 7;
const int MAXINT = 240;

//O(n * n),O(1)
//dynamic programming RMQ
//M[i][j] is paragraph from i to j
void RMQ(int** &M,int* A,int n){
    for (int i = 0; i < n; i++){
        M[i][i] = i;
    }
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (A[M[i][j - 1]] < A[j]){
                M[i][j] = M[i][j - 1]; 
            }
            else {
                M[i][j] = j;
            }
        }
    }
}

//O(n log n), O(1)
//M[i][j] here is paragraph start by i and len is 2^j
void DP_two_pow(int M[MAX][logMAX],int* arr,int n){
    for (int i = 0; i < n; i++){
        M[i][0] = arr[i];
    }
    for (int j = 1; (1 << j) <= n; j++){
        for (int i = 1; i + (1 << j) <= n; i++){
            if (arr[M[i][j - 1]] <= arr[M[i + (1 << (j - 1))][j - 1]]){
                M[i][j] = M[i][j - 1];
            }
            else {
                M[i][j] = M[i + (1 << (j - 1))][j - 1];
            }
        }
    }
}

//segment tree
//M[i] perform for segment which is managed by node i
//we perform tree by one array M has 1,2 * 2 ^ (log(N) + 1)
//N is number element of array

void initialize(int node,int begin,int end,int M[MAXINT],int A[MAX],int n){
    if (begin == end){
        M[node] = begin;
    }
    else {
        int middle = begin + ((end - begin)>>1);
        initialize(2 * node,begin,middle,M,A,n);
        initialize(2 * node + 1,middle + 1,end,M,A,n);
        if (A[M[2 * node]] <= A[M[2 * node + 1]]){
            M[node] = M[2 * node];
        }
        else {
            M[node] = M[2 * node + 1];
        }
    }
}

//query
// O(N),O(logN)
int query(int node,int begin,int end,int M[MAXINT],int A[MAX],int i,int j){
    int p1; //part1
    int p2; //part2
    // case 2 segment don't intersection
    //i j is the current node; 
    if (i > end || j < begin){
        return -1; 
    }
    if (begin >= i && end <= j){
        return M[node];
    }
    p1 = query(2 * node,begin,(begin + end)/2,M,A,i,j);
    p2 = query(2 * node + 1,(begin + end)/2,end,M,A,i,j);
    if (p1 == -1){
        return (M[node] = p2);
    }
    if (p2 == -1){
        return (M[node] = p1);
    }
    if (A[p1] <= A[p2]){
        return (M[node] = p1);
    }
    return (M[node] = p2);
}



int main(){
    int n = 10;
    int* arr = new int[10]{2,3,4,1,6,7,8,9,1,7};
    int** M = new int*[10];
    for (int i = 0; i++ < 10;){
        M[i] = new int[4];
    }
   
    return 0;
}