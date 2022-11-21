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

## Min Heap Solution

[網路上別人的教學](https://www.youtube.com/watch?v=4MEkBvqE_2Q)使用Min Heap的概念來完成，由於Heap不論是存還是取都只要`O(logn)`的時間，因此看完所有會議也只需要`O(nlogn)`的時間，與排序所需要的時間相同，因此時間複雜度為`O(nlogn)`，比我的方法快。

下圖為他方法的概念。他的思路為：先將會議依照開始的時間排序，接著一場一場會議看，依序為其分配會議室，方法中使用Min Heap來記錄各個會議室「當前會議的結束時間」。由於使用Min Heap的方式來記錄當前各場會議的結束時間，因此根節點紀錄的就會是「最早結束的會議時間」。因此我們每次看到一場新的會議的時候，就先去看新的會議的開時間是否比根節點紀錄的「最早結束時間」還晚，如果成立的話，那這場會議就可以使用該場會議使用的會議室；反之代表該時段所有會議室都在使用狀態，因此需要使用額外的會議室（在Heap中加入新的節點）。

在我們遍歷完所有會議後，由於Min Heap存放著個時段中，各個會議的結束時間。而因為過程中會議室如果不夠的話，就要增加一個新的會議室，因此最後Min Heap中節點的數量即代表所需要的最少會議室數量。

<img width="1377" alt="截圖 2022-11-21 下午3 00 09" src="https://user-images.githubusercontent.com/55487740/202985368-37d18293-bf96-4bdb-bc09-5116b8471ab4.png">

```cpp
class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), sortByFirst);
        priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        minHeap.push(intervals[0].end);
        for (int i = 1; i < intervals.size(); i++) {
            if (minHeap.top() <= intervals[i].start) {
                minHeap.pop();
                minHeap.push(intervals[i].end);
            }
            else {
                minHeap.push(intervals[i].end);
            }
        }
        return minHeap.size();
    }
private:
    struct {
        bool operator() (Interval a, Interval b) {
            return a.start < b.start;
        }
    }sortByFirst;
};
```

