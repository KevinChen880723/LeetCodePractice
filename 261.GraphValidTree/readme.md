# Note 

這題給我們一個Undirected Graph中的節點數量`n`，以及Graph中的Edges `edges`，問我們這張圖是否是一個有效的Tree。

## My Solution

首先要知道有效的Tree必須符合以下兩個性質：
- 不存在Cycle
- 所有點都應該連接在一起（只有一個Connected Component)

### 判斷是否有Cycle

我使用跟[Course Schedule](https://github.com/KevinChen880723/LeetCodePractice/tree/master/207.CourseSchedule#%E8%8A%B1%E8%8A%B1%E9%86%AC%E7%9A%84%E8%A7%A3%E6%B3%95)那題類似的方式來看途中有沒有存在Cycle，唯一的不同處是那提的圖唯有向圖但這題是無向圖。為了避免我在Traverse子節點的時候，直接使用相同的Edge走回自己，我需要在呼叫遞迴程式之前，先將同一條鞭`graph[i][n]`設定為`0`，之後再將他調整回`1`。

### 判斷是否所有節點相連

另外，這題還需要判斷所有節點是否都連接在一起。針對這點，我的解法為：
- 一開始直接先判斷`edges.size()`是否至少跟`n-1`一樣多，如果沒有的話就一定沒辦法滿足此條件，因此直接回傳`false`。
- 之前[Course Schedule](https://github.com/KevinChen880723/LeetCodePractice/tree/master/207.CourseSchedule#%E8%8A%B1%E8%8A%B1%E9%86%AC%E7%9A%84%E8%A7%A3%E6%B3%95)需要分別從第`0`個節點到第`n-1`個節點開始遍歷，原因先修課的名單有可能有多個Connected Components，如果只從第一個節點開始Traverse的話，假如不是所有課都有關連性的話，那最後有些課就不會被遍歷到。不過這邊我們是要判斷一個圖是否包含多個Connected Components，因此可以只從第一個節點開始遍歷，過程中使用一個`unordered_set<int> connectedComponents`來紀錄這個Component包含的所有節點，當遞迴程式結束時，我們就找完第一個節點所在的那個Connected Component，這時只要再來看是否所有節點都存在這個Component中就好，如果沒有的話就代表不是所有節點都相連，因此回傳`false`。

我這個做法的時間複雜度應該是`O(n^2)`，因為我雖然是DFS，但我有一個截斷的機制。如果有個點已經走過了，就不再重新Traverse，因此最多只會走n^2個節點。

```cpp
class Solution {
public:
    bool validTree(int n, vector<vector<int>> &edges) {
        if (edges.size() < n-1) return false;
        vector<vector<int>> graph(n, vector<int>(n, 0));
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]][edges[i][1]] = 1;
            graph[edges[i][1]][edges[i][0]] = 1;
        }
        vector<int> visitStatus(n, 0);
        unordered_set<int> connectedComponents;
        return isValid(graph, visitStatus, connectedComponents);
    }

    bool isValid(vector<vector<int>> &graph, vector<int> &visitStatus, unordered_set<int> &connectedComponents) {
        connectedComponents.insert(0);
        if (!visitFromNodeN(graph, visitStatus, connectedComponents, 0) || connectedComponents.size() != graph.size()) return false;
        return true;
    }

    bool visitFromNodeN(vector<vector<int>> &graph, vector<int> &visitStatus, unordered_set<int> &connectedComponents, int n) {
        // visitStatus -> 0: initial; 1: visiting; 2: visited
        if (visitStatus[n] == 2) return true;
        else if (visitStatus[n] == 1) return false;
        visitStatus[n] = 1;
        for (int i = 0; i < graph.size(); i++) {
            // If there is an edge between node n and i
            if (graph[n][i] == 1) {
                connectedComponents.insert(i);
                // set graph[i][n] to 0 to prevent we traverse the same edge twice
                graph[i][n] = 0;
                if (!visitFromNodeN(graph, visitStatus, connectedComponents, i)) return 0;
                graph[i][n] = 1;
            }
        }
        visitStatus[n] = 2;
        return true;
    }
};
```

```
這題在LeetCode一樣要付費才能存取，因此我是在LintCode中測試的，有通過所有測試資料。
```
