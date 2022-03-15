# Note

這題給我們一個Linked List，他要我們把這個List的順序換成下面這樣：
![圖片](https://user-images.githubusercontent.com/55487740/158319014-fb98667d-25d2-4bc3-b42a-054e1cd0bd50.png)

## My O(n) Solution

我這題的作法可以達到`O(n)`的時間複雜度、`O(1)`的空間複雜度，方法為：
1. **將List拆成前後兩半**：為了用較快的速度完成這個功能，我使用Slow-fast Pointers，快的指標一次走兩步，慢的指標一次走一步，當快的指標走到最後面了，就代表慢指標已經走到中間，因此之後慢指標就可以作為後半部List的開頭指標。其中為了讓第一個List的結尾指向`nullptr`，我在每次移動慢指標之前，都會先用一個暫存的指標指向慢指標原本指向的節點，當慢指標抵達目標位置時，暫存指標就會指導第一個List的最後一個節點，因此可以再接著做`temp->next = nullptr`。
2. **將第二個List作反轉**：這部分就是之前學過的Reverse Linked List，過程中會使用額外兩個指標`next`、`prev`。使用`next`是為了讓我們在改變`head->next`後還能知道原本List中的下一個節點是誰，使用`prev`則是為了讓我們知道我們要指回去的前一個節點是誰。這個部分使用`while`回圈來實現，執行條件是`head`不是指向`nullptr`，由於條件是這樣，因此在結束回圈時，反轉後的開頭指標就不會是原先的`head`，而會是`prev`。
3. **將兩個Lists做穿插合併**

```cpp
class Solution {
public:
    void reorderList(ListNode* head) {
        // Use slow-fast pointers to separate the list into two lists (head2 stands for the slow pointer)
        if (!head->next) return;
        ListNode *fast = head;
        ListNode *head2 = head;
        ListNode *temp;
        while (fast) {
            if (!fast->next) break;
            temp = head2;
            head2 = head2->next;
            fast = fast->next->next;
        }
        temp->next = nullptr;
        
        // Reverse the second list
        ListNode *prev = nullptr, *next;
        while (head2) {
            next = head2->next;
            head2->next = prev;
            prev = head2;
            head2 = next;
        }
        head2 = prev;
        
        // Merge the two lists in the sequence set by this question.
        ListNode *p1 = head, *p2 = head2;
        while (1) {
            temp = p1->next;
            p1->next = p2;
            if (!temp) break;
            p1 = temp;
            temp = p2->next;
            p2->next = p1;
            p2 = temp;
        }
        /*
         * This is a better merging solution from the LeetCode discussion section.
         * for (p1 = head, p2 = head2; p1; ) {
         *     auto t = p1->next;
         *     p1 = p1->next = p2;
         *     p2 = t;
         * }
         */
    }
};
```

![](https://i.imgur.com/6c3rmFT.png)
