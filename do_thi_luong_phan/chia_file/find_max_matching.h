#ifndef FIND_MATCHING_H

#define FIND_MATCHING_H

//const
const int maxV = 100;
const int maxE = maxV * (maxV - 1)/2;
const int maxC = 101;

//variable
int V_X;
int V_Y;
bool a[maxV][maxV];
int matchX[maxV];
int matchY[maxV];
int trace[maxV];

//prototype
void loadGraph();
void init();
int findAgumentingPath();
void enlarge();
void solve();
void printResult();

#endif