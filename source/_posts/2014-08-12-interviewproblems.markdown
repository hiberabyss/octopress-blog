---
layout: post
title: "2014面试题"
date: 2014-08-12 14:51
comments: true
categories: Job Algorithm
---

根据同学面试经历总结，解答仅供参考。(by hiberabyss)

<!--more-->

##目录
- [算法相关](#s1)
- [海量数据问题](#s2)
- [操作系统相关](#s3)


<h3 id="s1">算法相关</h3>

#### 给定完全二叉树，求最后一层最右节点。要求时间复杂度小于`O(N)`（赵子汉——百度二面）
- 直接对二叉树进行层次遍历，用`last`变量记录每次访问的值，遍历完成直接返回`last`即可；时间复杂度为`O(N)`。
- 采用递归的思路：
    - 结束条件：如果根节点为叶子节点，即为所求，直接返回；
    - 如果左子树高度大于右子树，则最右节点在左子树；
    - 如果左子树高度等于右子树，则最右节点在右子树。

因为是完全二叉树，树的高度可以通过从根节点不断往左遍历求得，递归也可以很方便的用迭代的方法来实现，时间复杂度为`O(logN*logN)`。代码如下：

```c++
TreeNode *getRightMost(TreeNode *root) {
    if ( !root ) return root;
    
    while ( root->left || root->right ) {
        int lh = 0;
        TreeNode *tmp = root->left;
        while ( tmp ) lh++, tmp = tmp->left;

        int rh = 0;
        tmp = root->right;
        while ( tmp ) rh++, tmp = tmp->left;

        if ( lh == rh ) root = root->right;
        else root = root->left;
    }

    return root;
}
```

####给定一个链表内的两个指针，对指针间的节点做`reverse`（李强强——百度电面）
- 通过交换节点数据来实现翻转，时间复杂度为`O(N)`，空间复杂度为`O(N)`；代码如下：

```c++
struct ListNode {
    ListNode *next;
    int val;
}

void reverseNodes(ListNode *p1, ListNode *p2) {
    if ( !p1 || !p2 ) return;

    vector<ListNode*> nodes;
    for ( auto node = p1; ; node = node->next ) {
        nodes.push_back(node);
        if ( node == p2 ) break;
    }

    int i = 0;
    int j = nodes.size() - 1;
    while ( i<j ) swap(nodes[i++]->val, nodes[j--]->val);
}

```

- 按照要求翻转的是指针之间的节点（不包括p1和p2）的方式理解的话，可以通过更改链表指针在`O(N)`的时间复杂度和`O(1)`的空间复杂度内解决；（如果包含p1和p2，也可以先交换p1和p2的值，便可转化为这种情况），代码如下：

```c++
void reverseNodes(ListNode *p1, ListNode *p2) {
    if ( !p1 || !p1->next ) return;
    auto pre = p1->next;
    auto cur = pre->next;

    while ( cur != p2 && cur ) {
        auto tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }

    p1->next->next = cur;
    p1->next = pre;
}
```

####随机数相关算法
该类算法的思路在于先由给定随机数生成器生成一个序列，剔除一部分数，由剩下的序列来生成要求的结果。

- 给定随机数生成器`rand1p`，以概率`p`生成1，以概率`1-p`生成0，设计`rand1`，等概率生成0和1 ( 思路：两个`rand1p`之和为0或2的概率相等 )

```c++
int rand1() {
    int res = 0;

    do {
        res = 2*rand1p() + rand1p();
    } while ( res == 0 || res == 3 );

    return res - 1;
}
```   

- 由等概率01生成器`rand1`生成等概率的N个数

```c++
int randN(int N) {
    int res = 0;
    
    do {
        res = 0;
        for ( int i=0; ; i++ ) {
            res += (rand1() << i);
            if ( (1<<i) >= N ) break;
        }
    } while( res >= N );

    return res + 1;
}
```

- 给定`rand5`（等概率生成1-5），设计`rand7`（等概率生成1-7）（思路：由两个`rand5`组成一个2位的5进制数，则可等概率生成序列0-24，剔除最后4个数，则可得到一个有21个数的等概率序列）

```c++
int rand7() {
    int res = 0;
    do {
        res = 5 * (rand5() - 1) + rand5() - 1;
    } while ( res > 20 );

    return (res%7) + 1;
}
```

####找第K个数

####两个有序数组求中位数

####Inplace MergeSort

####非递归快排

<h2 id="s2">海量数据问题</h2>
这篇[博客](http://www.cnblogs.com/gw811/archive/2012/10/11/2719232.html)总结的挺好的。

####求N个整数（unsigned int）的中位数，N很大（强强——百度电面）
- 用外排序的方法排好序，返回第`N/2`个元素，时间复杂度`O(N*logN)`
- 类似桶排序的思想；对整数区间进行划分（例如划分为16个区间：0 ~ 2^28 - 1, ..., 15\*2^28 ~ 2^32 - 1），遍历所有整数，把属于同一个区间内的整数写到同一个文件中，并统计整数数量（N0, N1, ..., N7)，找到k，使得`sum{N0~Nk} >= N/2`且`sum{N0~Nk-1} < N/2`，则该问题转化为求第k个区间内的整数的第`N/2-sum{N0~Nk-1}`个数的问题。如果区间内的整数还是太多，则可以对区间再做进一步细分，重复上述过程。

<h3 id="s3">操作系统相关</h3>

####shell的实现原理（中海——百度一面）
- 读取输入，fork出新的进程，在子进程中调用`exec`运行相应程序。
