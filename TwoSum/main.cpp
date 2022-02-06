#include "twosum.h"
#include "twosum.cpp"
#include <iostream>
#include <vector>

using namespace std;
int main(){
    baseline::twosum obj;
    int a[] = {3, 2, 4};
    vector<int> numList, results(2);
    int x;
    for (x = 0; x < 3; x++)
        numList.push_back(a[x]);
    results = obj.twoSum(numList, 6);
    cout << "result is: [" << results[0] << ", " << results[1] << "]" << endl;
    return 0;
}