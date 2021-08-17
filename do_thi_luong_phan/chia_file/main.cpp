#include <iostream>
#include "find_max_matching.h"

using namespace std;

int main() {
    loadGraph();
    init();
    solve();
    printResult();
    return 0;
}