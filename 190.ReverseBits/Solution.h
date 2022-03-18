#include <cstdint>
#include <cmath>

using namespace std;

class Solution {
public:
    Solution(){
        int i;
        for (i = 0; i < 32; i++) {
            one_hot_ary[i] = pow(2, i);
        }
    }
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        int i;
        for (i = 0; i < 32; i++) {
            if (n >= one_hot_ary[31-i]) {
                n -= one_hot_ary[31-i];
                result += one_hot_ary[i];
            }
        }
        return result;
    }
private:
    uint32_t one_hot_ary[32];
};