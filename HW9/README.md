# Assignment 9 作業說明
## HW1
## Design
Traverse AOE network，並找出critical path

### Function Introduction
* **_answer_** : 依格式輸出答案
```c++
void answer(head* graph,int n,int*ea,int*la,int a)
```

* **_forward_traverse_** 以堆疊的方式從AOE network的start vertex走訪到end vertex，並沿途計算earlist event time。
```c++
void forward_traverse(head* graph,int n,int* weight)
```
* **_backward_traverse_** : 以BFS的方式從AOE network的end vertex走訪到start vertex，並沿途計算latest event time、latest activity time、earlist event time。
```c++
void backward_traverse(head* graph,int n,int* ea,int* la,int* weight)
```

### Flow
1. 以adjacentcy list的資料型態記錄activities和events，並初始化相關要記錄的table。

2. 呼叫 _forward_traverse_ ，走到end vertex時即可算出整個network最快完成時間。由於會走訪所有edge和vertex，所以時間複雜度為O(n+e)。

3. 呼叫 _backward_traverse_ ，沿途計算並更新所有latest event time、latest activity time、earlist event time。和 _forward_traverse_ 一樣會走訪所有edge和vertex，所以時間複雜度為O(n+e)。

4. 輸出答案，並將slack=0的edge輸出為critical path。
