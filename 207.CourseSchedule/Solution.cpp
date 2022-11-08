#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 題目會給我們很多堂課，以及各堂課所需的先修課程名單。假如有一堂課的先修課程包含自己，則該課程不能修，也就沒辦法修完所有課程。因此我們的任務就是要去看有沒有存在一堂課，一直遞迴過去的先修課程包含自己的，有的話就回傳False，反之回傳True。
        // 創建Graph，初始化為全False
        vector<vector<bool>> prerequisitesGraph(numCourses, vector<bool>(numCourses, 0)); 
        int i, j;
        for (i = 0; i < prerequisites.size(); i++) {
            prerequisitesGraph[prerequisites[i][0]][prerequisites[i][1]] = 1;
        }
        // 去Traverse這個Graph，直到每一個Vertex都找完他們需要哪些先修課，建立一個遞迴先修課的Graph。這個過程會花費O(n^2)的時間。
        // 用一個長度為n的list來記錄有沒有從各個點去Traverse周圍的所有鄰居，如果有的話就設為True。假如之後看到有一個點有被Traverse過了，那就直接回傳他一共有哪些鄰居，回到上一層之後再把這些鄰居也都設定為True（代表需要先修該門課）。完成後再把上一層的這個點在list中對應到的位置設定為True，因為已經Traverse過了。
        vector<bool> traversed(numCourses, 0);
        for (i = 0; i < numCourses; i++) {
            unordered_set<int> recursivePrerequisites;
            traverseNeighborsFromNode_i(numCourses, prerequisitesGraph, traversed, recursivePrerequisites, i);
        }
        // Check whether the course itself is in its prerequisity list
        for (i = 0; i < numCourses; i++) {
            if (prerequisitesGraph[i][i] == 1) return 0;
        }
        return 1;
    }
    
    void traverseNeighborsFromNode_i(int numCourses, vector<vector<bool>> &prerequisitesGraph, vector<bool> &traversed, unordered_set<int> &allRecursivePrerequisites, int startNode) {
        int i;
        if (traversed[startNode] == 1) {
            for (i = 0; i < numCourses; i++) {
                if (prerequisitesGraph[startNode][i] == 1) {
                    allRecursivePrerequisites.insert(i);
                }
            }
            return;
        }
        traversed[startNode] = 1;
        for (i = 0; i < numCourses; i++) {
            unordered_set<int> recursivePrerequisites;
            // If i is the prerequisity course of i
            if (prerequisitesGraph[startNode][i] == 1) {
                traverseNeighborsFromNode_i(numCourses, prerequisitesGraph, traversed, recursivePrerequisites, i);
                allRecursivePrerequisites.merge(recursivePrerequisites);
            }
        }
        for (auto element: allRecursivePrerequisites) {
            prerequisitesGraph[startNode][element] = 1;
        }
    }
};