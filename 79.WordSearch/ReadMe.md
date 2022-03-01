# 79. Word Search

Given an `m x n` grid of characters `board` and a string `word`, return `true` if `word` exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

**Example 1:**

![圖片](https://user-images.githubusercontent.com/55487740/156104570-d3ecaa12-254f-495e-b4fa-819114ebafd2.png)

```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
```
**Example 2:**

![圖片](https://user-images.githubusercontent.com/55487740/156104580-fbaeb4ca-d340-4b94-9613-41aa355c68ff.png)

```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
```
**Example 3:**

![圖片](https://user-images.githubusercontent.com/55487740/156104590-5113bc26-ee94-4613-a876-c7ec86a6203d.png)

```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
```
 

**Constraints:**

- `m == board.length`
- `n = board[i].length`
- `1 <= m, n <= 6`
- `1 <= word.length <= 15`
- `board` and `word` consists of only lowercase and uppercase English letters.

 

**Follow up**: Could you use search pruning to make your solution faster with a larger `board`?
