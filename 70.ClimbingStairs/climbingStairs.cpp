#include "climbingStairs.h"
#include <vector>

using namespace std;

int Solution::climbStairs(int n){
    if (n > 2) {
        int i;
        int *lut = new int[n];
        lut[0] = 1;
        lut[1] = 2;
        for (i = 2; i < n; i++){
            lut[i] = lut[i-1] + lut[i-2];
        }
        return lut[n-1];
    }
    else return n;
}