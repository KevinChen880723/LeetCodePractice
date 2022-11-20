# Note

這題給我們一個二維Vector `intervals`，裡面的每個元素代表一段開會時間，一段時間使用大小為`2`的Vector表示開始時間與結束時間。題目問我們，如果有個人的開會時間如`intervals`，則他有辦法參加完所有會議嗎？

## My Baseline Solution

一開始看到這題只想到比較笨的方法，時間複雜度為`O(n*I)`，其中`I`代表最長的Interval大小。

我的作法是：使用Hash set紀錄每個區間中的所有時間，並且在看到新的時間時，判斷該時間是否已經出現在Hash set中，如果有的話就代表會議時辰有所重疊，直接回傳`false`；反之，如果可以順利地將所有時間加入Set中，就代表時間不重疊，因此回傳`true`。

```cpp
class Solution {
public: 
    bool canAttendMeetings(vector<vector<int> > intervals) {
        unordered_set<int> meetingTimes;
        for (int i = 0; i < intervals.size(); i++) {
            for (int j = intervals[i][0]; j <= intervals[i][1]; j++) {
                if (meetingTimes.count(j)) return false;
                meetingTimes.insert(j);
            }
        }
        return true;
    }
};
```

```
這題要LeetCode Premium，我沒辦法去用他的網站測，不知道結果如何，不過可以通過他給的兩筆測資。
```

## Sorting Solution

網路上看到別人先用`O(nlogn)`的時間將`intervals`按照會議的開始時間排序，之後只要`O(n)`的時間跑過`intervals`，看比較早的會議的結束時間是否會比下一個會議的開始時間還晚，如果比較晚的話就回傳`false`。

我覺得他這樣做是因為我那個方法的時間複雜度取決於`interval`的大小，如果每個會議都很長的話，那這個`O(nlogn)`的演算法一定比較好。

```cpp
class Solution {
public: 
    bool canAttendMeetings(vector<vector<int> > intervals) {
        sort(intervals.begin(), intervals.end(), sortByFirst);
        for (int i = 0; i < intervals.size()-1; i++) {
            if (intervals[i][1] >= intervals[i+1][0]) return false;
        }
        return true;
    }
private:
    struct {
        bool operator() (vector<int> a, vector<int> b) {
            return a[0] < b[0];
        }
    }sortByFirst;
};
