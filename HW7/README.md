# Assignment 7 作業說明
## HW1
## Design
使用 _adjacency lists_ 的資料型態來實作graph完成題目。

### Function Introduction

#### **_class graph_** :
* **_(constructor)_** : 初始化相應node數的node array。以及一個visited array來記錄nodes是否被造訪。
```c++
graph(int n)
```
* **_(destructor)_** : 將visited array以及整個adjacency lists的elements delete，歸還記憶體。
```c++
~graph()
```

* **_new_edge_** : 將相連的edge記錄在adjacency lists裡。 <br>
_Time complexity: O(n)_ (n為總nodes數)
```c++
void new_edge(int i,int j)
```
* **_dfn_** : traverse所有node。v為起始node，round是為了記錄visited，代表第幾次走訪。由於使用adjacency lists的資料結構，會造訪所有的node和兩次所有的edge。 <br>
_Time complexity: O(n+e)_ (e為總edges數)
```c++
void dfn(const int v,const int round)
```

* **_bipartite_** : 做兩次DFS(O(n+e))，藉由visited裡的elements判斷是否為bipartite graph。且為了判斷visited裡的elements(第一次DFS記錄為1，第二次DFS記錄為2)，會用兩次for loop掃過一次(O(2n))。若還有未造訪的node或者無第二次DFS，則輸出為False，反之為True。因此 **time complexity為 2*O(n+e)+O(2n)=O(n+e)** <br>
_Time complexity: O(n+e)_
```c++
bool bipartite()
```

* **_answer_** : 將兩個graphs的nodes依序輸出。 <br>
_Time complexity: O(n)_
```c++
void answer()const
```

### Flow
1. 依據node數初始化一個graph，並依序寫入edge。

2. 依據bipartite()判斷是否為bipartite graph，若為真，輸出兩個graphs的nodes。

## HW2
## Design
使用 _adjacency lists_ 的資料型態來實作graph完成題目。

### Function Introduction
#### **_class graph_** :

* **_(constructor)_** : 初始化相應node數的node array。以及dfn、low array來記錄nodes造訪順序和loop。

```c++
graph(int n)
```
* **_(destructor)_** : 將dfn、low array以及整個adjacency lists的elements delete，歸還記憶體。
```c++
~graph()
```
* **_new_edge_** : 將相連的edge記錄在adjacency lists裡。 <br>
_Time complexity: O(n)_ (n為總nodes數)
```c++
void new_edge(int i,int j)
```

* **_biconnected_** : biconnected的驅動程式。<br>
_Time complexity: O(n+e)_ (e為總edges數)
```c++
void biconnected()
```
* **_biconnected_** : 以DFS為基礎，藉由 _low_ 和 _dfn_ 幫助判斷graph有沒有biconnected component。_dfn_紀錄DFS走訪的順序，_low(n) = min{dfn(n),min{low(x)|x是n的兒子},min{dfn(x)|(n,x)為cross edge}}_，用來判斷是否有 _biconnected component_ 。若當前的node與它parent的low值不一樣，則判斷為bridge edge。因為一樣使用DFS traverse adjacency lists的所有nodes和2次所有edge。所以 **time complexity為 O(n+2e)=O(n+e)**<br>
_Time complexity: O(n+e)_
```c++
void biconnected(const int n,const int parent,int* num)
```

* **_result_** : 輸出bridge edge。<br>
_Time complexity: O(e)_
```c++
void result()const
```
### Flow
1. 依據node數初始化一個graph，並依序寫入edge。

2. 依據biconnected()來判斷是否有bridge edges，若為真，輸出所有的bridge edges。
