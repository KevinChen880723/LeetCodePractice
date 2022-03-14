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
            if (!head || !head->next) return false;
            while (fast->next->next) {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast) return true;
                if (!fast || !fast->next) break;
            }
            return false;
        }
    };
}