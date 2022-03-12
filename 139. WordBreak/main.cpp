#include "solution.h"
#include <iostream>

using namespace std;

int main(){
    Solution solution;
    string ary[] = {"cats","dog","sand","and","cat"};
    vector<string> input;
    int i;
    for (i = 0; i < 5; i++) input.push_back(ary[i]);
    bool result = solution.wordBreak("catsandog", input);
    cout << result << endl;
    return 0;
}