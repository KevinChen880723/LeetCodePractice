#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

namespace hashmap{
    class Solution {
    public:
        bool hasCycle(ListNode *head) {
            unordered_set<ListNode*> set;
            while (head) {
                if (set.count(head)) return true;
                set.insert(head);
                head = head->next;
            }
            return false;
        }
    };
}

namespace twoPointer{
    class Solution {
    public:
        bool hasCycle(ListNode *head) {
            ListNode *slow = head;
            ListNode *fast = head;
            while (fast) {
                // 本來一直在想邊界條件要怎麼設定，但其實這個很簡單，while裡面直接設定fast
                // 之後為了避免指標在移動的時候出錯，因此先檢查fast->next有沒有東西，如果不是nullptr下一步就可以正常移動。
                if (!fast->next) return false;
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast) return true;
            }
            return false;
        }
    };
}