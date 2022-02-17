Given the head of a linked list, remove the `n-th` node from the end of the list and return its head.

 

**Example 1:**

![圖片](https://user-images.githubusercontent.com/55487740/153827901-023440a4-bd19-451f-8fcb-355ae329f852.png)

```
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
```
**Example 2:**

```
Input: head = [1], n = 1
Output: []
```
**Example 3:**

```
Input: head = [1,2], n = 1
Output: [1]
```
**Constraints:**

- The number of nodes in the list is `sz`.
- `1 <= sz <= 30`
- `0 <= Node.val <= 100`
- `1 <= n <= sz`