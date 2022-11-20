# Note

這題跟Meeting Room差不多，只是他改問我們如果會議時程表如`intervals`，則這間公司至少需要幾間會議室。

## My Solution

我的作法在一開始一樣先對`intervals`排序，接著使用一個變數`meetingsHavntEnd`紀錄還沒結束的會議，並使用`MaxOverlapped`紀錄同一時間下，最多有幾場會議重疊。演算法中要去遍歷所有會議，接著判斷該場會議與下一場會議重疊，就將該會議加入`meetingsHavntEnd`中，接著再去`meetingsHavntEnd`中看有多少會議是現在已經完成的，將已經結束的從`meetingsHavntEnd`移除；反之，如果有到現在還沒結束的，就將`currentOverlapped`加`1`，並在最後將`MaxOverlapped`設定為`max(MaxOverlapped, currentOverlapped)`。而我們要回傳的結果為需要幾場會議室，也就是`MaxOverlapped+1`。

這個演算法的時間複雜度為`O(meetingsHavntEnd.size()*n)`，最大為`O(n^2)`，之後再去看有沒有別人的方法可以加速。

```cpp
class Solution {
public:
    int minMeetingRooms(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), sortByFirst);
        vector<int> meetingsHavntEnd;
        int MaxOverlapped = 0;
        for (int i = 0; i < intervals.size()-1; i++) {
            if (intervals[i].end >= intervals[i+1].start) {
                meetingsHavntEnd.push_back(intervals[i].end);
                vector<int> temp;
                int currentOverlapped = 0;
                for (int j = 0; j < meetingsHavntEnd.size(); j++) {
                    if (meetingsHavntEnd[j] > intervals[i+1].start) {
                        currentOverlapped++;
                        temp.push_back(meetingsHavntEnd[j]);
                    }
                    else { 
                        currentOverlapped--;
                    }
                }
                meetingsHavntEnd = temp;
                MaxOverlapped = max(MaxOverlapped, currentOverlapped);
            }
        }
        return MaxOverlapped+1;
    }
private:
    struct {
        bool operator() (Interval a, Interval b) {
            return a.start < b.start;
        }
    }sortByFirst;
};
```
