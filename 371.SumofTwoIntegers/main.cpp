#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

namespace mySolution {
    class Solution {
    public:
        int getSum(int a, int b) {
            bool cin = 0;
            int bit_parser = 1, final_result = 0;
            for (int i = 31; i >= 0; i--) {
                bool b_bit = b & bit_parser, a_bit = a & bit_parser;
                bool bit_result = a_bit ^ b_bit ^ cin;
                final_result = (bit_result == 1)? final_result | bit_parser: final_result;
                cin = (cin & b_bit) | (cin & a_bit) | (a_bit & b_bit);
                bit_parser = (unsigned int)bit_parser << 1;
            }
            return final_result;
        }
    };
};

namespace betterSolution {
    class Solution {
    public:
        int getSum(int a, int b) {
            while(b != 0){
                int temp = (unsigned int)(a&b)<<1;
                a = a ^ b;
                b = temp;
            }
            return a;
        }
    };
};