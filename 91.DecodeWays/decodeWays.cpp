#include "decodeWays.h"
#include <iostream>

int Solution::numDecodings(string s){
    int oneDigitAmount, amount, lastAmount, lastOneDigitAmount, i;
    if (s[0] == '0') return 0;
    lastOneDigitAmount = oneDigitAmount = (s[0] == '1' || s[0] == '2')? 1:0;
    lastAmount = amount = 1;
    for (i = 1; i < s.size(); i++){
        int last2Digits = stoi(s.substr(i-1, 2));
        if (s[i] == '0'){
            if (last2Digits == 10 || last2Digits == 20) oneDigitAmount = 0;
            else return 0;
            amount = lastOneDigitAmount;
        }
        else if (s[i] == '1' || s[i] == '2'){
            if (last2Digits >= 11 && last2Digits <= 26) amount += lastOneDigitAmount;
            oneDigitAmount = lastAmount;
        }
        else{
            if (last2Digits >= 11 && last2Digits <= 26) amount += lastOneDigitAmount;
            oneDigitAmount = 0;
        }
        lastOneDigitAmount = oneDigitAmount;
        lastAmount = amount;
    }
    return amount;
}