# Note

這題給我們一個使用Adjacency List表示的Graph，題目問希望我們複製出一個一模一樣的Graph並回傳回去，要注意的是不能直接回傳一個記憶體位置相同的圖（使用另一個指標指向舊的圖）。

## Solution

由於題目給我們的是指向圖中某一個節點的指標，我們需要透過該指標指向的節點的`neighbors`來得知有哪些節點跟這個節點相鄰。每看到一個新的節點時都要創建一個數值及鄰居都完全一樣的節點，而因為`neighbors`裡面存放的是指標，因此還要確保不同的節點能指到記憶體位置相同的相同數值節點。為了達到這個目的，我使用一個Hash map來記錄某個數值與其對應的節點的記憶體位址，之後在遍歷所有鄰居的過程中，先去檢查存放某個數值的節點是否已經存在，如果不存在的話就遞迴呼叫相同函數來建立新的節點；反之，如果該節點已經存在，就使用Hash map來找出對應到該數值的節點的記憶體位址。

```cpp
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<int, Node*> dict;
        return cloneGraph(node, dict);
    }
    
    Node* cloneGraph(Node *node, unordered_map<int, Node*> &dict) {
        Node *newNode = new Node(node->val);
        dict[node->val] = newNode;
        int i;
        for (Node *n : node->neighbors) {
            if (!dict.count(n->val)) dict[n->val] = cloneGraph (n, dict);
            newNode->neighbors.push_back(dict[n->val]);
        }
        return newNode;
    }
};
```

![](https://i.imgur.com/1FP9S0c.png)
