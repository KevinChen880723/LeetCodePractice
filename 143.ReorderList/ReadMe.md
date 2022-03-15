# 143. Reorder List

You are given the head of a singly linked-list. The list can be represented as:
```
L0 → L1 → … → Ln - 1 → Ln
```
Reorder the list to be on the following form:
```
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
```
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

**Example 1:**

![圖片](https://user-images.githubusercontent.com/55487740/158320403-b617bd78-d1e5-4c67-a967-71ac971d98e1.png)

```
Input: head = [1,2,3,4]
Output: [1,4,2,3]
```
**Example 2:**

![圖片](https://user-images.githubusercontent.com/55487740/158320391-f253bb17-d4c9-478c-a6c5-8c7450c481f7.png)

```
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
```
 

**Constraints:**

- The number of nodes in the list is in the range `[1, 5 * 10^4]`.
- `1 <= Node.val <= 1000`

