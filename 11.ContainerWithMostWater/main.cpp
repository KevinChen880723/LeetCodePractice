#include "container.cpp"
#include <vector>
#include <iostream>

using namespace std;

int main(){
    BestSolution::Solution solution;
    int height[] = {1,8,6,2,5,4,8,3,7};
    vector<int> input;
    int i;
    for (i = 0; i < 9; i++) 
        input.push_back(height[i]);
    int result = solution.maxArea(input);
    cout << "The max area of water is: " << result << endl;
    return 0;
}