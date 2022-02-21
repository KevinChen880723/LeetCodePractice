#include "anagrams.cpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    bruteforce::Solution solution;
    string ary[] = {"eat","tea","tan","ate","nat","bat"};
    vector<string> input;
    vector<vector<string> > result;
    int i;
    for (i = 0; i < 6; i++){
        input.push_back(ary[i]);
    }
    result = solution.groupAnagrams(input);
    return 0;
}