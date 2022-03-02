# 100. Same Tree

Given the roots of two binary trees `p` and `q`, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

**Example 1:**

![圖片](https://user-images.githubusercontent.com/55487740/156305012-859b2950-ec8c-47af-a196-ac7d4d523fdb.png)

```
Input: p = [1,2,3], q = [1,2,3]
Output: true
```
**Example 2:**

![圖片](https://user-images.githubusercontent.com/55487740/156305022-8c0e16e6-8c96-4b25-96f1-b9974e69ce94.png)

```
Input: p = [1,2], q = [1,null,2]
Output: false
```
**Example 3:**

![圖片](https://user-images.githubusercontent.com/55487740/156305039-dc8ae2bf-8aaf-42a2-9d55-458928a85df8.png)

```
Input: p = [1,2,1], q = [1,1,2]
Output: false
```
 

**Constraints:**

- The number of nodes in both trees is in the range `[0, 100]`.
- `-10^4 <= Node.val <= 10^4`

