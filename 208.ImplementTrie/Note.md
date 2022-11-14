# Note 

## My Solution

這題就是要我們實現一個字串的紀錄庫，之後他要可以讓使用者搜尋字串，或者是看裡面有沒有哪個字根開頭的字。

我自己的方法是建立一個二元樹，每個節點存一個字串，之後字串加入的時候去用Binary search tree的方式依序將字串加入（若新字串比當前節點的字串小，就存到左節點）
，之後搜尋的時候就是用二元搜尋的方式去。

其實我覺得如果用紅黑樹的方式來建立Tree會比較好，因為樹會比較平衡。目前這樣算起來，假如二元樹非常不平衡，時間複雜度就會變成是`O(n)`，而不是`O(logn)`。不過很神奇的是，這樣竟然沒有運算超時，還有超過`26.45%`的人。
<img width="1379" alt="截圖 2022-11-14 下午1 05 16" src="https://user-images.githubusercontent.com/55487740/201579789-bdf03403-41bf-4679-9457-9364eabcb790.png">

## LeetCode Solution

LeetCode官方使用一種叫做Trie的資料結構，這種資料結構會有一個起始的Node，其中每個Node會有`26`個用來指向代表`a`到`z`的指標，並且會有一個欄位來紀錄該資料庫中是否包含以該字元結尾的字串。例如下圖中的字串資料庫，目前就只有儲存`d`及`h`開頭的字串，然後圖片中使用紅色表示結束節點，因此可以知道裡面存放了`deal`、`dear`、`do`、`he`、`heat`以及`hen`。

![圖片](https://user-images.githubusercontent.com/55487740/201617573-26b22e00-16d9-4066-ad69-fda728574da3.png)

<img width="1379" alt="圖片" src="https://user-images.githubusercontent.com/55487740/201652866-b8b68356-8408-44b8-8bb7-970819624719.png">

```cpp
class node {
public:
    vector<node*> pointers;
    bool isEnd;
    node() {
        isEnd = false;
        pointers = vector<node*>(26, nullptr);
    }
};

class Trie {
public:
    Trie() {
        
    }
    
    void insert(string word) {
        node *cur = &rootNode;
        for (int i = 0; i < word.size(); i++) {
            char newChar = word[i];
            // If the target char is not exist in the trie
            if (cur->pointers[newChar-'a'] == nullptr) {
                cur->pointers[newChar-'a'] = new node();
            }
            cur = cur->pointers[newChar-'a'];
        }
        // If current is in the last position of word
        cur->isEnd = true;
    }
    
    bool search(string word) {
        node *cur = &rootNode;
        for (int i = 0; i < word.size(); i++) {
            char newChar = word[i];
            // If the target char is not exist in the trie
            if (cur->pointers[newChar-'a'] == nullptr) {
                return false;
            }
            cur = cur->pointers[newChar-'a'];
        }
        if(cur->isEnd == true) return true;
        else return false;
    }
    
    bool startsWith(string prefix) {
        node *cur = &rootNode;
        for (int i = 0; i < prefix.size(); i++) {
            char newChar = prefix[i];
            // If the target char is not exist in the trie
            if (cur->pointers[newChar-'a'] == nullptr) {
                return false;
            }
            cur = cur->pointers[newChar-'a'];
        }
        return true;
    }
private:
    node rootNode;
};
```
